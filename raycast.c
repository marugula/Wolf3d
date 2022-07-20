/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:05:28 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 12:06:04 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		axis.point.y = floor(data->pl.poz.y / GAMEBOXSIZE) \
											* GAMEBOXSIZE - 0.001;
		axis.step.y = -GAMEBOXSIZE;
	}
	else
	{
		axis.point.y = floor(data->pl.poz.y / GAMEBOXSIZE) \
										* GAMEBOXSIZE + GAMEBOXSIZE;
		axis.step.y = GAMEBOXSIZE;
	}
	axis.step.x = GAMEBOXSIZE / fabs(tan(angle_ray));
	if (cos(angle_ray) < 0)
		axis.step.x *= -1;

	if (cos(angle_ray) < 0)
		axis.point.x = data->pl.poz.x - \
						fabs((data->pl.poz.y - axis.point.y) / tan(angle_ray));
	else
		axis.point.x = data->pl.poz.x + \
						fabs((data->pl.poz.y - axis.point.y) / tan(angle_ray));
	return (axis);
}

t_raycast	init_ordinat(t_data *data, float angle_ray)
{
	t_raycast	ordinat;

	if (cos(angle_ray) > 0)
	{
		ordinat.point.x = floor(data->pl.poz.x / GAMEBOXSIZE) \
											* GAMEBOXSIZE + GAMEBOXSIZE;
		ordinat.step.x = GAMEBOXSIZE;
	}
	else
	{
		ordinat.point.x = floor(data->pl.poz.x / GAMEBOXSIZE) \
											* GAMEBOXSIZE - 0.001;
		ordinat.step.x = -GAMEBOXSIZE;
	}
	ordinat.step.y = GAMEBOXSIZE * fabs(tan(angle_ray));
	if (sin(angle_ray) > 0)
		ordinat.step.y *= -1;
	if (sin(angle_ray) > 0)
		ordinat.point.y = data->pl.poz.y - \
					fabs((data->pl.poz.x - ordinat.point.x) * tan(angle_ray));
	else
		ordinat.point.y = data->pl.poz.y + \
					fabs((data->pl.poz.x - ordinat.point.x) * tan(angle_ray));
	return (ordinat);
}

t_img_info	texture_mapping(t_imgs imgs, float angle, int is_axis)
{
	if (is_axis)
	{
		if (sin(angle) > 0)
			return (imgs.south);
		else
			return (imgs.north);
	}
	else
	{
		if (cos(angle) > 0)
			return (imgs.west);
		else
			return (imgs.east);
	}
}

# define LEN_RAY 1500

t_vector	find_intersection_points(t_data *data, float angle_ray, int	*number_column, t_img_info *wall_texture)
{
	t_raycast	axis;
	t_raycast	ordinat;
	float		dist_ordnt;
	float		dist_axis;

	axis = init_axis(data, angle_ray);
	ordinat = init_ordinat(data, angle_ray);
	dist_ordnt = distance(data->pl.poz, ordinat.point, angle_ray);
	dist_axis = distance(data->pl.poz, axis.point, angle_ray);
	while (!(is_wall_in_point(data->map, ordinat.point) || \
			(dist_ordnt >= LEN_RAY)) || \
			!(is_wall_in_point(data->map, axis.point) || dist_axis >= LEN_RAY))
	{
		if (!is_wall_in_point(data->map, ordinat.point) && dist_ordnt < LEN_RAY)
			ordinat.point = sum_vectors(ordinat.point, ordinat.step);
		if (!is_wall_in_point(data->map, axis.point) && dist_axis < LEN_RAY)
			axis.point = sum_vectors(axis.point, axis.step);
		dist_ordnt = distance(data->pl.poz, ordinat.point, angle_ray);
		dist_axis = distance(data->pl.poz, axis.point, angle_ray);
		if (dist_ordnt > LEN_RAY && dist_axis > LEN_RAY)
			return (init_vector(-1, -1));
	}

	if (distance(data->pl.poz, ordinat.point, angle_ray) < distance(data->pl.poz, axis.point, angle_ray))
	{
		*number_column = nbr_of_slice_column(ordinat.point.y);
		*wall_texture = texture_mapping(data->imgs, angle_ray, 0);
		return (ordinat.point);
	}
	*number_column = nbr_of_slice_column(axis.point.x);
	*wall_texture = texture_mapping(data->imgs, angle_ray, 1);
	return (axis.point);
}

int	convet_rad_to_grad(float rad)
{
	return (rad * 180 / M_PI);
}

void	count_perp_dir_for_sprites(t_sprite *sprite, t_player pl)
{
	int	i;
	float	perp_dir;
	// float	temp;

	i = 0;
	while (sprite != NULL && sprite[i].tex != NULL)
	{
		if (sprite[i].is_door == IS_DOORAXIS)
		{
			if (sin(pl.direction) > 0)
				perp_dir = 0;
			else
				perp_dir = M_PI;
		}
		else if (sprite[i].is_door == IS_DOORORDINAT)
		{
			if (cos(pl.direction) < 0)
				perp_dir = M_PI / 2;
			else
				perp_dir = 3 * M_PI / 2 ;
		}
		else
			perp_dir = count_perp_angle(angle_between_two_dots(pl.poz, sprite[i].poz, pl.direction), -1);
		sprite[i].left_angle = angle_between_two_dots(pl.poz, shift_poz(sprite[i].poz, perp_dir + M_PI, sprite[i].tex->width), pl.direction);
		sprite[i].right_angle = angle_between_two_dots(pl.poz, shift_poz(sprite[i].poz, perp_dir, sprite[i].tex->width), pl.direction);
		// if (sprite[i].is_door && sprite[i].left_angle < sprite[i].right_angle)
		// {
		// 	temp = sprite[i].left_angle;
		// 	sprite[i].left_angle = sprite[i].right_angle;
		// 	sprite[i].right_angle = temp;
		// }
		sprite[i].dist_to_pl = distance_pyth(pl.poz, sprite[i].poz);
		i++;
	}
}

void	ray_cast(t_data *data)
{
	t_vector	intersection_point;
	float		angle_ray;
	int			num_column;
	int			x;
	t_img_info	wall_txtr;

	angle_ray = data->pl.direction + (FOV / 2);
	x = 0;
	count_perp_dir_for_sprites(data->sprites, data->pl);
	while (angle_ray > data->pl.direction - (FOV / 2) && x < data->window.img.width)
	{
		if (cos(angle_ray) == 0 || sin(angle_ray) == 0)
			intersection_point = find_intersection_points(data, angle_ray + STEPANGLE, &num_column, &wall_txtr);
		else
			intersection_point = find_intersection_points(data, angle_ray, &num_column, &wall_txtr);

		if (!(intersection_point.x == -1 && intersection_point.y == -1))
			draw_wall_column(x, num_column, (int) slice_height(correct_distance(distance(data->pl.poz, intersection_point, angle_ray), fabs(data->pl.direction - angle_ray)), wall_txtr.height), &data->window.img, wall_txtr);
		else
			intersection_point = init_vector(INFINITY, INFINITY);

		if (cos(angle_ray) == 0 || sin(angle_ray) == 0)
			draw_sprite_column(data, angle_ray + STEPANGLE, distance(data->pl.poz, intersection_point, angle_ray), x);
		else
			draw_sprite_column(data, angle_ray, distance(data->pl.poz, intersection_point, angle_ray), x);

		x++;
		angle_ray -= STEPANGLE;
	}

}