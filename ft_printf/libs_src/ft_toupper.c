/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:12:47 by amnishen          #+#    #+#             */
/*   Updated: 2017/10/29 15:16:52 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

char	*ft_toupper_str(char *str)
{
	size_t	n;

	if (str == NULL)
		return (NULL);
	n = 0;
	while (str[n])
	{
		if (str[n] >= 'a' && str[n] <= 'z')
			str[n] = str[n] - 32;
		n++;
	}
	return (str);
}
