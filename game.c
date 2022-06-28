#include "cub3d.h"



int	is_out_of_border_map(char **map, int x, int y)
{
	if (x < 0 || y < 0 || y >= strarr_len(map) || x >= (int)ft_strlen(map[y]))
		return (1);
	return (0);
}

int	is_wall_in_point(char **map, t_vector point)
{
	int	x;
	int	y;

	x = (int) floor(point.x / (float) GAMEBOXSIZE);
	y = (int) floor(point.y / (float) GAMEBOXSIZE);
	if (is_out_of_border_map(map, x, y))
		return (1);
	if (map && map[y] && map[y][x] == '1')
		return (1);
	return (0);
}


t_vector	find_intersection_points(t_data *data, float angle_ray, int	*number_column)
{
	t_vector	axis_point;
	t_vector	ordinat_point;
	t_vector	axis_step;
	t_vector	ordinat_step;

	if (sin(angle_ray) > 0)
	{
		axis_point.y = floor(data->pl.poz.y / GAMEBOXSIZE) * GAMEBOXSIZE - 1;
		axis_step.y = -GAMEBOXSIZE;
	}
	else
	{
		axis_point.y = floor(data->pl.poz.y / GAMEBOXSIZE) * GAMEBOXSIZE + GAMEBOXSIZE;
		axis_step.y = GAMEBOXSIZE;
	}
	axis_step.x = GAMEBOXSIZE / fabs(tan(angle_ray));
	if (cos(angle_ray) < 0)
		axis_step.x *= -1;

	if (cos(angle_ray) < 0)
		axis_point.x = data->pl.poz.x - fabs((data->pl.poz.y - axis_point.y) / tan(angle_ray));
	else
		axis_point.x = data->pl.poz.x + fabs((data->pl.poz.y - axis_point.y) / tan(angle_ray));



	if (cos(angle_ray) > 0)
	{
		ordinat_point.x = floor(data->pl.poz.x / GAMEBOXSIZE) * GAMEBOXSIZE + GAMEBOXSIZE;
		ordinat_step.x = GAMEBOXSIZE;
	}
	else
	{
		ordinat_point.x = floor(data->pl.poz.x / GAMEBOXSIZE) * GAMEBOXSIZE - 1;
		ordinat_step.x = -GAMEBOXSIZE;
	}
	ordinat_step.y = GAMEBOXSIZE * fabs(tan(angle_ray));
	if (sin(angle_ray) > 0)
		ordinat_step.y *= -1;
	if (sin(angle_ray) > 0)
		ordinat_point.y = data->pl.poz.y - fabs((data->pl.poz.x - ordinat_point.x) * tan(angle_ray));
	else
		ordinat_point.y = data->pl.poz.y + fabs((data->pl.poz.x - ordinat_point.x) * tan(angle_ray));



	while (!is_wall_in_point(data->map, ordinat_point) || !is_wall_in_point(data->map, axis_point))
	{
		if (!is_wall_in_point(data->map, ordinat_point))
			ordinat_point =  sum_vectors(ordinat_point, ordinat_step);

		if (!is_wall_in_point(data->map, axis_point))
			axis_point = sum_vectors(axis_point, axis_step);
	}

	if (distance(data->pl.poz, ordinat_point, angle_ray) < distance(data->pl.poz, axis_point, angle_ray))
	{
		*number_column = nbr_of_slice_column(ordinat_point.y);
		return (ordinat_point);
	}
	else
	{
		*number_column = nbr_of_slice_column(axis_point.x);
		return (axis_point);
	}

}



void	ray_cast(t_data *data)
{
	t_vector	intersection_point;
	float		angle_ray;
	int			num_column;
	int			x;

	angle_ray = data->pl.direction + (FOV / 2);
	x = 0;
	while (angle_ray > data->pl.direction - (FOV / 2) && x < data->window.img.width)
	{
		if (cos(angle_ray) == 0 || sin(angle_ray) == 0)
			intersection_point = find_intersection_points(data, angle_ray + STEPANGLE, &num_column);
		else
			intersection_point = find_intersection_points(data, angle_ray, &num_column);
		set_column_in_img(x, num_column, (int) slice_height(distance(data->pl.poz, intersection_point, angle_ray)), &data->window.img, data->imgs.east);
		x++;
		angle_ray -= STEPANGLE;
	}
}

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
