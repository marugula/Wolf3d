/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:33:02 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/19 13:42:47 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	creat_window_img(t_game_window *mlx)
{
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img.img)
		exit_error("error init_game_window\n");
	mlx->img.height = HEIGHT;
	mlx->img.width = WIDTH;
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_p_pix,
			&mlx->img.size_line, &mlx->img.endian);
	if (!mlx->img.addr)
		exit_error("error init_game_window\n");
}

void	init_img(t_img_info *img, char	*texture_path, void *mlx_ptr)
{
	img->img = mlx_xpm_file_to_image \
		(mlx_ptr, texture_path, &img->width, &img->height);
	if (img->img == NULL)
	{
		ft_putstr_fd(texture_path, 2);
		exit_error(" img creat ERROR\n");
	}
	img->addr = mlx_get_data_addr \
		(img->img, &img->bits_p_pix, &img->size_line, &img->endian);
	if (img->addr == NULL)
	{
		ft_putstr_fd(texture_path, 2);
		exit_error("East img get addr ERROR\n");
	}
}

void	init_sides_img(t_imgs *imgs, t_textures texture, void *mlx_ptr)
{
	init_img(&imgs->east, texture.east, mlx_ptr);
	init_img(&imgs->west, texture.west, mlx_ptr);
	init_img(&imgs->south, texture.south, mlx_ptr);
	init_img(&imgs->north, texture.north, mlx_ptr);
	init_img(&imgs->player_icn, "textures/cat.xpm", mlx_ptr);
}
