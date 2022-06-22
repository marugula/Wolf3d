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

float	find_intersection_point(t_data *data)
{
	// float	step_x;
	float	step_y;

	if (sin(data->pl.direction) > 1)
		step_y = GAMEBOXSIZE;
	else
		step_y = -GAMEBOXSIZE;

	return (0);
}




void	ray_cast(t_data *data)
{
	float	angle_ray;
	float	distance;
	// вычесление крайнего левого луча
	angle_ray = data->pl.direction - (FOV / 2);

	while (angle_ray < data->pl.direction)
	{
		distance =

		angle_ray += STEPANGLE;
	}



}


void game(char **map, t_textures textures)
{
	t_data			data;

	data.window.mlx = mlx_init();
	data.window.win = mlx_new_window(data.window.mlx, WIDTH, HEIGHT, "Cub3D");
	creat_window_img(&data.window);
	init_sides_img(&data.imgs, textures, data.window.mlx);
	data.map = map;


	fill_floor_and_cell_window_img(&data.window.img, textures);
	paint_sample(&data);

	mlx_put_image_to_window(data.window.mlx, data.window.win, data.window.img.img, 0, 0);
	mlx_loop(data.window.mlx);
}