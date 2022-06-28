/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:51:16 by tamchoor          #+#    #+#             */
/*   Updated: 2022/06/28 16:11:01 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

int	deal_destroy(void)
{
	exit (EXIT_SUCCESS);
}

int	control_pl_dir(t_data *data)
{
	float	direction_step = (float)(M_PI/2) / 90;

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
	int	speed = 4;

	if (data->key.y == 1)
	{
		data->pl.poz.x += speed * cos(data->pl.direction);
		data->pl.poz.y -= speed * sin(data->pl.direction);
	}
	else if (data->key.y == -1)
	{
		data->pl.poz.x -= speed * cos(data->pl.direction);
		data->pl.poz.y += speed * sin(data->pl.direction);
	}
	if (data->key.x == -1)
	{
		data->pl.poz.x += speed * cos(data->pl.direction + M_PI / 2);
		data->pl.poz.y -= speed * sin(data->pl.direction + M_PI / 2);
	}
	else if (data->key.x == 1)
	{
		data->pl.poz.x += speed * cos(data->pl.direction - M_PI / 2);
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
