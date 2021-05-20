/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:38:38 by poliveir          #+#    #+#             */
/*   Updated: 2021/03/08 19:49:18 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int i;
	int sign;
	int r;

	i = 0;
	while (ft_iswspace(str[i]) == 1)
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (ft_isdigit(str[i]) == 1)
	{
		r = 0;
		while (ft_isdigit(str[i]) == 1)
		{
			r = (r * 10) + (str[i] - '0');
			i++;
		}
		return (r * sign);
	}
	return (0);
}
