/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:10:18 by amnishen          #+#    #+#             */
/*   Updated: 2018/04/26 16:24:14 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				atoi_binary(char *str)
{
	int			i;
	int			j;
	size_t		res;

	res = 0;
	j = 0;
	while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t' ||
			str[j] == '\r' || str[j] == '\v' || str[j] == '\f')
		j++;
	if (str[j] == '-' || str[j] == '+')
		j++;
	i = j;
	while (str[i] >= '0' && str[i] <= '1')
	{
		res = res * 2 + (str[i] - '0');
		i++;
	}
	if (str[j - 1] == '-')
		res = res * -1;
	return (res);
}

static	void	bits_line_2(char *bits_line, int x, int y, int n)
{
	char		*mask1;
	int			tab[2];

	mask1 = ft_strdup("110xxxxx");
	while (n != 0)
		tab[n--] = gimme_some_int(bits_line, &y);
	while (y >= 0)
		mask1[x--] = bits_line[y--];
	while (x > 0)
	{
		if (mask1[x] == 'x')
			mask1[x] = '0';
		x--;
	}
	tab[0] = atoi_binary(mask1);
	unicode_write(tab, 2);
	free(mask1);
}

static	void	bits_line_3(char *bits_line, int x, int y, int n)
{
	char		*mask1;
	int			tab[3];

	mask1 = ft_strdup("1110xxxx");
	while (n != 0)
		tab[n--] = gimme_some_int(bits_line, &y);
	while (y >= 0)
		mask1[x--] = bits_line[y--];
	while (x > 0)
	{
		if (mask1[x] == 'x')
			mask1[x] = '0';
		x--;
	}
	tab[0] = atoi_binary(mask1);
	unicode_write(tab, 3);
	free(mask1);
}

static	void	bits_line_4(char *bits_line, int x, int y, int n)
{
	char		*mask1;
	int			tab[4];

	mask1 = ft_strdup("11110xxx");
	while (n != 0)
		tab[n--] = gimme_some_int(bits_line, &y);
	while (y >= 0)
		mask1[x--] = bits_line[y--];
	while (x > 0)
	{
		if (mask1[x] == 'x')
			mask1[x] = '0';
		x--;
	}
	tab[0] = atoi_binary(mask1);
	unicode_write(tab, 4);
	free(mask1);
}

void			do_some_unicode_pls(int uni)
{
	char		*bits_line;

	bits_line = ft_itoa_base(uni, 2);
	if (ft_strlen(bits_line) <= 7)
		write(1, &uni, 1);
	else if (ft_strlen(bits_line) <= 11 && ft_strlen(bits_line) > 7)
		bits_line_2(bits_line, 7, ft_strlen(bits_line) - 1, 1);
	else if (ft_strlen(bits_line) <= 16 && ft_strlen(bits_line) > 11)
		bits_line_3(bits_line, 7, ft_strlen(bits_line) - 1, 2);
	else
		bits_line_4(bits_line, 7, ft_strlen(bits_line) - 1, 3);
	free(bits_line);
}
