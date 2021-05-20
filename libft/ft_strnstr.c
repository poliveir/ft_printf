/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:30:48 by poliveir          #+#    #+#             */
/*   Updated: 2021/03/02 14:54:44 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	if (needle[0] == '\0')
		return ((char*)haystack);
	else
	{
		i = 0;
		while (haystack[i] != '\0' && i < len)
		{
			j = 0;
			k = i;
			while (haystack[k] == needle[j] && k < len)
			{
				k++;
				j++;
				if (needle[j] == '\0')
					return ((char*)&haystack[k - j]);
			}
			i++;
		}
		return (NULL);
	}
}
