/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:12:25 by poliveir          #+#    #+#             */
/*   Updated: 2021/05/20 01:42:04 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void	ft_reset_flags(t_details *details)
{
	details->wid = 0;
	details->pre = 0;
	details->flags[minus] = FALSE;
	details->flags[zero] = FALSE;
	details->flags[point] = FALSE;
	details->flags[neg_pre] = FALSE;
}

static void	ft_check_wid(t_details *details)
{
	if (*details->fmt == '*')
	{
		details->wid = va_arg(details->args, int);
		if (details->wid < 0)
		{
			details->flags[minus] = TRUE;
			details->wid *= -1;
		}
		details->fmt++;
	}
	if (ft_isdigit(*details->fmt))
		details->wid = ft_atoi(details->fmt);
	while (ft_isdigit(*details->fmt))
		details->fmt++;
}

static void	ft_check_pre(t_details *details)
{
	if (*details->fmt == '.')
	{
		details->flags[point] = TRUE;
		details->fmt++;
		if (*details->fmt == '*')
		{
			details->pre = va_arg(details->args, int);
			if (details->pre < 0)
				details->flags[neg_pre] = TRUE;
			details->fmt++;
		}
		if (ft_isdigit(*details->fmt))
			details->pre = ft_atoi(details->fmt);
		while (ft_isdigit(*details->fmt))
			details->fmt++;
	}
}

void		ft_check_flags(t_details *details)
{
	ft_reset_flags(details);
	while (!(ft_strrchr("cpsdiuxX%", *details->fmt)) && *details->fmt)
	{
		if (*details->fmt == '-')
		{
			details->flags[minus] = TRUE;
			details->fmt++;
		}
		else if (*details->fmt == '0')
		{
			details->flags[zero] = TRUE;
			details->fmt++;
		}
		ft_check_wid(details);
		ft_check_pre(details);
	}
	if (ft_strrchr("cpsdiuxX%", *details->fmt))
		ft_conversions(details);
}
