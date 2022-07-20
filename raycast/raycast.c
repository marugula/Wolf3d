/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:05:28 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 16:33:20 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycast.h"

void	count_perp_dir_for_sprites(t_sprite *sprite, t_player pl)
{
	int	i;
	float		perp_dir;
	t_vector	shift;
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
		sprite[i].left_angle = angle_between_two_dots(pl.poz, shift_poz(sprite[i].poz, perp_dir + M_PI,	sprite[i].tex[0].width), pl.direction);
		shift = shift_poz(sprite[i].poz, perp_dir, sprite[i].tex->width);
		sprite[i].right_angle = angle_between_two_dots(pl.poz, shift_poz(sprite[i].poz, perp_dir, sprite[i].tex->width), pl.direction);
		if (sprite[i].is_door && fabs(sprite[i].left_angle - sprite[i].right_angle) > M_PI)
			sprite[i].left_angle = sprite[i].right_angle;
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

	count_perp_dir_for_sprites(data->sprites, data->pl);
	x = 0;
	angle_ray = data->pl.direction + (FOV / 2);
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
