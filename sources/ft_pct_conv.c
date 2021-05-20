/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pct_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:38:23 by poliveir          #+#    #+#             */
/*   Updated: 2021/05/19 13:15:22 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void	ft_process_wid(t_details *details)
{
	if (details->flags[minus])
	{
		ft_putchar_fd('%', 1);
		ft_pad(details, details->wid, 1, ' ');
	}
	details->n_chr_total++;
	if (!(details->flags[minus]))
	{
		if (details->flags[zero])
			ft_pad(details, details->wid, 1, '0');
		else
			ft_pad(details, details->wid, 1, ' ');
		ft_putchar_fd('%', 1);
	}
}

void		ft_pct_conv(t_details *details)
{
	if (!(details->wid))
	{
		ft_putchar_fd('%', 1);
		details->n_chr_total++;
	}
	else
		ft_process_wid(details);
	details->fmt++;
}
