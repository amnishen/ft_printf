/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:48:37 by amnishen          #+#    #+#             */
/*   Updated: 2018/04/19 14:48:38 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	uni_str_write(int mylti_len, wchar_t *mylti_str)
{
	int			n;

	n = 0;
	while (mylti_str[n] && mylti_len != 0)
	{
		do_some_unicode_pls((int)mylti_str[n]);
		mylti_len = mylti_len - wchar_size((int)mylti_str[n]);
		n++;
	}
}

static	void	go_for_null(t_printf *pf)
{
	char		*arg;
	char		*arg_line;

	arg = ft_strdup("(null)");
	if (pf->precision < (long)ft_strlen(arg) && pf->precision != -1)
	{
		arg_line = (char*)ft_memalloc(sizeof(char) * pf->precision + 1);
		arg_line = ft_strncpy(arg_line, arg, pf->precision);
	}
	else
		arg_line = ft_strdup(arg);
	free(arg);
	make_width_line(pf, arg_line);
	free(arg_line);
}

void			spec_s(t_printf *pf)
{
	char		*arg;
	char		*arg_line;

	arg = va_arg(pf->arg, char *);
	va_end(pf->arg);
	if (arg == NULL)
		return (go_for_null(pf));
	if (pf->precision < (long)ft_strlen(arg) && pf->precision != -1)
	{
		arg_line = (char*)ft_memalloc(sizeof(char) * pf->precision + 1);
		arg_line = ft_strncpy(arg_line, arg, pf->precision);
	}
	else
		arg_line = ft_strdup(arg);
	make_width_line(pf, arg_line);
	free(arg_line);
}

static	void	print_mylti_str(t_printf *pf, wchar_t *mylti_str, int mylti_len)
{
	make_width_string(pf, mylti_len);
	if (pf->minus_flag == 1 && pf->width_str != NULL)
	{
		uni_str_write(mylti_len, mylti_str);
		ft_putstr(pf->width_str);
	}
	else if (pf->minus_flag != 1 && pf->width_str != NULL)
	{
		ft_putstr(pf->width_str);
		uni_str_write(mylti_len, mylti_str);
	}
	else
		uni_str_write(mylti_len, mylti_str);
	pf->bytes_printed = mylti_len + ft_strlen(pf->width_str);
	if (pf->width_str)
		free(pf->width_str);
}

void			spec_s_ls(t_printf *pf)
{
	wchar_t		*mylti_str;
	int			n;
	int			mylti_len;

	mylti_str = va_arg(pf->arg, wchar_t *);
	va_end(pf->arg);
	if (mylti_str == NULL)
		return (go_for_null(pf));
	n = 0;
	mylti_len = 0;
	while (mylti_str[n])
	{
		if (pf->precision != -1)
		{
			if (mylti_len + wchar_size((int)mylti_str[n]) < pf->precision)
				mylti_len = mylti_len + wchar_size((int)mylti_str[n]);
			else
				break ;
		}
		else
			mylti_len = mylti_len + wchar_size((int)mylti_str[n]);
		n++;
	}
	print_mylti_str(pf, mylti_str, mylti_len);
}
