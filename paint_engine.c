/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:48:55 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 19:34:07 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_costil	init_clm(int x_poz, int num_column, int heigth)
{
	t_costil	strt;

	strt.x_poz = x_poz;
	strt.num_column = num_column;
	strt.heigth = heigth;
	return (strt);
}

void	draw_wall_column(t_costil info, t_img_info *winimg, t_img_info texture)
{
	int					mid_window;
	int					step;
	float				prop;
	int					img_poz;
	unsigned int		color;

	prop = (float) texture.height / (float) info.heigth;
	mid_window = HEIGHT / 2;
	step = 0;
	while (step < info.heigth / 2 && step < HEIGHT / 2)
	{
		img_poz = round((double)(info.heigth / 2 + step) *prop);
		color = get_color_in_pixel(info.num_column, img_poz, texture);
		if (color != 0 && color != 4278190080)
			change_pixel_in_img(info.x_poz, mid_window + step, winimg, \
			color_shift(color, \
			intensity((float)(GAMEBOXSIZE / 1.5) / (float) info.heigth)));
		img_poz = round((double)(info.heigth / 2 - step) *prop);
		color = get_color_in_pixel(info.num_column, img_poz, texture);
		if (color != 0 && color != 4278190080)
			change_pixel_in_img(info.x_poz, mid_window - step, \
			winimg, color_shift(color, \
			intensity((float)(GAMEBOXSIZE / 1.5) / (float) info.heigth)));
		step++;
	}
}

void	fill_floor_and_cell_window_img(t_img_info *img, t_textures textures)
{
	int		x;
	int		y;
	float	intesive;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		intesive = fabs((float) y - HEIGHT / 2) / (HEIGHT / 2);
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				change_pixel_in_img(x, y, img, \
				color_shift(textures.ceilling, intesive));
			else
				change_pixel_in_img(x, y, img, \
				color_shift(textures.floor, intesive));
			x++;
		}
		y++;
	}
}
