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

int	redrawing(t_data *data)
{
	if (data->key.x != 0 || data->key.y != 0 || data->key.direct != 0 || data->key.mouse_move != 0)
	{
		control_pl_dir(data);
		control_pl_poz(data);
		fill_floor_and_cell_window_img(&data->window.img, data->texture);
		ray_cast(data);
		mlx_do_sync(data->window.mlx);
		mlx_put_image_to_window(data->window.mlx, data->window.win, data->window.img.img, 0, 0);
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
	fill_floor_and_cell_window_img(&data.window.img, data.texture);


	ray_cast(&data);


	mlx_put_image_to_window(data.window.mlx, data.window.win, data.window.img.img, 0, 0);

	init_control_key(&data);
	mlx_hook(data.window.win, ON_KEYDOWN, 0, control_key_down, &data);
	mlx_hook(data.window.win, ON_KEYUP, 0, control_key_up, &data);
	mlx_hook(data.window.win, ON_DESTROY, 0, deal_destroy, 0);
	mlx_hook(data.window.win, BUTTONMOVE, 0, mouse_move, &data);
	mlx_loop_hook(data.window.mlx, redrawing, &data);

	mlx_loop(data.window.mlx);
}
