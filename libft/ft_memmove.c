/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:34:33 by poliveir          #+#    #+#             */
/*   Updated: 2021/03/09 11:40:47 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tempsrc;
	unsigned char	*temp;

	tempsrc = (unsigned char*)src;
	temp = (unsigned char*)dst;
	if (!dst && !src)
		return (NULL);
	if (temp < tempsrc)
		while (len-- > 0)
			*temp++ = *tempsrc++;
	else
	{
		temp += (len - 1);
		tempsrc += (len - 1);
		while (len-- > 0)
			*temp-- = *tempsrc--;
	}
	return (dst);
}
