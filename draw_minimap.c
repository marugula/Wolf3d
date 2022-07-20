/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:15:44 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 19:01:57 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_borders(t_img_info *win, \
		float width, float heigth)
{
	t_vector	point;

	point = init_vector(0, 0);
	while (point.y < heigth)
		change_pixel_in_img(point.x, point.y++, win, 0xfffff);
	point = init_vector(width, 0);
	while (point.y < heigth)
	{
		change_pixel_in_img(point.x, point.y, win, 0xfffff);
		point.y++;
	}
	point = init_vector(0, 0);
	while (point.x < width)
	{
		change_pixel_in_img(point.x, point.y, win, 0xfffff);
		point.x++;
	}
	point = init_vector(0, heigth);
	while (point.x < width)
	{
		change_pixel_in_img(point.x, point.y, win, 0xfffff);
		point.x++;
	}
}

void	draw_cell(float size, t_vector poz, t_img_info *win)
{
	t_vector	i;

	i = poz;
	while (i.y < poz.y + size)
	{
		i.x = poz.x;
		while (i.x < poz.x + size)
		{
			change_pixel_in_img(i.x, i.y, win, 0x0);
			i.x++;
		}
		i.y++;
	}
}

void	draw_wall(t_data *data, float size_cell )
{
	t_vector	poz;

	poz = init_vector(0, 0);
	while (poz.y < strarr_len(data->map))
	{
		poz.x = 0;
		while (poz.x < (int)ft_strlen(data->map[(int)poz.y]))
		{
			if (data->map[(int)poz.y][(int)poz.x] == '1')
				draw_cell(size_cell, init_vector(poz.x * size_cell, \
					poz.y * size_cell), &(data->window.img));
			poz.x++;
		}
		poz.y++;
	}
}

void	draw_player_icn( \
	t_player pl, t_img_info pl_icn, float size_cell, t_img_info *win)
{
	int		x;
	int		y;
	float	prop_shift;
	float	prop_size_icn;

	y = 0;
	prop_shift = size_cell / GAMEBOXSIZE;
	prop_size_icn = pl_icn.height / (4 * size_cell);
	while (y < (4 * size_cell))
	{
		x = 0;
		while (x < (4 * size_cell))
		{
			change_pixel_in_img(shift_x(init_vector(x, y), pl, \
					pl_icn.width, size_cell), \
					shift_y(init_vector(x, y), pl, pl_icn.height, size_cell), \
					win, \
				get_color_in_pixel(x * prop_size_icn, y * \
				prop_size_icn, pl_icn));
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data)
{
	float		size_cell;

	size_cell = count_size_cell(data->map);
	if (size_cell == 0)
		size_cell++;
	draw_borders(&(data->window.img), \
		max_len(data->map) * size_cell, \
		strarr_len(data->map) * size_cell);
	draw_wall(data, size_cell);
	draw_player_icn(data->pl, data->imgs.player_icn, \
		size_cell, &data->window.img);
}
