/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:31:27 by amnishen          #+#    #+#             */
/*   Updated: 2017/11/06 19:13:09 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		j;
	size_t	res;

	res = 0;
	j = 0;
	while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t' ||
			str[j] == '\r' || str[j] == '\v' || str[j] == '\f')
		j++;
	if (str[j] == '-' || str[j] == '+')
		j++;
	i = j;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > 9223372036854775807 && str[j - 1] == '-')
		return (0);
	if (res > 9223372036854775807)
		return (-1);
	if (str[j - 1] == '-')
		res = res * -1;
	return (res);
}
