/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:51:16 by tamchoor          #+#    #+#             */
/*   Updated: 2022/06/28 19:02:50 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

int	deal_destroy(void)
{
	exit (EXIT_SUCCESS);
}

int	control_pl_dir(t_data *data)
{
	float	direction_step = M_PI / 30;

	if (data->key.direct == 1)
	{
		data->pl.direction -= direction_step;
	}
	else if (data->key.direct == -1)
	{
		data->pl.direction += direction_step;
	}
	return (0);
}



int	control_pl_poz(t_data *data)
{
	int	speed = 10;

	if (data->key.y == 1)
	{
		if (is_wall_in_point(data->map, init_vector(data->pl.poz.x + speed * cos(data->pl.direction), data->pl.poz.y)) == 0)
			data->pl.poz.x += speed * cos(data->pl.direction);
		if (is_wall_in_point(data->map, init_vector(data->pl.poz.x, data->pl.poz.y - speed * sin(data->pl.direction))) == 0)
			data->pl.poz.y -= speed * sin(data->pl.direction);
	}
	else if (data->key.y == -1)
	{
		if (is_wall_in_point(data->map, init_vector(data->pl.poz.x - speed * cos(data->pl.direction), data->pl.poz.y)) == 0)
			data->pl.poz.x -= speed * cos(data->pl.direction);
		if (is_wall_in_point(data->map, init_vector(data->pl.poz.x, data->pl.poz.y + speed * sin(data->pl.direction))) == 0)
			data->pl.poz.y += speed * sin(data->pl.direction);
	}
	if (data->key.x == -1)
	{
		if (is_wall_in_point(data->map, init_vector(data->pl.poz.x + speed * cos(data->pl.direction +  M_PI / 2), data->pl.poz.y)) == 0)
			data->pl.poz.x += speed * cos(data->pl.direction + M_PI / 2);
		if (is_wall_in_point(data->map, init_vector(data->pl.poz.x, data->pl.poz.y - speed * sin(data->pl.direction + M_PI / 2))) == 0)
			data->pl.poz.y -= speed * sin(data->pl.direction + M_PI / 2);
	}
	else if (data->key.x == 1)
	{
		if (is_wall_in_point(data->map, init_vector(data->pl.poz.x - speed * cos(data->pl.direction +  M_PI / 2), data->pl.poz.y)) == 0)
			data->pl.poz.x += speed * cos(data->pl.direction - M_PI / 2);
		if (is_wall_in_point(data->map, init_vector(data->pl.poz.x, data->pl.poz.y + speed * sin(data->pl.direction + M_PI / 2))) == 0)
			data->pl.poz.y -= speed * sin(data->pl.direction - M_PI / 2);
	}
	return (0);
}

int	control_key_down(int key, t_data *data)
{
	if (key == right)
		data->key.direct = 1;
	else if (key == left)
		data->key.direct = -1;
	if (key == w)
		data->key.y = 1;
	else if (key == s)
		data->key.y = -1;
	if (key == a)
		data->key.x = -1;
	else if (key == d)
		data->key.x = 1;
	if (key == esc)
		exit (EXIT_SUCCESS);
	return (0);
}

int	control_key_up(int key, t_data *data)
{
	if (key == right)
		data->key.direct = 0;
	else if (key == left)
		data->key.direct = 0;
	if (key == w)
		data->key.y = 0;
	else if (key == s)
		data->key.y = 0;
	if (key == a)
		data->key.x = 0;
	else if (key == d)
		data->key.x = 0;
	return (0);
}
