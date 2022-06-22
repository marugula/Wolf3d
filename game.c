#include "cub3d.h"

unsigned int	get_color_in_pixel(int x, int y, t_img_info img)
{
	char	*dst;

	// printf("x = %d   y = %d    img.size_line = %d    img.bits_p_pix = %d \n\n", x, y, img.size_line, img.bits_p_pix);
	if (y < 0 || y >= img.height || x < 0 || x >= img.width)
		return (0);
	dst = img.addr + (y * img.size_line + x * (img.bits_p_pix / 8));

	// printf("color = %x\n", *(unsigned int*)dst);
	return (*(unsigned int*)dst);
}

void change_pixel_in_img(int x, int y, t_img_info *img, unsigned int color)
{
	char	*dst;

	// printf("y = %d ,  x = %d  img->height = %d  img->width = %d\n", x, y, img->height, img->width);
	if (y < 0 || y >= img->height || x < 0 || x >= img->width)
		return ;
	// printf("was print color %x", color);
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
		// printf("src_y = %d , get_color_in_pixel(num_column, src_y, texture) = %x\n\n", src_y, get_color_in_pixel(num_column, src_y, texture));
		change_pixel_in_img(x_poz, y_poz + y, winimg, get_color_in_pixel(num_column, src_y, texture));
		y++;
	}
}

# define SIZE 200

void game()
{
	t_game_window	win_data;
	t_img_info		img;
	// t_img_info		column;

	win_data.mlx = mlx_init();
	win_data.win = mlx_new_window(win_data.mlx, WIDTH, HEIGHT, "Cub3D");
	creat_window_img(&win_data);
	fill_floor_and_cell_window_img(&win_data.img);

	img.img = mlx_xpm_file_to_image(win_data.mlx, "textures/purple_texture.xpm", &img.width, &img.height);
	// img.img = mlx_xpm_file_to_image(win_data.mlx, "textures/image.xpm", &img.width, &img.height);

	if (img.img == NULL)
		printf("ERORr creat img\n");
	img.addr = mlx_get_data_addr(img.img, &img.bits_p_pix, &img.size_line, &img.endian);

	int x = 0;
	int	step = 0;
	while (x < img.width)
	{
		set_column_to_img(100 + step, 100, x, SIZE, &(win_data.img), img);
		// set_column_to_img(100 + step + 1, 100, x, SIZE, &(win_data.img), img);
		// set_column_to_img(100 + step + 2, 100, x, SIZE, &(win_data.img), img);
		x++;
		step += 1;
	}


	mlx_put_image_to_window(win_data.mlx, win_data.win, win_data.img.img, 0, 0);
	mlx_loop(win_data.mlx);
}