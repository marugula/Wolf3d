/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:51:10 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 12:20:28 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	mouse_move(int x, int y, t_data *data)
{
	(void) y;
	if (data->key.press_x != x)
	{
		data->pl.direction -= \
					(x - data->key.press_x) * (float)(M_PI / 2) / 90 * SPEED_MOUSE_MOVE;
		data->key.press_x = x;
		data->key.mouse_move = 1;
	}
	else
		data->key.mouse_move = 0;
	return (0);
}
