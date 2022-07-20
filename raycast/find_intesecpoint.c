/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intesecpoint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:32:53 by marugula          #+#    #+#             */
/*   Updated: 2022/07/20 16:56:26 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycast.h"

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