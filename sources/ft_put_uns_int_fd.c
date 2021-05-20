/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uns_int_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 23:02:05 by poliveir          #+#    #+#             */
/*   Updated: 2021/05/19 19:52:30 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_put_uns_int_fd(unsigned int n, int fd)
{
	char c;

	if (n > 9)
		ft_put_uns_int_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}
