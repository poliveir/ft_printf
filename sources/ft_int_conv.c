/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:24:02 by poliveir          #+#    #+#             */
/*   Updated: 2021/05/18 21:13:00 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void
	ft_process_wid(t_details *details, int i, int n_digits, int minus_sig)
{
	if (details->flags[minus])
		ft_putnbr_fd(i, 1);
	if (!(details->flags[minus]) && details->flags[zero])
	{
		if (i < 0)
		{
			ft_putchar_fd('-', 1);
			ft_pad(details, details->wid, n_digits + minus_sig, '0');
			if (i == -2147483648)
				ft_putstr_fd("2147483648", 1);
			else
				ft_putnbr_fd(-i, 1);
		}
		else
		{
			ft_pad(details, details->wid, n_digits, '0');
			ft_putnbr_fd(i, 1);
		}
		return ;
	}
	ft_pad(details, details->wid, n_digits + minus_sig, ' ');
	if (!(details->flags[minus]))
		ft_putnbr_fd(i, 1);
}

static void
	ft_process_pre(t_details *details, int i, int n_digits)
{
	if (i == 0 && details->pre < 1)
		return ;
	if (i < 0)
	{
		ft_putchar_fd('-', 1);
		ft_pad(details, details->pre, n_digits, '0');
		if (i == -2147483648)
			ft_putstr_fd("2147483648", 1);
		else
			ft_putnbr_fd(-i, 1);
	}
	else
	{
		ft_pad(details, details->pre, n_digits, '0');
		ft_putnbr_fd(i, 1);
	}
}

static void
	ft_process_wid_and_pre_minus(t_details *details, int i, int n_digits,
	int minus_sig)
{
	if (n_digits < details->pre)
	{
		ft_process_pre(details, i, n_digits);
		ft_pad(details, details->wid, details->pre + minus_sig, ' ');
	}
	else
	{
		ft_process_pre(details, i, n_digits);
		ft_pad(details, details->wid, n_digits + minus_sig, ' ');
	}
}

static void
	ft_process_wid_and_pre(t_details *details, int i, int n_digits,
	int minus_sig)
{
	if (details->flags[minus])
		ft_process_wid_and_pre_minus(details, i, n_digits, minus_sig);
	else
	{
		if (n_digits < details->pre)
		{
			if (details->flags[neg_pre] && details->flags[zero])
				ft_pad(details, details->wid, details->pre + minus_sig, '0');
			else
				ft_pad(details, details->wid, details->pre + minus_sig, ' ');
			ft_process_pre(details, i, n_digits);
		}
		else
		{
			if (details->flags[neg_pre] && details->flags[zero])
			{
				if (i < 0)
					return (ft_process_wid(details, i, n_digits, minus_sig));
				ft_pad(details, details->wid, n_digits + minus_sig, '0');
			}
			else
				ft_pad(details, details->wid, n_digits + minus_sig, ' ');
			ft_process_pre(details, i, n_digits);
		}
	}
}

void
	ft_int_conv(t_details *details)
{
	int	i;
	int	n_chr;
	int	minus_sig;
	int	n_digits;

	minus_sig = 0;
	i = va_arg(details->args, int);
	if (i < 0)
		minus_sig++;
	n_digits = ft_count_digits_sig(i);
	if (details->pre < 0)
		details->pre = 1;
	if (i == 0 && details->flags[point] && details->pre < 1)
		n_digits--;
	n_chr = n_digits + minus_sig;
	details->n_chr_total += n_chr;
	if (!(details->wid) && !(details->flags[point]))
		ft_putnbr_fd(i, 1);
	else if (details->wid && !(details->flags[point]))
		ft_process_wid(details, i, n_digits, minus_sig);
	else if (!(details->wid) && details->flags[point])
		ft_process_pre(details, i, n_digits);
	else
		ft_process_wid_and_pre(details, i, n_digits, minus_sig);
	details->fmt++;
}
