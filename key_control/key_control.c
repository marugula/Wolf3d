/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:51:16 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 15:09:19 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	deal_destroy(void)
{
	exit (EXIT_SUCCESS);
}

int	control_pl_dir(t_data *data)
{
	float	direction_step;

	direction_step = M_PI;
	if (data->key.direct == 1)
	{
		data->pl.direction -= direction_step * deltatime_sec(data->time);
	}
	else if (data->key.direct == -1)
	{
		data->pl.direction += direction_step * deltatime_sec(data->time);
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
