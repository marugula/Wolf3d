/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:47:41 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 19:02:55 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	redrawing(t_data *data)
{
	rewrite_time(&data->time);
	sprite_animation(data->sprites, data->pl.poz);
	control_pl_dir(data);
	control_pl_poz(data);
	fill_floor_and_cell_window_img(&data->window.img, data->texture);
	ray_cast(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->window.mlx, data->window.win, \
							data->window.img.img, 0, 0);
	return (0);
}

void	init_structs_for_data(char **map, t_textures textures, t_data *data)
{
	data->window = init_game_window();
	init_sides_img(&data->imgs, textures, data->window.mlx);
	init_cat_imgs(data);
	init_minotaur_imgs(data);
	init_door_imgs(data);
	data->map = map;
	data->pl = init_player_direct_and_poz(map);
	data->texture = textures;
	fill_floor_and_cell_window_img(&data->window.img, data->texture);
	init_sprites_struct(data);
}

void	game(char **map, t_textures textures)
{
	t_data	data;

	init_structs_for_data(map, textures, &data);
	ray_cast(&data);
	draw_minimap(&data);
	mlx_put_image_to_window(data.window.mlx, \
							data.window.win, data.window.img.img, 0, 0);
	init_loop_hook(&data);
}
