/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:19:43 by amnishen          #+#    #+#             */
/*   Updated: 2018/05/16 17:19:44 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			manege_prefix_d(t_printf *pf, long x)
{
	if (pf->precision != -1)
		pf->zero_flag = -1;
	if (pf->space_flag == 1)
		pf->prefix = ' ';
	if (pf->plus_flag == 1 && x >= 0)
		pf->prefix = '+';
}

int				is_printf_spec(char c)
{
	if (c != 's' && c != 'S' && c != 'p' && c != 'd' &&
		c != 'D' && c != 'i' && c != 'o' &&
		c != 'O' && c != 'u' && c != 'U' && c != 'x' &&
		c != 'X' && c != 'c' && c != 'C' && c != '%')
		return (0);
	else
		return (1);
}

int				is_printf_flag(char c)
{
	if (c != '-' && c != '+' && c != ' ' && c != '#' && c != '0')
		return (0);
	else
		return (1);
}

int				is_size_spec(char c)
{
	if (c != 'l' && c != 'h' && c != 'z' && c != 'j')
		return (0);
	else
		return (1);
}

void			make_flag_str(char *format, int *a, t_printf *pf)
{
	size_t		n;
	int			i;
	char		*str;

	n = *a;
	i = 0;
	pf->flag_str = (char*)ft_memalloc(sizeof(char) * 6);
	str = pf->flag_str;
	while (is_printf_flag(format[n]) == 1 && i < 6)
		str[i++] = format[n++];
	*a = n;
	pf->flag_str = str;
}
