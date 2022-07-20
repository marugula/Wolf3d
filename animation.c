/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:15:43 by marugula          #+#    #+#             */
/*   Updated: 2022/07/20 15:34:31 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

# define OPEN_DIST	300

void	open_door_animation(t_sprite *door, t_vector pl)
{
	if (distance_pyth(pl, door->poz) < OPEN_DIST)
	{
		door->animation_dir = 1;
	}
	else
	{
		door->animation_dir = -1;
	}
	if (door->frame + door->animation_dir <= 7 && door->frame + door->animation_dir >= 0)
		door->frame += door->animation_dir;
}


void	sprite_animation(t_sprite *sprites, t_vector pl)
{
	static int	time = 3;
	int			i;

	time++;
	i = 0;
	if (time % ANIM_PERIOD == 0)
	{
		while (sprites && sprites[i].tex != NULL)
		{
			if (sprites[i].is_door == ISSPRITE)
			{
				sprites[i].frame = \
					(sprites[i].frame + sprites[i].animation_dir) % 8;
				if (sprites[i].frame >= 7 || sprites[i].frame <= 0)
					sprites[i].animation_dir *= -1;
			}
			else
				open_door_animation(sprites + i, pl);
			i++;
		}
	}
}