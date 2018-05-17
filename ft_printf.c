/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 09:21:27 by amnishen          #+#    #+#             */
/*   Updated: 2018/02/09 09:21:30 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list		ap;
	int			res;

	va_start(ap, format);
	res = i_hate_this_project(format, &ap);
	va_end(ap);
	return (res);
}
