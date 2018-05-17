/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_x_X.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:49:52 by amnishen          #+#    #+#             */
/*   Updated: 2018/04/16 17:49:55 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char		*xnone_size_arg_line(t_printf *pf)
{
	unsigned int	x;
	char			*arg_line;
	char			*buf;
	int				line_size;

	x = va_arg(pf->arg, unsigned int);
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

static	char		*xhh_size_arg_line(t_printf *pf)
{
	unsigned char	x;
	char			*arg_line;
	char			*buf;
	int				line_size;

	x = (unsigned char)va_arg(pf->arg, unsigned int);
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

static	char		*xh_size_arg_line(t_printf *pf)
{
	unsigned short	x;
	char			*arg_line;
	char			*buf;
	int				line_size;

	x = (unsigned short)va_arg(pf->arg, unsigned int);
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

static	char		*xl_size_arg_line(t_printf *pf)
{
	unsigned long	x;
	char			*arg_line;
	char			*buf;
	int				line_size;

	x = va_arg(pf->arg, unsigned long);
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

void				spec_x(t_printf *pf)
{
	char			*arg_line;

	if (pf->size_spec == 'h')
		arg_line = xh_size_arg_line(pf);
	else if (pf->size_spec == 'H')
		arg_line = xhh_size_arg_line(pf);
	else if (pf->size_spec == 'z')
		arg_line = xz_size_arg_line(pf);
	else if (pf->size_spec == 'l' || pf->size_spec == 'L' ||
				pf->size_spec == 'j')
		arg_line = xl_size_arg_line(pf);
	else
		arg_line = xnone_size_arg_line(pf);
	if (pf->type == 'X')
		arg_line = ft_toupper_str(arg_line);
	make_prefix_line(pf);
	make_width_line(pf, arg_line);
	if (arg_line)
		free(arg_line);
}
