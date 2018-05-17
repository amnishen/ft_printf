/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c_C.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:16:27 by amnishen          #+#    #+#             */
/*   Updated: 2018/04/18 17:16:28 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		spec_percent(t_printf *pf)
{
	char	*arg_line;

	arg_line = (char*)ft_memalloc(sizeof(char) * 2);
	arg_line[0] = '%';
	make_width_line(pf, arg_line);
	free(arg_line);
}

void		spec_c(t_printf *pf)
{
	char	c;

	c = (char)va_arg(pf->arg, int);
	va_end(pf->arg);
	if (pf->width > 1)
		pf->width_str = (char*)ft_memalloc(sizeof(char) * pf->width);
	if (pf->zero_flag == 1)
		ft_memset(pf->width_str, '0', pf->width - 1);
	else
		ft_memset(pf->width_str, ' ', pf->width - 1);
	if (pf->minus_flag == 1)
	{
		ft_putchar(c);
		ft_putstr(pf->width_str);
	}
	else
	{
		ft_putstr(pf->width_str);
		ft_putchar(c);
	}
	if (pf->width_str != NULL)
		free(pf->width_str);
	pf->bytes_printed = pf->width;
}

void		spec_c_lc(t_printf *pf)
{
	int		uni;
	int		size;

	uni = va_arg(pf->arg, int);
	va_end(pf->arg);
	size = wchar_size(uni);
	make_width_string(pf, size);
	if (pf->minus_flag == 1 && pf->width_str != NULL)
	{
		do_some_unicode_pls(uni);
		ft_putstr(pf->width_str);
	}
	else if (pf->minus_flag != 1 && pf->width_str != NULL)
	{
		ft_putstr(pf->width_str);
		do_some_unicode_pls(uni);
	}
	else
		do_some_unicode_pls(uni);
	pf->bytes_printed = size + ft_strlen(pf->width_str);
	if (pf->width_str)
		free(pf->width_str);
}

int			wchar_size(int uni)
{
	char	*bits_line;
	int		res;

	res = 0;
	bits_line = ft_itoa_base(uni, 2);
	if (ft_strlen(bits_line) <= 7)
		res = 1;
	else if (ft_strlen(bits_line) <= 11 && ft_strlen(bits_line) > 7)
		res = 2;
	else if (ft_strlen(bits_line) <= 16 && ft_strlen(bits_line) > 11)
		res = 3;
	else
		res = 4;
	free(bits_line);
	return (res);
}

void		make_width_string(t_printf *pf, int size)
{
	int		line_size;

	if (size < pf->width)
		line_size = pf->width - size;
	else
	{
		pf->width_str = NULL;
		return ;
	}
	pf->width_str = (char*)ft_memalloc(sizeof(char) * line_size);
	ft_memset(pf->width_str, ' ', line_size - 1);
	if (pf->zero_flag == 1)
		ft_memset(pf->width_str, '0', line_size - 1);
}
