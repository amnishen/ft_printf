/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct_great_again.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 23:37:11 by amnishen          #+#    #+#             */
/*   Updated: 2018/03/14 23:37:17 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_struct_great_again(t_printf *pf)
{
	pf->minus_flag = -1;
	pf->plus_flag = -1;
	pf->space_flag = -1;
	pf->sharp_flag = -1;
	pf->zero_flag = -1;
	if (pf->flag_str)
		manage_flags(pf);
	pf->prefix = -1;
	pf->prefix_size = 0;
	pf->prefix_line = NULL;
	pf->width_str = NULL;
	go_for_spec(pf);
}

void	go_for_spec(t_printf *pf)
{
	if (pf->type == 'i' || pf->type == 'd' || pf->type == 'D')
		spec_i_d(pf);
	if (pf->type == 'o' || pf->type == 'O')
		spec_o(pf);
	if (pf->type == 'p')
		spec_p(pf);
	if (pf->type == 'u' || pf->type == 'U')
		spec_u(pf);
	if (pf->type == '%')
		spec_percent(pf);
	if (pf->type == 'x' || pf->type == 'X')
		spec_x(pf);
	if (pf->type == 'c' && pf->size_spec != 'l')
		spec_c(pf);
	if ((pf->type == 'c' && pf->size_spec == 'l') || pf->type == 'C')
		spec_c_lc(pf);
	if ((pf->type == 's' && pf->size_spec == 'l') || pf->type == 'S')
		spec_s_ls(pf);
	if ((pf->type == 's' && pf->size_spec != 'l'))
		spec_s(pf);
}

void	make_prefix_line(t_printf *pf)
{
	char	*buf;

	if (pf->prefix != -1)
		pf->prefix_size = 1;
	if (pf->prefix == '#')
		pf->prefix_size = 2;
	if (pf->prefix_size == 1)
	{
		pf->prefix_line = (char*)ft_memalloc(sizeof(char) * 2);
		buf = pf->prefix_line;
		buf[0] = pf->prefix;
		pf->prefix_line = buf;
	}
	else if (pf->prefix_size == 2 && pf->type == 'x')
		pf->prefix_line = ft_strdup("0x");
	else if (pf->prefix_size == 2 && pf->type == 'X')
		pf->prefix_line = ft_strdup("0X");
}

void	make_width_line(t_printf *pf, char *arg_line)
{
	if ((long)ft_strlen(arg_line) + pf->prefix_size >= pf->width)
		pf->width_str = NULL;
	else if (pf->width != 1)
	{
		pf->width_str = (char*)ft_memalloc(sizeof(char) *
			(pf->width - pf->prefix_size - ft_strlen(arg_line) + 1));
		ft_memset(pf->width_str, ' ', pf->width -
			pf->prefix_size - ft_strlen(arg_line));
		if (pf->zero_flag == 1)
			ft_memset(pf->width_str, '0', pf->width -
				pf->prefix_size - ft_strlen(arg_line));
	}
	go_to_print(pf, arg_line);
}

void	go_to_print(t_printf *pf, char *arg_line)
{
	if (pf->minus_flag == 1)
	{
		ft_putstr(pf->prefix_line);
		ft_putstr(arg_line);
		ft_putstr(pf->width_str);
	}
	else
	{
		if (pf->zero_flag == 1 && pf->prefix_size != 0)
			ft_putstr(pf->prefix_line);
		ft_putstr(pf->width_str);
		if (pf->zero_flag != 1 && pf->prefix_size != 0)
			ft_putstr(pf->prefix_line);
		ft_putstr(arg_line);
	}
	pf->bytes_printed = ft_strlen(arg_line) +
		ft_strlen(pf->width_str) + pf->prefix_size;
	if (pf->prefix_line != NULL)
		free(pf->prefix_line);
	if (pf->width_str != NULL)
		free(pf->width_str);
}
