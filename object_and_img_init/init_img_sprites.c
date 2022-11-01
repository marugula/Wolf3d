/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:32:53 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/19 13:42:44 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_cat_imgs(t_data *data)
{
	init_img(&data->imgs.cat[0], \
			"textures/cat/cat1.xpm", data->window.mlx);
	init_img(&data->imgs.cat[1], \
			"textures/cat/cat2.xpm", data->window.mlx);
	init_img(&data->imgs.cat[2], \
			"textures/cat/cat3.xpm", data->window.mlx);
	init_img(&data->imgs.cat[3], \
			"textures/cat/cat4.xpm", data->window.mlx);
	init_img(&data->imgs.cat[4], \
			"textures/cat/cat5.xpm", data->window.mlx);
	init_img(&data->imgs.cat[5], \
			"textures/cat/cat6.xpm", data->window.mlx);
	init_img(&data->imgs.cat[6], \
			"textures/cat/cat7.xpm", data->window.mlx);
	init_img(&data->imgs.cat[7], \
			"textures/cat/cat8.xpm", data->window.mlx);
}

void	init_minotaur_imgs(t_data *data)
{
	init_img(&data->imgs.minotaur[0], \
			"textures/minotaur/Minotaur1.xpm", data->window.mlx);
	init_img(&data->imgs.minotaur[1], \
			"textures/minotaur/Minotaur2.xpm", data->window.mlx);
	init_img(&data->imgs.minotaur[2], \
			"textures/minotaur/Minotaur3.xpm", data->window.mlx);
	init_img(&data->imgs.minotaur[3], \
			"textures/minotaur/Minotaur4.xpm", data->window.mlx);
	init_img(&data->imgs.minotaur[4], \
			"textures/minotaur/Minotaur5.xpm", data->window.mlx);
	init_img(&data->imgs.minotaur[5], \
			"textures/minotaur/Minotaur6.xpm", data->window.mlx);
	init_img(&data->imgs.minotaur[6], \
			"textures/minotaur/Minotaur7.xpm", data->window.mlx);
	init_img(&data->imgs.minotaur[7], \
			"textures/minotaur/Minotaur0.xpm", data->window.mlx);
}

void	init_door_imgs(t_data *data)
{
	init_img(&data->imgs.door[0], \
			"textures/door/door.xpm", data->window.mlx);
	init_img(&data->imgs.door[1], \
			"textures/door/opendoor1.xpm", data->window.mlx);
	init_img(&data->imgs.door[2], \
			"textures/door/opendoor2.xpm", data->window.mlx);
	init_img(&data->imgs.door[3], \
			"textures/door/opendoor3.xpm", data->window.mlx);
	init_img(&data->imgs.door[4], \
			"textures/door/opendoor4.xpm", data->window.mlx);
	init_img(&data->imgs.door[5], \
			"textures/door/opendoor5.xpm", data->window.mlx);
	init_img(&data->imgs.door[6], \
			"textures/door/opendoor6.xpm", data->window.mlx);
	init_img(&data->imgs.door[7], \
			"textures/door/opendoor7.xpm", data->window.mlx);
}
