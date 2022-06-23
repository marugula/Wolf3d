#include "cub3d.h"


# define SIZE 300

void	paint_sample(t_data *data)
{
	int x = 0;
	int	step = 0;
	while (x < data->imgs.north.width)
	{
		set_column_in_img(100 + step, 100 + step / 2, x, SIZE - step, &(data->window.img), data->imgs.north);
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

float	distance(t_vector point1, t_vector point2, float angle)
{


	return (float);
}








int	is_wall_in_point(char **map, t_vector point)
{
	int	x;
	int	y;

	x = fmod(point.x, (float) GAMEBOXSIZE);
	y = fmod(point.y, (float) GAMEBOXSIZE);
	if (map && map[y] && map[y][x] == '1')
		return (1);
	return (0);

}


int	is_out_of_border_map(char **map, t_vector point)
{
	if (point.x < 0 || point.y < 0 || point.y > strarr_len(map) || point.x > ft_strlen(map[(int)point.y]))
		return (1);
	return (0);
}



t_vector	find_intersection_points(t_data *data, float angle_ray)
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
	axis_step.x = axis_step.y / tan(angle_ray);
	axis_point.x = data->pl.poz.x + (data->pl.poz.y - axis_point.y) * tan(angle_ray);

	if (cos(angle_ray) > 0)
	{
		ordinat_point.x = floor(data->pl.poz.x / GAMEBOXSIZE) * GAMEBOXSIZE + GAMEBOXSIZE;
		ordinat_step.x = GAMEBOXSIZE;
	}
	else
	{
		ordinat_point.x = floor(data->pl.poz / GAMEBOXSIZE) * GAMEBOXSIZE - 1;
		ordinat_step.x = -GAMEBOXSIZE;
	}
	ordinat_step.y = ordinat_step.x * tan(angle_ray);
	ordinat_point.y = data->pl.poz.y + (data->pl.poz.x - ordinat_point.x) / tan(angle_ray);

	while (/* distance(data->pl.poz, axis_point, angle_ray) < SPACEVISIBLE && distance(data->pl.poz, ordinat_point, angle_ray) < SPACEVISIBLE */ \
			/* && !is_out_of_border_map(data->map, axis_point) && !is_out_of_border_map(data->map, ordinat_point) */
			1)
	{
		if (distance(data->pl.poz, ordinat_point, angle_ray) < distance(data->pl.poz, axis_point, angle_ray))
		{
			ordinat_point = sum_vectors(ordinat_point, ordinat_step);
			if (is_wall_in_point(data->map, ordinat_point))
				return (ordinat_point);
		}
		else
		{
			axis_point = sum_vectors(axis_point, axis_step);
			if (is_wall_in_point(data->map, axis_point))
				return (axis_point);
		}
	}

}




void	ray_cast(t_data *data)
{
	float	angle_ray;
	t_vector	intersection_poin;
	// float	distance;
	// вычесление крайнего левого луча
	angle_ray = data->pl.direction - (FOV / 2);

	while (angle_ray < data->pl.direction + (FOV / 2))
	{
		intersection_poin = find_intersection_points(data, angle_ray);
	// расстояние
	// считаем высоту
	// получаем номер колонки
	// ОТРИСОВКА

		angle_ray += STEPANGLE;
	}



}


void game(char **map, t_textures textures)
{
	t_data	data;

	data.window.mlx = mlx_init();
	data.window.win = mlx_new_window(data.window.mlx, WIDTH, HEIGHT, "Cub3D");
	creat_window_img(&data.window);
	init_sides_img(&data.imgs, textures, data.window.mlx);
	data.map = map;
	// init pl poz

	// ray_cast();

	fill_floor_and_cell_window_img(&data.window.img, textures);
	paint_sample(&data);

	mlx_put_image_to_window(data.window.mlx, data.window.win, data.window.img.img, 0, 0);
	mlx_loop(data.window.mlx);
}