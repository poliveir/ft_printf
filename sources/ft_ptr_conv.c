/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 21:55:58 by poliveir          #+#    #+#             */
/*   Updated: 2021/05/18 21:19:35 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void
	ft_process_pre(t_details *details, unsigned long long address)
{
	if (address == 0 && details->pre < 1)
		ft_putstr_fd("0x", 1);
	else
	{
		ft_putstr_fd("0x", 1);
		ft_put_dec_to_hex(address, 'x');
	}
}

static void
	ft_process_wid_and_pre_minus(t_details *details,
				unsigned long long address, int n_digits)
{
	if (n_digits < details->pre)
	{
		ft_process_pre(details, address);
		ft_pad(details, details->wid, details->pre, ' ');
	}
	else
	{
		ft_process_pre(details, address);
		ft_pad(details, details->wid, n_digits, ' ');
	}
}

static void
	ft_process_wid_and_pre(t_details *details, unsigned long long address,
				int n_digits)
{
	if (details->flags[minus])
		ft_process_wid_and_pre_minus(details, address, n_digits);
	else
	{
		if (n_digits < details->pre)
		{
			ft_pad(details, details->wid, details->pre, ' ');
			ft_process_pre(details, address);
		}
		else
		{
			ft_pad(details, details->wid, n_digits, ' ');
			ft_process_pre(details, address);
		}
	}
}

static void
	ft_process_wid(t_details *details, unsigned long long address, int n_digits)
{
	if (details->flags[minus])
	{
		ft_putstr_fd("0x", 1);
		ft_put_dec_to_hex(address, 'x');
	}
	ft_pad(details, details->wid, n_digits, ' ');
	if (!(details->flags[minus]))
	{
		ft_putstr_fd("0x", 1);
		ft_put_dec_to_hex(address, 'x');
	}
}

void
	ft_ptr_conv(t_details *details)
{
	unsigned long long	address;
	int					n_digits;

	address = (unsigned long long)va_arg(details->args, void*);
	n_digits = ft_count_digits_hex(address) + 2;
	if (details->pre < 0)
		details->pre = 1;
	if (address == 0 && details->flags[point] && details->pre < 1)
		n_digits--;
	details->n_chr_total += n_digits;
	if (!(details->wid) && !(details->flags[point]))
	{
		ft_putstr_fd("0x", 1);
		ft_put_dec_to_hex(address, 'x');
	}
	else if (details->wid && !(details->flags[point]))
		ft_process_wid(details, address, n_digits);
	else if (!(details->wid) && details->flags[point])
		ft_process_pre(details, address);
	else
		ft_process_wid_and_pre(details, address, n_digits);
	details->fmt++;
}
