/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_dec_to_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:10:53 by poliveir          #+#    #+#             */
/*   Updated: 2021/05/18 20:30:41 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_put_dec_to_hex(size_t hex, char fmt)
{
	if (hex / 16)
		ft_put_dec_to_hex(hex / 16, fmt);
	if (fmt == 'x')
		ft_putchar_fd("0123456789abcdef"[hex % 16], 1);
	else
		ft_putchar_fd("0123456789ABCDEF"[hex % 16], 1);
}
