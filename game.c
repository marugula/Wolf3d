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

t_vector	find_intersection_points(t_data *data, float angle_ray)
{
	t_vector	axis_point;
	t_vector	ordinat_point;
	t_vector	axis_step;
	t_vector	ordinat_step;

	if (sin(angle_ray) > 0)
	{
		axis_point.y = floor(data->pl.poz.y / 64) * 64;
		axis_step.y = -64;
	}
	else
	{
		axis_point.y = ceil(data->pl.poz.y / 64) * 64;
		axis_step.y = 64;
	}
	axis_step.x = axis_step.y / tan(angle_ray);

	if (cos(angle_ray) > 0)
	{
		ordinat_point.x = ceil(data->pl.poz.x / 64) * 64;
		ordinat_step.x = 64;
	}
	else
	{

	}




	return (axis_step);
}


float	disctance(t_vector point1, t_vector point2)
{


	return (float);
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