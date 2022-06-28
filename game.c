#include "cub3d.h"








t_game_window	init_game_window(void)
{
	t_game_window	window;

	window.mlx = mlx_init();
	if (!window.mlx)
		exit_error("init_game_window\n");
	window.win = mlx_new_window(window.mlx, WIDTH, HEIGHT, "CUB3D");
	if (!window.win)
		exit_error("init_game_window\n");
	creat_window_img(&window);
	return (window);
}

int	deal_destroy(void)
{
	exit (EXIT_SUCCESS);
}

int	key_control(int key, t_data *data)
{
	(void ) data;
	if (key == 53)
	{
		exit (EXIT_SUCCESS);
	}
	return (0);
}

int	key_control_down(int key, t_data *data)
{
	int speed = 12;
	// ->124 <-123
	if (key == 124)
	{
		if (data->pl.direction - (float)2 * (M_PI/2) / 90 <= 0.0f)
			data->pl.direction = (float) 2 * M_PI;
		data->pl.direction -= (float)(M_PI/2) / 90;
	}
	else if (key == 123)
	{
		if (data->pl.direction + (float)(M_PI/2) / 90 >= 2 * M_PI)
			data->pl.direction = (float) 0.0f;
		data->pl.direction += (float)(M_PI/2) / 90;
	}
	//w 13 a 0 s 1 d 2
	if (key == 13)
	{
		// if (data->map[(int)data->pl.poz.y][(int)(data->pl.poz.x + (speed * cos(data->pl.direction)))] == '0')
			data->pl.poz.x += speed * cos(data->pl.direction);
		// if (data->map[(int)(data->pl.poz.y - (speed * sin(data->pl.direction)))][(int)data->pl.poz.x] == '0')
			data->pl.poz.y -= speed * sin(data->pl.direction);
	}
	else if (key == 1)
	{
		// if (data->map[(int)data->pl.poz.y][(int)(data->pl.poz.x - (speed * cos(data->pl.direction)))] == '0')
			data->pl.poz.x -= speed * cos(data->pl.direction);
		// if (data->map[(int)(data->pl.poz.y + (speed * sin(data->pl.direction)))][(int)data->pl.poz.x] == '0')
			data->pl.poz.y += speed * sin(data->pl.direction);
	}
	// else
	// {
	// 	return (0); // чтобы дважды не рисовать
	// }

	ft_putnbr_fd(key, 2);
	write(1, "-", 1);
	fill_floor_and_cell_window_img(&data->window.img, data->texture);
	ray_cast(data);
	mlx_put_image_to_window(data->window.mlx, data->window.win, data->window.img.img, 0, 0);
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	data->pl.direction -= (x - data->key.press_x) * (float)(M_PI/2) / 90;
	data->key.press_x = x;
	data->key.press_y = y;
	fill_floor_and_cell_window_img(&data->window.img, data->texture);
	ray_cast(data);
	mlx_put_image_to_window(data->window.mlx, data->window.win, data->window.img.img, 0, 0);

	return (0);
}

void game(char **map, t_textures textures)
{
	t_data	data;

	data.window = init_game_window();
	init_sides_img(&data.imgs, textures, data.window.mlx);
	data.map = map;
	// init pl poz
	data.pl =  init_player_direct_and_poz(map);
	data.texture = textures;
	data.key.button = 0;
	fill_floor_and_cell_window_img(&data.window.img, data.texture);


	ray_cast(&data);


	mlx_put_image_to_window(data.window.mlx, data.window.win, data.window.img.img, 0, 0);

	mlx_key_hook(data.window.win, key_control, &data);
	mlx_hook(data.window.win, ON_KEYDOWN, 0, key_control_down, &data);
	mlx_hook(data.window.win, ON_DESTROY, 0, deal_destroy, 0);

	mlx_hook(data.window.win, BUTTONMOVE, 0, mouse_move, &data);

	mlx_loop(data.window.mlx);
}
