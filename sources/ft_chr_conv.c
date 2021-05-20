/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 21:55:58 by poliveir          #+#    #+#             */
/*   Updated: 2021/05/20 00:50:46 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_chr_conv(t_details *details)
{
	unsigned char	c;

	c = va_arg(details->args, int);
	if (details->flags[minus])
	{
		ft_putchar_fd(c, 1);
		details->n_chr_total++;
	}
	ft_pad(details, details->wid, 1, ' ');
	if (!(details->flags[minus]))
	{
		ft_putchar_fd(c, 1);
		details->n_chr_total++;
	}
	details->fmt++;
}
