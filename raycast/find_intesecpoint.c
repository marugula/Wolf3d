/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intesecpoint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:32:53 by marugula          #+#    #+#             */
/*   Updated: 2022/07/20 17:38:09 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

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

t_raycast	choose_vector( \
			t_raycast axis, t_raycast ordinat, t_data *data, float angle_ray)
{
	if (distance(data->pl.poz, ordinat.point, angle_ray) \
			< distance(data->pl.poz, axis.point, angle_ray))
	{
		return (ordinat);
	}
	return (axis);
}

t_vector	find_intersection_points(t_data *data, float angle_ray, \
				int	*number_column, t_img_info *wall_texture)
{
	t_raycast	axis;
	t_raycast	ord;
	float		dst_o;
	float		dist_axis;

	axis = init_axis(data, angle_ray);
	ord = init_ordinat(data, angle_ray);
	dst_o = distance(data->pl.poz, ord.point, angle_ray);
	dist_axis = distance(data->pl.poz, axis.point, angle_ray);
	while (!(is_wall_in_point(data->map, ord.point) || (dst_o >= LEN_RAY)) || \
			!(is_wall_in_point(data->map, axis.point) || dist_axis >= LEN_RAY))
	{
		if (!is_wall_in_point(data->map, ord.point) && dst_o < LEN_RAY)
			ord.point = sum_vectors(ord.point, ord.step);
		if (!is_wall_in_point(data->map, axis.point) && dist_axis < LEN_RAY)
			axis.point = sum_vectors(axis.point, axis.step);
		dst_o = distance(data->pl.poz, ord.point, angle_ray);
		dist_axis = distance(data->pl.poz, axis.point, angle_ray);
		if (dst_o > LEN_RAY && dist_axis > LEN_RAY)
			return (init_vector(-1, -1));
	}
	axis = choose_vector(axis, ord, data, angle_ray);
	*number_column = nbr_of_slice_column(axis.point.x);
	*wall_texture = texture_mapping(data->imgs, angle_ray, 1);
	return (axis.point);
}
