/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:23:57 by marugula          #+#    #+#             */
/*   Updated: 2022/07/20 17:45:44 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	add_dist_to_door_slice( \
	t_slice_sp *slice, t_sprite sprite, t_player ray_info)
{
	float		door_dir;
	t_vector	ippoz;

	slice->is_door = sprite.is_door;
	if (slice->is_door == ISDOORAXIS)
	{
		if (sin(ray_info.direction) > 0)
			door_dir = 0;
		else
			door_dir = M_PI;
	}
	else
	{
		if (cos(ray_info.direction) < 0)
			door_dir = M_PI / 2;
		else
			door_dir = 3 * M_PI / 2 ;
	}
	ippoz = shift_poz(sprite.poz, door_dir, \
				(sprite.tex->width / 2) - slice->num_slice);
	slice->dist = distance_pyth(ray_info.poz, ippoz);
}

void	fill_slice(t_slice_sp *slices, t_sprite sprite, \
				int slice_num, t_player ray_info)
{
	slices->dist = sprite.dist_to_pl;
	slices->img = &sprite.tex[sprite.frame];
	slices->num_slice = slice_num;
	slices->is_door = sprite.is_door;
	if (sprite.is_door)
		add_dist_to_door_slice(slices, sprite, ray_info);
}

t_slice_sp	*add_new_sprite_slice( \
	t_slice_sp *slices, t_sprite sprite, int slice_num, t_player ray_info)
{
	t_slice_sp	*temp;

	temp = slices;
	if (slices == NULL)
	{
		slices = ft_calloc(1, sizeof(t_slice_sp));
		if (slices == NULL)
			exit_error("Malloc error");
		fill_slice(slices, sprite, slice_num, ray_info);
		return (slices);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = ft_calloc(1, sizeof(t_slice_sp));
	if (temp->next == NULL)
		exit_error("Malloc error");
	fill_slice(temp->next, sprite, slice_num, ray_info);
	return (slices);
}
