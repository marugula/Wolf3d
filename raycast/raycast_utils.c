/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:15:49 by marugula          #+#    #+#             */
/*   Updated: 2022/07/20 16:15:50 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "raycast.h"

float	distance(t_vector point_from, t_vector point_to, float angle_ray)
{
	double	distance;

	distance = fabs((point_from.x - point_to.x) / cos (angle_ray));
	if (distance == 0)
		distance = fabs((point_from.y - point_to.y) / sin (angle_ray));
	return ((float) distance);
}

float	distance_pyth(t_vector point_from, t_vector point_to)
{
	return (sqrt(pow(point_from.x - point_to.x, 2) + pow(point_from.y - point_to.y, 2)));
}

float	correct_distance(float distance, float angle)
{
	return (fabs(distance * cos(angle)));
}

float	slice_height(float distance, int height_img)
{
	float	height;

	height = (float) height_img / distance * (float) PLANEDIST;
	return (height);
}

int	nbr_of_slice_column(float point)
{
	int	nbr;

	nbr = (int) floor(fmod(point, GAMEBOXSIZE));
	return (nbr);
}
