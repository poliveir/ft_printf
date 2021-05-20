/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 21:55:58 by poliveir          #+#    #+#             */
/*   Updated: 2021/05/18 21:11:39 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void
	ft_process_pre(t_details *details, unsigned int hex, int n_digits)
{
	if (hex == 0 && details->pre < 1)
		return ;
	else
	{
		ft_pad(details, details->pre, n_digits, '0');
		ft_put_dec_to_hex(hex, *details->fmt);
	}
}

static void
	ft_process_wid_and_pre_minus(t_details *details, unsigned int hex,
					int n_digits)
{
	if (n_digits < details->pre)
	{
		ft_process_pre(details, hex, n_digits);
		ft_pad(details, details->wid, details->pre, ' ');
	}
	else
	{
		ft_process_pre(details, hex, n_digits);
		ft_pad(details, details->wid, n_digits, ' ');
	}
}

static void
	ft_process_wid_and_pre(t_details *details, unsigned int hex, int n_digits)
{
	if (details->flags[minus])
		ft_process_wid_and_pre_minus(details, hex, n_digits);
	else
	{
		if (n_digits < details->pre)
		{
			if (details->flags[neg_pre] && details->flags[zero])
				ft_pad(details, details->wid, details->pre, '0');
			else
				ft_pad(details, details->wid, details->pre, ' ');
			ft_process_pre(details, hex, n_digits);
		}
		else
		{
			if (details->flags[neg_pre] && details->flags[zero])
				ft_pad(details, details->wid, n_digits, '0');
			else
				ft_pad(details, details->wid, n_digits, ' ');
			ft_process_pre(details, hex, n_digits);
		}
	}
}

static void
	ft_process_wid(t_details *details, unsigned int hex, int n_digits)
{
	if (details->flags[minus])
		ft_put_dec_to_hex(hex, *details->fmt);
	if (!(details->flags[minus]) && details->flags[zero])
	{
		ft_pad(details, details->wid, n_digits, '0');
		ft_put_dec_to_hex(hex, *details->fmt);
		return ;
	}
	ft_pad(details, details->wid, n_digits, ' ');
	if (!(details->flags[minus]))
		ft_put_dec_to_hex(hex, *details->fmt);
}

void
	ft_hex_conv(t_details *details)
{
	unsigned int	hex;
	int				n_digits;

	hex = va_arg(details->args, unsigned int);
	n_digits = ft_count_digits_hex(hex);
	if (details->pre < 0)
		details->pre = 1;
	if (hex == 0 && details->flags[point] && details->pre < 1)
		n_digits--;
	details->n_chr_total += n_digits;
	if (!(details->wid) && !(details->flags[point]))
		ft_put_dec_to_hex(hex, *details->fmt);
	else if (details->wid && !(details->flags[point]))
		ft_process_wid(details, hex, n_digits);
	else if (!(details->wid) && details->flags[point])
		ft_process_pre(details, hex, n_digits);
	else
		ft_process_wid_and_pre(details, hex, n_digits);
	details->fmt++;
}
