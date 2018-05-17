/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:12:58 by amnishen          #+#    #+#             */
/*   Updated: 2018/04/18 18:13:01 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_p(t_printf *pf)
{
	long	x;
	char	*buf;
	char	*arg_line;

	x = va_arg(pf->arg, unsigned long);
	va_end(pf->arg);
	buf = (char*)ft_memalloc(sizeof(char) * 12);
	buf[0] = '0';
	buf[1] = 'x';
	arg_line = ft_itoa_base(x, 16);
	buf = ft_strcat(buf, arg_line);
	ft_putstr(buf);
	pf->bytes_printed = ft_strlen(buf);
	free(buf);
	free(arg_line);
}
