/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:47:24 by amnishen          #+#    #+#             */
/*   Updated: 2017/11/08 09:35:36 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_memalloc(size_t size)
{
	size_t	n;
	char	*ptr;

	if (size == 0)
		return (NULL);
	n = 0;
	ptr = (char*)malloc(sizeof(char) * size);
	if (ptr == NULL)
		return (NULL);
	while (n < size)
	{
		ptr[n] = '\0';
		n++;
	}
	return (ptr);
}
