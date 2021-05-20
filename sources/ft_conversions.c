/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:29:49 by poliveir          #+#    #+#             */
/*   Updated: 2021/05/20 01:37:23 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_conversions(t_details *details)
{
	if (*details->fmt == 'c')
		ft_chr_conv(details);
	else if (*details->fmt == 's')
		ft_str_conv(details);
	else if (*details->fmt == 'p')
		ft_ptr_conv(details);
	else if (*details->fmt == 'd' || *details->fmt == 'i')
		ft_int_conv(details);
	else if (*details->fmt == 'u')
		ft_uns_int_conv(details);
	else if (*details->fmt == 'x' || *details->fmt == 'X')
		ft_hex_conv(details);
	else if (*details->fmt == '%')
		ft_pct_conv(details);
}
