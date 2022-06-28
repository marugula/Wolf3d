# include "cub3d.h"

typedef struct s_raycast
{
	t_vector	point;
	t_vector	step;
}	t_raycast;



int	is_wall_in_point(char **map, t_vector point)
{
	int	x;
	int	y;

	x = (int) floor(point.x / (float) GAMEBOXSIZE);
	y = (int) floor(point.y / (float) GAMEBOXSIZE);
	if (x < 0 || y < 0 || y >= strarr_len(map) || x >= (int)ft_strlen(map[y]))
		return (1);
	if (map && map[y] && map[y][x] == '1')
		return (1);
	return (0);
}


t_raycast	init_axis(t_data *data, float angle_ray)
{
	t_raycast	axis;

	if (sin(angle_ray) > 0)
	{
		axis.point.y = floor(data->pl.poz.y / GAMEBOXSIZE) * GAMEBOXSIZE - 1;
		axis.step.y = -GAMEBOXSIZE;
	}
	else
	{
		axis.point.y = floor(data->pl.poz.y / GAMEBOXSIZE) * GAMEBOXSIZE + GAMEBOXSIZE;
		axis.step.y = GAMEBOXSIZE;
	}
	axis.step.x = GAMEBOXSIZE / fabs(tan(angle_ray));
	if (cos(angle_ray) < 0)
		axis.step.x *= -1;

	if (cos(angle_ray) < 0)
		axis.point.x = data->pl.poz.x - fabs((data->pl.poz.y - axis.point.y) / tan(angle_ray));
	else
		axis.point.x = data->pl.poz.x + fabs((data->pl.poz.y - axis.point.y) / tan(angle_ray));
	return(axis);
}


t_raycast	init_ordinat(t_data *data, float angle_ray)
{
	t_raycast	ordinat;

	if (cos(angle_ray) > 0)
	{
		ordinat.point.x = floor(data->pl.poz.x / GAMEBOXSIZE) * GAMEBOXSIZE + GAMEBOXSIZE;
		ordinat.step.x = GAMEBOXSIZE;
	}
	else
	{
		ordinat.point.x = floor(data->pl.poz.x / GAMEBOXSIZE) * GAMEBOXSIZE - 1;
		ordinat.step.x = -GAMEBOXSIZE;
	}
	ordinat.step.y = GAMEBOXSIZE * fabs(tan(angle_ray));
	if (sin(angle_ray) > 0)
		ordinat.step.y *= -1;
	if (sin(angle_ray) > 0)
		ordinat.point.y = data->pl.poz.y - fabs((data->pl.poz.x - ordinat.point.x) * tan(angle_ray));
	else
		ordinat.point.y = data->pl.poz.y + fabs((data->pl.poz.x - ordinat.point.x) * tan(angle_ray));
	return (ordinat);
}


t_vector	find_intersection_points(t_data *data, float angle_ray, int	*number_column)
{
	t_raycast	axis;
	t_raycast	ordinat;

	axis = init_axis(data, angle_ray);
	ordinat = init_ordinat(data, angle_ray);
	while (!is_wall_in_point(data->map, ordinat.point) || !is_wall_in_point(data->map, axis.point))
	{
		if (!is_wall_in_point(data->map, ordinat.point))
			ordinat.point = sum_vectors(ordinat.point, ordinat.step);
		if (!is_wall_in_point(data->map, axis.point))
			axis.point = sum_vectors(axis.point, axis.step);
	}
	if (distance(data->pl.poz, ordinat.point, angle_ray) < distance(data->pl.poz, axis.point, angle_ray))
	{
		*number_column = nbr_of_slice_column(ordinat.point.y);
		return (ordinat.point);
	}
	*number_column = nbr_of_slice_column(axis.point.x);
	return (axis.point);
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