/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:51:10 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/10 17:12:55 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	mouse_move(int x, int y, t_data *data)
{
	(void) y;
	if (data->key.press_x != x)
	{
		data->pl.direction -= (x - data->key.press_x) * (float)(M_PI/2) / 90;
		data->key.press_x = x;
		data->key.mouse_move = 1;
	}
	else
		data->key.mouse_move = 0;
	return (0);
}
