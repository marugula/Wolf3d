#include "cub3d.h"

unsigned int	get_color_in_pixel(int x, int y, t_img_info img)
{
	char	*dst;

	if (y < 0 || y >= img.height || x < 0 || x >= img.width)
		return (0);
	dst = img.addr + (y * img.size_line + x * (img.bits_p_pix / 8));
	return (*(unsigned int*)dst);
}

void	change_pixel_in_img(int x, int y, t_img_info *img, unsigned int color)
{
	char	*dst;

	if (y < 0 || y >= img->height || x < 0 || x >= img->width)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bits_p_pix / 8));
	*(unsigned int*)dst = color;
}

void	creat_window_img(t_game_window *mlx)
{
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img.height = HEIGHT;
	mlx->img.width = WIDTH;
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_p_pix, &mlx->img.size_line, &mlx->img.endian);
}

# define BLUE	0x34c9eb
# define GREEN	0x83eb34

void	fill_floor_and_cell_window_img(t_img_info *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				change_pixel_in_img(x, y, img, BLUE);
			else
				change_pixel_in_img(x, y, img, GREEN);
			x++;
		}
		y++;
	}
}

void	set_column_to_img(int x_poz, int y_poz, int num_column, int heigth, t_img_info *winimg, t_img_info texture)
{
	int		y;
	float	prop;
	int		src_y;

	y = 0;
	prop = (float) texture.height / (float) heigth;
	while (y < heigth)
	{
		src_y = round((double) y * prop);
		change_pixel_in_img(x_poz, y_poz + y, winimg, get_color_in_pixel(num_column, src_y, texture));
		y++;
	}
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
}

# define SIZE 200

void game(char **map, t_textures textures)
{
	t_data			data;

	data.window.mlx = mlx_init();
	data.window.win = mlx_new_window(data.window.mlx, WIDTH, HEIGHT, "Cub3D");
	creat_window_img(&data.window);
	init_sides_img(&data.imgs, textures, data.window.mlx);
	data.map = map;

	fill_floor_and_cell_window_img(&data.window.img);

	int x = 0;
	int	step = 0;
	while (x < data.imgs.north.width)
	{
		set_column_to_img(100 + step, 100 + step / 2, x, SIZE - step, &(data.window.img), data.imgs.north);
		x++;
		step += 1;
	}


	mlx_put_image_to_window(data.window.mlx, data.window.win, data.window.img.img, 0, 0);
	mlx_loop(data.window.mlx);
}