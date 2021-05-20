/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 21:55:21 by poliveir          #+#    #+#             */
/*   Updated: 2021/03/02 20:47:45 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int i;

	i = 2;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_putnbr(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (!(str = (char*)malloc(ft_count_digits(n))))
		return (NULL);
	if (n == -2147483648)
	{
		str = ft_putnbr(str);
		return (str);
	}
	i = ft_count_digits(n) - 1;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[i--] = '\0';
	while (n > 9)
	{
		str[i] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	str[i] = n + '0';
	return (str);
}
