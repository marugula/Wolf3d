#include "cub3d.h"

t_game_window	init_game_window(void)
{
	t_game_window	game_window;

	game_window.mlx = mlx_init();
	if (!game_window.mlx)
		exit_error("init_game_window\n");
	game_window.win = mlx_new_window(game_window.mlx, WIDTH, HEIGHT, "CUB3D");
	game_window.img = mlx_new_image(game_window.mlx, WIDTH, HEIGHT);
	if (!game_window.win || !game_window.img)
		exit_error("init_game_window\n");
	game_window.addr = mlx_get_data_addr(game_window.img, \
		&game_window.bits_p_pix, &game_window.size_line, &game_window.endian);
	if (!game_window.addr)
		exit_error("init_game_window\n");
	return (game_window);
}

t_point	init_point(int x, int y, char **map)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = map[y][x];
	return (point);
}

// void	my_pixel_put(int x, int y, t_game_window	*game_window)
// {
// 	int	i;

// 	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
// 	{
// 		i = y * game_window->size_line + x * (game_window->bits_p_pix / 8);
// 		(***fdf)->addr[i] = clr;
// 		(***fdf)->addr[++i] = clr >> 8;
// 		(***fdf)->addr[++i] = clr >> 16;
// 	}
// }

// void	draw_line(t_point current_point, t_point direction_point,char **map, t_game_window	game_window)
// {
// 	float	step_x;
// 	float	step_y;
// 	float	max;
// 	float	medium;

// 	step_x = (direction_point.x - current_point.x);
// 	step_y = (direction_point.y - current_point.y);
// 	medium = current_point.x + step_x / 2;
// 	if (fabsf(step_y) > fabsf(step_x))
// 		max = fabsf(step_y);
// 	else
// 		max = fabsf(step_x);
// 	step_x = step_x / max;
// 	step_y = step_y / max;
// 	while ((int)(current_point.x - direction_point.x) || (int)(current_point.y - direction_point.y))
// 	{
// 		current_point.x += step_x;
// 		current_point.y += step_y;
// 	}
// }

// void	draw_map(char **map, int map_height, int map_width, t_game_window	game_window)
// {
// 	int y = 0;
// 	int x = 0;
// 	t_point	current_point;
// 	t_point	direction_point;

// 	while (y < map_height)
// 	{
// 		x = 0;
// 		while (x < map_width)
// 		{
// 			current_point = init_point(x, y, map);
// 			if (x < map_width - 1)
// 			{
// 				direction_point = init_point(x + 1, y, map);
// 				draw_line(current_point, direction_point, map);
// 			}
// 			if (y < map_height - 1)
// 			{
// 				direction_point = init_point(x, y + 1, map);
// 				draw_line(current_point, direction_point, map);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }



// t_imgs	set_imgs_in_mlx(t_game_window game_window)
// {
// 	t_imgs	imgs;

// 	imgs.north.img = 
// }

int	init_game()
{
	// int map_width = 7;
	// int map_height = 6;
	char	*map[6];
	t_game_window	game_window;
	t_imgs imgs;

	map[0] = "1111111";
	map[1] = "1000001";
	map[2] = "1000001";
	map[3] = "1000001";
	map[4] = "1000001";
	map[5] = "1111111";

	int img_height = 2;
	int img_width = 2;

	game_window = init_game_window();
	imgs.north.img = mlx_xpm_file_to_image(game_window.mlx, "textures/pink_texture.xpm", &img_width, &img_height);
	imgs.north.addr = 
	mlx_put_image_to_window(game_window.mlx, game_window.win, game_window.img, 0, 0);
	mlx_loop(game_window.mlx);
	return (0);
}