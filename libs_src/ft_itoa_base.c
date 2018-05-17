/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 11:53:30 by amnishen          #+#    #+#             */
/*   Updated: 2018/04/06 11:57:32 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_strlen1(unsigned long n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

static	char	char_check(unsigned long nb, int base)
{
	char	c;
	int		n;

	n = nb % base;
	c = 'a';
	if (n < 10)
		return (n + 48);
	else
	{
		while (n > 10)
		{
			n--;
			c++;
		}
	}
	return (c);
}

char			*ft_itoa_base(unsigned long n, int base)
{
	int				j;
	int				i;
	char			*str;

	i = ft_strlen1(n, base);
	str = (char*)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	j = 0;
	str[i] = '\0';
	i--;
	while (i >= j)
	{
		str[i] = char_check(n, base);
		n = n / base;
		i--;
	}
	return (str);
}
