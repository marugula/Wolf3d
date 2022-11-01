/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:40:49 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 19:34:22 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_vector	find_poz_player(char **map)
{
	t_vector	poz;

	poz.y = 0;
	while (map[(int)poz.y])
	{
		poz.x = 0;
		while (map[(int)poz.y][(int)poz.x])
		{
			if (map[(int)poz.y][(int)poz.x] == 'N' ||
				map[(int)poz.y][(int)poz.x] == 'S' ||
				map[(int)poz.y][(int)poz.x] == 'E' ||
				map[(int)poz.y][(int)poz.x] == 'W')
			{
				return (poz);
			}
			poz.x++;
		}
		poz.y++;
	}
	poz.x = -1;
	poz.y = -1;
	return (poz);
}

float	get_direction_player(char direct)
{
	float	direction;

	if (direct == 'N')
		direction = M_PI / 2;
	else if (direct == 'W')
		direction = M_PI;
	else if (direct == 'S')
		direction = 3 * M_PI / 2;
	else
		direction = 0;
	return (direction);
}

t_player	init_player_direct_and_poz(char **map)
{
	t_vector	poz;
	t_player	player;

	poz = find_poz_player(map);
	if (poz.x == -1 || poz.y == -1)
		exit_error("Error player not set\n");
	player.direction = get_direction_player(map[(int)poz.y][(int)poz.x]);
	player.poz.x = poz.x * 64 + 32;
	player.poz.y = poz.y * 64 + 32;
	return (player);
}
