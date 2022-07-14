/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:23:12 by marugula          #+#    #+#             */
/*   Updated: 2022/07/13 17:38:54 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define IMGSIZE 100

void	draw_black_column(int poz, int size, t_game_window *win)
{
	int	i;

	i = 0;
	while (i < size)
	{
		change_pixel_in_img(poz, i + HEIGHT / 2 - size / 2, &win->img, 0xffffff);
		i++;
	}
}


void	draw_sprit(t_data *data, int *depth_buffer, t_vector sprite_win_poz, int dist)
{
	int	i;

	i = 0;
	while (i < sprite_win_poz.x + IMGSIZE)
	{
		if (depth_buffer[i] > dist)
			draw_black_column(i + sprite_win_poz.x, slice_height(dist), &data->window);
		i++;
	}
}