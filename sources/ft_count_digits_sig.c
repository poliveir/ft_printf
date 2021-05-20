/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_sig.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 01:50:52 by poliveir          #+#    #+#             */
/*   Updated: 2021/05/19 20:17:28 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_count_digits_sig(long long nbr)
{
	int n_digits;

	if (nbr == (-9223372036854775807 - 1))
		return (20);
	n_digits = 1;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 9)
	{
		n_digits++;
		nbr /= 10;
	}
	return (n_digits);
}
