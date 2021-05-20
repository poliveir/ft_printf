/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:57:27 by poliveir          #+#    #+#             */
/*   Updated: 2021/03/01 22:35:24 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t lendst;
	size_t i;
	size_t j;

	lendst = ft_strlen(dst);
	i = lendst;
	j = 0;
	if (dstsize == 0)
		return ((unsigned long)ft_strlen(src));
	else if (dstsize < lendst)
		return ((unsigned long)(ft_strlen(src) + dstsize));
	while (i < (dstsize - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return ((unsigned long)(lendst + ft_strlen(src)));
}
