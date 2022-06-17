/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:45:15 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:55:56 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static t_list	*ft_new_new_list(t_list *lst, t_list *new_lst,
			void *(*f)(void *), void (*del)(void *))
{
	new_lst = ft_lstnew((*f)(lst->content));
	if (!(new_lst))
	{
		ft_lstclear(&new_lst, del);
		return (0);
	}
	return (new_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*n;

	if (!lst || !f)
		return (0);
	new_lst = 0;
	new_lst = ft_new_new_list(lst, new_lst, (*f), del);
	if (!(new_lst))
		return (0);
	lst = lst->next;
	n = new_lst;
	while (lst != NULL)
	{
		new_lst = ft_lstnew((*f)(lst->content));
		if (!(new_lst))
		{
			ft_lstclear(&new_lst, del);
			ft_lstclear(&n, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&n, new_lst);
	}
	return (n);
}
