/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_uns.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 01:50:52 by poliveir          #+#    #+#             */
/*   Updated: 2021/05/18 20:29:58 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_count_digits_uns(size_t nbr)
{
	int n_digits;

	n_digits = 1;
	while (nbr > 9)
	{
		n_digits++;
		nbr /= 10;
	}
	return (n_digits);
}
