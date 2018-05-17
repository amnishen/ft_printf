/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 09:40:15 by amnishen          #+#    #+#             */
/*   Updated: 2018/03/19 17:18:34 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	flag_width(t_printf *pf, int *a, char *format, va_list *arg)
{
	int			n;

	n = *a;
	if (is_printf_flag(format[n]) == 1)
		make_flag_str(format, &n, pf);
	if (ft_isdigit(format[n]) == 1)
	{
		pf->width = ft_atoi(&format[n]);
		if (pf->width < 0)
			pf->width *= -1;
		while (ft_isdigit(format[n]) == 1)
			n++;
	}
	else if (format[n] == '*')
	{
		pf->width = va_arg(*arg, int);
		n++;
	}
	else
		pf->width = 1;
	*a = n;
}

static	void	make_precision(t_printf *pf, int *a, char *format, va_list *arg)
{
	int			n;

	n = *a;
	if (format[n] == '.')
	{
		if (ft_isdigit(format[++n]) == 1)
		{
			pf->precision = ft_atoi(&format[n]);
			while (ft_isdigit(format[n]) == 1)
				n++;
		}
		else if (format[n] == '*')
		{
			pf->precision = va_arg(*arg, int);
			n++;
		}
		else
			pf->precision = 0;
	}
	else
		pf->precision = -1;
	*a = n;
}

static	void	make_size_spec(t_printf *pf, int *a, char *format)
{
	int			n;

	n = *a;
	if (is_size_spec(format[n]) == 1)
	{
		pf->size_spec = format[n++];
		if (format[n] == pf->size_spec)
		{
			pf->size_spec = pf->size_spec - 32;
			n++;
		}
	}
	else
		pf->size_spec = 0;
	*a = n;
}

int				make_arg(char *format, va_list *arg, int *a)
{
	int			n;
	t_printf	*pf;
	int			skip_arg;

	n = *a + 1;
	pf = (t_printf*)malloc(sizeof(t_printf));
	pf->flag_str = NULL;
	flag_width(pf, &n, format, arg);
	make_precision(pf, &n, format, arg);
	make_size_spec(pf, &n, format);
	while (format[n] && is_printf_spec(format[n]) == 0)
		n++;
	pf->type = format[n];
	if (pf->type != '%')
	{
		va_copy(pf->arg, *arg);
		skip_arg = va_arg(*arg, int);
	}
	make_struct_great_again(pf);
	skip_arg = pf->bytes_printed;
	*a = n;
	free(pf);
	return (skip_arg);
}

int				i_hate_this_project(char *format, va_list *ap)
{
	int			n;
	int			res;

	res = 0;
	n = 0;
	while (format[n])
	{
		if (format[n] == '%')
			res = res + make_arg(format, ap, &n);
		else
		{
			ft_putchar(format[n]);
			res++;
		}
		n++;
	}
	return (res);
}
