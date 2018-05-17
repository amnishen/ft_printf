/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_file2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:13:39 by amnishen          #+#    #+#             */
/*   Updated: 2018/05/17 10:13:41 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unicode_write(int *tab, int size)
{
	int		x;

	x = 0;
	while (x < size)
	{
		write(1, &(tab[x]), 1);
		x++;
	}
}

int		gimme_some_int(char *bits_line, int *y)
{
	int		x;
	int		n;
	char	*mask;

	mask = ft_strdup("10xxxxxx");
	n = *y;
	x = 7;
	while (mask[x] == 'x')
		mask[x--] = bits_line[n--];
	x = atoi_binary(mask);
	free(mask);
	*y = n;
	return (x);
}
