/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:25 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:55:40 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_list;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		new_list = *lst;
		while (new_list->next != NULL)
		{
			new_list = new_list->next;
		}
		new_list->next = new;
	}
}
