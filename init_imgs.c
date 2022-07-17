# include "cub3d.h"

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
	img->img = mlx_xpm_file_to_image(mlx_ptr, texture_path, &img->width, &img->height);
	if (img->img == NULL)
	{
		ft_putstr_fd(texture_path, 2);
		exit_error(" img creat ERROR\n");
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_p_pix, &img->size_line, &img->endian);
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
