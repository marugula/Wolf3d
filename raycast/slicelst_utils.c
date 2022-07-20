/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slicework.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:18:43 by marugula          #+#    #+#             */
/*   Updated: 2022/07/20 16:22:58 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	*clear_slice_list(t_slice_sp *list)
{
	t_slice_sp *temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	return (NULL);
}

int	slice_lst_is_sorted(t_slice_sp *slice_lst)
{
	while (slice_lst && slice_lst->next)
	{
		if (slice_lst->dist < slice_lst->next->dist)
			return (NOTSORTED);
		slice_lst = slice_lst->next;
	}
	return (SORTED);
}

int	size_slice_lst(t_slice_sp *slice_lst)
{
	int	i;

	i = 0;
	while (slice_lst != NULL)
	{
		slice_lst = slice_lst->next;
		i++;
	}
	return (i);
}

void	swap_value_slice_list(t_slice_sp *slice1, t_slice_sp *slice2)
{
	t_slice_sp	temp;

	temp.dist = slice1->dist;
	temp.img = slice1->img;
	temp.num_slice = slice1->num_slice;
	slice1->dist = slice2->dist;
	slice1->img = slice2->img;
	slice1->num_slice = slice2->num_slice;
	slice2->dist =temp.dist;
	slice2->img =temp.img;
	slice2->num_slice =temp.num_slice;
}

void	sort_slice_lst(t_slice_sp *slice_lst)
{
	t_slice_sp	*iterator;

	while (slice_lst_is_sorted(slice_lst) != SORTED)
	{
		iterator = slice_lst;
		while (iterator->next != NULL)
		{
			if (iterator->dist < iterator->next->dist)
			{
				swap_value_slice_list(iterator, iterator->next);
			}
			iterator = iterator->next;
		}
	}
}

