/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:11:38 by marugula          #+#    #+#             */
/*   Updated: 2022/07/20 17:39:45 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

double	angle_between_two_dots(t_vector start, t_vector end, float pl_dir)
{
	double	angle;

	angle = atan2(start.y - end.y, end.x - start.x);
	while (angle - pl_dir > M_PI)
		angle -= 2 * M_PI;
	while (angle - pl_dir < -M_PI)
		angle += 2 * M_PI;
	return (angle);
}

t_player	init_player(t_vector poz, float angle)
{
	t_player	ret;

	ret.direction = angle;
	ret.poz = poz;
	return (ret);
}

int	y_shift_poz_on_floor(t_slice_sp cat)
{
	return ((float)(HEIGHT + slice_height(cat.dist, GAMEBOXSIZE)) / 2 \
							- slice_height(cat.dist, cat.img->height));
}

int	check_intersection_sprite(t_sprite sprite, double angle)
{
	double		angle_step;
	int			i;

	angle_step = (sprite.left_angle - sprite.right_angle) / sprite.tex->width;
	if (angle < sprite.left_angle && angle > sprite.right_angle)
	{
		i = (int)floor((angle - sprite.right_angle) / angle_step);
		return (i);
	}
	return (-1);
}
