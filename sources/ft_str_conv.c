/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 21:55:58 by poliveir          #+#    #+#             */
/*   Updated: 2021/05/18 21:09:13 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void	ft_put_n_chr_fd(char *s, int fd, int n_chr)
{
	if (!s)
		return ;
	write(fd, s, n_chr);
}

void		ft_str_conv(t_details *details)
{
	char	*s;
	int		n_chr;

	s = va_arg(details->args, char*);
	if (s == NULL)
		s = "(null)";
	n_chr = ft_strlen(s);
	if (details->flags[point] && details->pre < n_chr && details->pre >= 0)
		n_chr = details->pre;
	if (details->flags[minus])
		ft_put_n_chr_fd(s, 1, n_chr);
	ft_pad(details, details->wid, n_chr, ' ');
	if (!(details->flags[minus]))
		ft_put_n_chr_fd(s, 1, n_chr);
	details->n_chr_total += n_chr;
	details->fmt++;
}
