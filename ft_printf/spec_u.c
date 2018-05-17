/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:40:08 by amnishen          #+#    #+#             */
/*   Updated: 2018/04/11 17:40:11 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char		*uhh_size_arg_line(t_printf *pf)
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

static	char		*uh_size_arg_line(t_printf *pf)
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

static	char		*unone_size_arg_line(t_printf *pf)
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

static	char		*ul_size_arg_line(t_printf *pf)
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

void				spec_u(t_printf *pf)
{
	char			*arg_line;

	if (pf->size_spec == 'h')
		arg_line = uh_size_arg_line(pf);
	else if (pf->size_spec == 'H')
		arg_line = uhh_size_arg_line(pf);
	else if (pf->size_spec == 'z')
		arg_line = uz_size_arg_line(pf);
	else if (pf->size_spec == 'l' || pf->size_spec == 'L' ||
				pf->type == 'U' || pf->size_spec == 'j')
		arg_line = ul_size_arg_line(pf);
	else
		arg_line = unone_size_arg_line(pf);
	make_width_line(pf, arg_line);
	if (arg_line)
		free(arg_line);
}
