/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:27:37 by poliveir          #+#    #+#             */
/*   Updated: 2021/05/18 21:15:57 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_pad(t_details *details, int w_or_p, int n_chr, char zero_or_sp)
{
	while (w_or_p > n_chr)
	{
		ft_putchar_fd(zero_or_sp, 1);
		w_or_p--;
		details->n_chr_total++;
	}
}
