/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:58:06 by poliveir          #+#    #+#             */
/*   Updated: 2021/05/20 17:57:58 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			n_chr;
	t_details	*details;
	t_details	details_list;

	details = &details_list;
	details->fmt = format;
	details->n_chr_total = 0;
	va_start(details->args, format);
	while (*details->fmt)
	{
		if (*details->fmt == '%')
		{
			details->fmt++;
			ft_check_flags(details);
		}
		else
		{
			ft_putchar_fd(*(details->fmt), 1);
			details->fmt++;
			details->n_chr_total++;
		}
	}
	va_end(details->args);
	n_chr = details->n_chr_total;
	return (n_chr);
}
