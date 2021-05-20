/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:49:38 by poliveir          #+#    #+#             */
/*   Updated: 2021/05/20 17:57:12 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define TRUE 1
# define FALSE 0

enum				e_flags
{
	minus = 0,
	zero = 1,
	point = 2,
	neg_pre = 3
};

typedef struct	s_details
{
	const char	*fmt;
	va_list		args;
	int			wid;
	int			pre;
	int			flags[4];
	int			n_chr_total;
}				t_details;

/*
** MAIN FUNCTION:
*/

int				ft_printf(const char *format, ...);

/*
** FLAG CHECKING:
*/

void			ft_check_flags(t_details *details);

/*
** CONVERSIONS:
*/

void			ft_conversions(t_details *details);

void			ft_chr_conv(t_details *details);

void			ft_str_conv(t_details *details);

void			ft_ptr_conv(t_details *details);

void			ft_int_conv(t_details *details);

void			ft_uns_int_conv(t_details *details);

void			ft_hex_conv(t_details *details);

void			ft_pct_conv(t_details *details);

/*
** UTILITIES:
*/

int				ft_count_digits_hex(size_t hex);

int				ft_count_digits_sig(long long nbr);

int				ft_count_digits_uns(size_t nbr);

void			ft_put_uns_int_fd(unsigned int nbr, int fd);

void			ft_put_dec_to_hex(size_t hex, char fmt);

void			ft_pad(t_details *details, int w_or_p,
				int n_chr, char zero_or_sp);

#endif
