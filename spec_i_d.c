/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 23:52:34 by amnishen          #+#    #+#             */
/*   Updated: 2018/03/14 23:52:37 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*dh_size_arg_line(t_printf *pf, short x)
{
	char		*arg_line;
	char		*buf;
	int			line_size;

	if (x == 0 && pf->precision == 0)
		return (NULL);
	manege_prefix_d(pf, x);
	if (x < 0)
	{
		buf = ft_itoa_base(((long)x * -1), 10);
		pf->prefix = '-';
	}
	else
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

static	char	*dl_size_arg_line(t_printf *pf, long x)
{
	char		*arg_line;
	char		*buf;
	int			line_size;

	if (x == 0 && pf->precision == 0)
		return (NULL);
	manege_prefix_d(pf, x);
	if (x < 0)
	{
		buf = ft_itoa_base(x * -1, 10);
		pf->prefix = '-';
	}
	else
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

static	char	*dnone_size_arg_line(t_printf *pf, int x)
{
	char		*arg_line;
	char		*buf;
	int			line_size;

	if (x == 0 && pf->precision == 0)
		return (NULL);
	manege_prefix_d(pf, x);
	if (x < 0)
	{
		buf = ft_itoa_base((long)x * -1, 10);
		pf->prefix = '-';
	}
	else
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

static	char	*dhh_size_arg_line(t_printf *pf, char x)
{
	char		*arg_line;
	char		*buf;
	int			line_size;

	if (x == 0 && pf->precision == 0)
		return (NULL);
	manege_prefix_d(pf, x);
	if (x < 0)
	{
		buf = ft_itoa_base((long)x * -1, 10);
		pf->prefix = '-';
	}
	else
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

void			spec_i_d(t_printf *pf)
{
	char		*arg_line;

	if (pf->size_spec == 'h')
		arg_line = dh_size_arg_line(pf, (short)va_arg(pf->arg, int));
	else if (pf->size_spec == 'H')
		arg_line = dhh_size_arg_line(pf, (char)va_arg(pf->arg, int));
	else if (pf->size_spec == 'z')
		arg_line = dz_size_arg_line(pf, va_arg(pf->arg, size_t));
	else if (pf->size_spec == 'l' || pf->size_spec == 'L' ||
				pf->type == 'D' || pf->size_spec == 'j')
		arg_line = dl_size_arg_line(pf, va_arg(pf->arg, long));
	else
		arg_line = dnone_size_arg_line(pf, va_arg(pf->arg, int));
	make_prefix_line(pf);
	make_width_line(pf, arg_line);
	if (arg_line)
		free(arg_line);
	va_end(pf->arg);
}
