/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:49:11 by marugula          #+#    #+#             */
/*   Updated: 2022/07/20 17:39:16 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	is_wall_in_point(char **map, t_vector point)
{
	int	x;
	int	y;

	x = (int) floor(point.x / (float) GAMEBOXSIZE);
	y = (int) floor(point.y / (float) GAMEBOXSIZE);
	if (x < 0 || y < 0 || y >= strarr_len(map) || x >= (int)ft_strlen(map[y]))
		return (1);
	if (map && map[y] && map[y][x] == '1')
		return (1);
	return (0);
}

t_img_info	texture_mapping(t_imgs imgs, float angle, int is_axis)
{
	if (is_axis)
	{
		if (sin(angle) > 0)
			return (imgs.south);
		else
			return (imgs.north);
	}
	else
	{
		if (cos(angle) > 0)
			return (imgs.west);
		else
			return (imgs.east);
	}
}

t_vector	sum_vectors(t_vector a, t_vector b)
{
	t_vector	new;

	new.x = a.x + b.x;
	new.y = a.y + b.y;
	return (new);
}

float	count_perp_angle(float angle, int dir)
{
	return (angle + dir * M_PI_2);
}

t_vector	shift_poz(t_vector poz, float angle, float shift)
{
	poz.x = poz.x + shift * cos(angle);
	poz.y = poz.y - shift * sin(angle);
	return (poz);
}
