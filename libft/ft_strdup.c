/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:17:56 by poliveir          #+#    #+#             */
/*   Updated: 2021/03/08 17:37:51 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char		*ft_strdup(const char *s1)
{
	char *ptr;

	if (!(ptr = (char*)(malloc((sizeof(char) * ft_strlen(s1)) + 1))))
		return (NULL);
	else
		ft_strcpy(ptr, s1);
	return (ptr);
}
