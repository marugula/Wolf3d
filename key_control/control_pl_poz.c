/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_pl_poz.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:38:36 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 15:07:34 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_sprite_in_point(char **map, t_vector point)
{
	int	x;
	int	y;

	x = (int) floor(point.x / (float) GAMEBOXSIZE);
	y = (int) floor(point.y / (float) GAMEBOXSIZE);
	if (x < 0 || y < 0 || y >= strarr_len(map) || x >= (int)ft_strlen(map[y]))
		return (1);
	if (map && ((map[y] && map[y][x] == 'C') || (map[y] && map[y][x] == 'M')))
		return (1);
	return (0);
}

int	check_moving(char **map, t_vector point)
{
	if (is_sprite_in_point(map, point) || is_wall_in_point (map, point))
		return (1);
	return (0);
}

void	moving_ordinat(t_data *data, int speed)
{
	if (data->key.y == 1)
	{
		if (check_moving(data->map, \
						init_vector(data->pl.poz.x + speed * \
						cos(data->pl.direction), data->pl.poz.y)) == 0)
			data->pl.poz.x += speed * cos(data->pl.direction);
		if (check_moving(data->map, \
						init_vector(data->pl.poz.x, data->pl.poz.y - speed * \
						sin(data->pl.direction))) == 0)
			data->pl.poz.y -= speed * sin(data->pl.direction);
	}
	else if (data->key.y == -1)
	{
		if (check_moving(data->map, \
						init_vector(data->pl.poz.x - speed * \
						cos(data->pl.direction), data->pl.poz.y)) == 0)
			data->pl.poz.x -= speed * cos(data->pl.direction);
		if (check_moving(data->map, \
						init_vector(data->pl.poz.x, data->pl.poz.y + \
						speed * sin(data->pl.direction))) == 0)
			data->pl.poz.y += speed * sin(data->pl.direction);
	}
}

void	moving_axis(t_data *data, int speed)
{
	if (data->key.x == -1)
	{
		if (check_moving(data->map, \
					init_vector(data->pl.poz.x + speed * \
					cos(data->pl.direction + M_PI / 2), data->pl.poz.y)) == 0)
			data->pl.poz.x += speed * cos(data->pl.direction + M_PI / 2);
		if (check_moving(data->map, \
					init_vector(data->pl.poz.x, data->pl.poz.y - speed * \
					sin(data->pl.direction + M_PI / 2))) == 0)
			data->pl.poz.y -= speed * sin(data->pl.direction + M_PI / 2);
	}
	else if (data->key.x == 1)
	{
		if (check_moving(data->map, \
					init_vector(data->pl.poz.x - speed * \
					cos(data->pl.direction + M_PI / 2), data->pl.poz.y)) == 0)
			data->pl.poz.x += speed * cos(data->pl.direction - M_PI / 2);
		if (check_moving(data->map, \
					init_vector(data->pl.poz.x, data->pl.poz.y + speed * \
					sin(data->pl.direction + M_PI / 2))) == 0)
			data->pl.poz.y -= speed * sin(data->pl.direction - M_PI / 2);
	}
}

int	control_pl_poz(t_data *data)
{
	moving_ordinat(data, SPEED_PL_MOVE * deltatime_sec(data->time));
	moving_axis(data, SPEED_PL_MOVE * deltatime_sec(data->time));
	return (0);
}
