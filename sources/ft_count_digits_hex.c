/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:06:53 by poliveir          #+#    #+#             */
/*   Updated: 2021/05/18 20:29:40 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_count_digits_hex(size_t hex)
{
	int	n_digits;

	n_digits = 0;
	if (!hex)
		n_digits++;
	while (hex)
	{
		n_digits++;
		hex /= 16;
	}
	return (n_digits);
}
