/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_file1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:18:33 by amnishen          #+#    #+#             */
/*   Updated: 2018/05/16 17:18:35 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*dz_size_arg_line(t_printf *pf, size_t x)
{
	char		*arg_line;
	char		*buf;
	int			line_size;

	if (x == 0 && pf->precision == 0)
		return (NULL);
	if (pf->precision != -1)
		pf->zero_flag = -1;
	if (pf->space_flag == 1)
		pf->prefix = ' ';
	if (pf->plus_flag == 1)
		pf->prefix = '+';
	buf = ft_itoa_base(x, 10);
	if ((long)ft_strlen(buf) >= pf->precision)
		line_size = (long)ft_strlen(buf);
	else
		line_size = pf->precision;
	arg_line = (char*)ft_memalloc(sizeof(char) * line_size);
	if ((long)ft_strlen(buf) < pf->precision)
		ft_memset(arg_line, '0', line_size - (long)ft_strlen(buf));
	arg_line = ft_strncat(arg_line, buf, (long)ft_strlen(buf));
	free(buf);
	return (arg_line);
}

char			*oz_size_arg_line(t_printf *pf)
{
	size_t		x;
	char		*arg_line;
	char		*buf;
	int			line_size;

	x = va_arg(pf->arg, size_t);
	va_end(pf->arg);
	if (x == 0 && pf->precision == 0 && pf->sharp_flag != 1)
		return (NULL);
	if (pf->precision != -1)
		pf->zero_flag = 0;
	if (pf->sharp_flag == 1 && x != 0)
		pf->prefix = '0';
	buf = ft_itoa_base(x, 8);
	if ((long)ft_strlen(buf) >= pf->precision)
		line_size = (long)ft_strlen(buf);
	else
		line_size = pf->precision;
	arg_line = (char*)ft_memalloc(sizeof(char) * line_size);
	if ((long)ft_strlen(buf) < pf->precision)
		ft_memset(arg_line, '0', line_size - (long)ft_strlen(buf));
	arg_line = ft_strncat(arg_line, buf, (long)ft_strlen(buf));
	free(buf);
	return (arg_line);
}

char			*uz_size_arg_line(t_printf *pf)
{
	size_t		x;
	char		*arg_line;
	char		*buf;
	int			line_size;

	x = va_arg(pf->arg, size_t);
	va_end(pf->arg);
	if (x == 0 && pf->precision == 0)
		return (NULL);
	if (pf->precision != -1)
		pf->zero_flag = 0;
	buf = ft_itoa_base(x, 10);
	if ((long)ft_strlen(buf) >= pf->precision)
		line_size = (long)ft_strlen(buf);
	else
		line_size = pf->precision;
	arg_line = (char*)ft_memalloc(sizeof(char) * line_size);
	if ((long)ft_strlen(buf) < pf->precision)
		ft_memset(arg_line, '0', line_size - (long)ft_strlen(buf));
	arg_line = ft_strncat(arg_line, buf, (long)ft_strlen(buf));
	ft_strdel(&buf);
	return (arg_line);
}

char			*xz_size_arg_line(t_printf *pf)
{
	size_t		x;
	char		*arg_line;
	char		*buf;
	int			line_size;

	x = va_arg(pf->arg, size_t);
	va_end(pf->arg);
	if (x == 0 && pf->precision == 0)
		return (NULL);
	if (pf->precision != -1)
		pf->zero_flag = 0;
	buf = ft_itoa_base(x, 16);
	if ((long)ft_strlen(buf) >= pf->precision)
		line_size = (long)ft_strlen(buf);
	else
		line_size = pf->precision;
	arg_line = (char*)ft_memalloc(sizeof(char) * line_size);
	if (pf->sharp_flag == 1 && x != 0)
		pf->prefix = '#';
	if ((long)ft_strlen(buf) < pf->precision)
		ft_memset(arg_line, '0', line_size - (long)ft_strlen(buf));
	arg_line = ft_strncat(arg_line, buf, (long)ft_strlen(buf));
	free(buf);
	return (arg_line);
}

void			manage_flags(t_printf *pf)
{
	char		*str;
	int			n;

	n = 0;
	str = pf->flag_str;
	while (str[n])
	{
		if (str[n] == '-')
			pf->minus_flag = 1;
		if (str[n] == '+')
			pf->plus_flag = 1;
		if (str[n] == ' ')
			pf->space_flag = 1;
		if (str[n] == '#')
			pf->sharp_flag = 1;
		if (str[n++] == '0')
			pf->zero_flag = 1;
	}
	if (pf->minus_flag == 1)
		pf->zero_flag = -1;
	if (pf->flag_str)
		free(pf->flag_str);
}
