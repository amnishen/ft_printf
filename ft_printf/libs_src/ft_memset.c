/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:50:28 by amnishen          #+#    #+#             */
/*   Updated: 2017/10/28 15:57:23 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	a;
	unsigned int	i;

	i = 0;
	a = c % 256;
	ptr = (unsigned char*)b;
	while (i < len)
	{
		ptr[i] = a;
		i++;
	}
	return (b);
}
