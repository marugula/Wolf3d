#include "cub3d.h"


# define SIZE 300

void	paint_sample(t_data *data)
{
	int x = 0;
	int	step = 0;
	while (x < data->imgs.north.width)
	{
		set_column_in_img(100 + step, x, SIZE - step, &(data->window.img), data->imgs.north);
		x++;
		step += 1;
	}
}

float	find_intersection_point_axis(t_data *data)
{
	// float	step_x;
	float	step_y;

	if (sin(data->pl.direction) > 1)
		step_y = GAMEBOXSIZE;
	else
		step_y = -GAMEBOXSIZE;

	return (0);
}


t_vector	sum_vectors(t_vector a, t_vector b)
{
	t_vector	new;

	new.x = a.x + b.x;
	new.y = a.y + b.y;
	return (new);
}

float	distance(t_vector point_from, t_vector point_to, float angle_ray)
{
	double	distance;

	distance = fabs(fabs(point_from.x - point_to.x) / cos (angle_ray));
	return ((float) distance);
}

float	slice_height(float distance)
{
	float	height;

	height = (float) GAMEBOXSIZE / distance * (float) PLANEDIST;
	return (height);
}


int	nbr_of_slice_column(float point)
{
	int	nbr;

	nbr = (int) floor(fmod(point, GAMEBOXSIZE));
	return (nbr);
}

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


float	correct_distance(float distance, float angle)
{
	return (distance * cos(angle));
}

void	ray_cast(t_data *data)
{
	float		angle_ray;
	t_vector	intersection_point;
	float		dist;
	int			height;
	int			num_column;
	int			x;
	// вычесление крайего левого луча
	angle_ray = data->pl.direction + (FOV / 2);

	x = 0;
	while (angle_ray > data->pl.direction - (FOV / 2) && x < data->window.img.width)
	{
		if (cos(angle_ray) == 0 || sin(angle_ray) == 0)
			intersection_point = find_intersection_points(data, angle_ray + STEPANGLE, &num_column);
		else
			intersection_point = find_intersection_points(data, angle_ray, &num_column);
		dist = distance(data->pl.poz, intersection_point, angle_ray);
		height = (int) slice_height(dist);
		set_column_in_img(x, num_column, height, &data->window.img, data->imgs.east);
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


void game(char **map, t_textures textures)
{
	t_data	data;

	data.window = init_game_window();
	init_sides_img(&data.imgs, textures, data.window.mlx);
	data.map = map;
	// init pl poz
	data.pl =  init_player_direct_and_poz(map);


	fill_floor_and_cell_window_img(&data.window.img, textures);

	// paint_sample(&data);

	ray_cast(&data);


	mlx_put_image_to_window(data.window.mlx, data.window.win, data.window.img.img, 0, 0);
	mlx_loop(data.window.mlx);
}