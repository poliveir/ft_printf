/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:35:53 by poliveir          #+#    #+#             */
/*   Updated: 2021/03/08 18:50:59 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*new_lst;
	t_list	*new_lst_1st;

	if (lst && f)
	{
		if (!(new_lst = ft_lstnew(f(lst->content))))
			return (NULL);
		new_lst_1st = new_lst;
		lst = lst->next;
		while (lst)
		{
			if (!((new_lst->next) = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&new_lst_1st, del);
				return (NULL);
			}
			lst = lst->next;
			new_lst = new_lst->next;
		}
		return (new_lst_1st);
	}
	return (NULL);
}
