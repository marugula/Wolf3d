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

int	control_pl_dir(t_data *data)
{
	float	direction_step = (float)(M_PI/2) / 90;

	if (data->key.direct == 1)
	{
		data->pl.direction -= direction_step;
	}
	else if (data->key.direct == -1)
	{
		data->pl.direction += direction_step;
	}
	return (0);
}

int	control_pl_poz(t_data *data)
{
	int	speed = 4;
	// int	step = 20;

	if (data->key.y == 1)
	{
		data->pl.poz.x += speed * cos(data->pl.direction);
		data->pl.poz.y -= speed * sin(data->pl.direction);
	}
	else if (data->key.y == -1)
	{
		data->pl.poz.x -= speed * cos(data->pl.direction);
		data->pl.poz.y += speed * sin(data->pl.direction);
	}
	if (data->key.x == -1)
	{
		data->pl.poz.x += speed * cos(data->pl.direction + M_PI / 2);
		data->pl.poz.y -= speed * sin(data->pl.direction + M_PI / 2);
	}
	else if (data->key.x == 1)
	{
		data->pl.poz.x += speed * cos(data->pl.direction - M_PI / 2);
		data->pl.poz.y -= speed * sin(data->pl.direction - M_PI / 2);
	}
	return (0);
}

int	redrawing(t_data *data)
{
	if (data->key.x != 0 || data->key.y != 0 || data->key.direct != 0)
	{
		control_pl_dir(data);
		control_pl_poz(data);
		fill_floor_and_cell_window_img(&data->window.img, data->texture);
		ray_cast(data);
		mlx_do_sync(data->window.mlx);
		mlx_put_image_to_window(data->window.mlx, data->window.win, data->window.img.img, 0, 0);
		write(1, "draw-", 5);
	}
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	(void) y;
	data->pl.direction -= (x - data->key.press_x) * (float)(M_PI/2) / 90;
	data->key.press_x = x;
	return (0);
}

int	control_key_down(int key, t_data *data)
{
	if (key == right)
	{
		data->key.direct = 1;
	}
	else if (key == left)
	{
		data->key.direct = -1;
	}
	if (key == w)
	{
		data->key.y = 1;
	}
	else if (key == s)
	{
		data->key.y = -1;
	}
	if (key == a)
	{
		data->key.x = -1;
	}
	else if (key == d)
	{
		data->key.x = 1;
	}
	return (0);
}

int	control_key_up(int key, t_data *data)
{
	if (key == right)
	{
		data->key.direct = 0;
	}
	else if (key == left)
	{
		data->key.direct = 0;
	}
	if (key == w)
	{
		data->key.y = 0;
	}
	else if (key == s)
	{
		data->key.y = 0;
	}
	if (key == a)
	{
		data->key.x = 0;
	}
	else if (key == d)
	{
		data->key.x = 0;
	}
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
	control_key_up(-1, &data);
	fill_floor_and_cell_window_img(&data.window.img, data.texture);


	ray_cast(&data);


	mlx_put_image_to_window(data.window.mlx, data.window.win, data.window.img.img, 0, 0);

	mlx_key_hook(data.window.win, key_control, &data);

	mlx_hook(data.window.win, ON_KEYDOWN, 0, control_key_down, &data);
	mlx_hook(data.window.win, ON_KEYUP, 0, control_key_up, &data);
	mlx_hook(data.window.win, ON_DESTROY, 0, deal_destroy, 0);

	// mlx_loop_hook(data.window.mlx, control_pl, &data);

	// mlx_hook(data.window.win, BUTTONMOVE, 0, mouse_move, &data);
	mlx_loop_hook(data.window.mlx, redrawing, &data);

	mlx_loop(data.window.mlx);
}
