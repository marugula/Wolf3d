/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:23:12 by marugula          #+#    #+#             */
/*   Updated: 2022/07/15 23:12:55 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define IMGSIZE 100

void	draw_black_column(int poz, int size, t_game_window *win)
{
	int	i;

	i = 0;
	while (i < size)
	{
		change_pixel_in_img(poz, i + HEIGHT / 2 - size / 2, &win->img, 0xffffff);
		i++;
	}
}

typedef struct s_slice_sprite_info
{
	float						dist;
	int							num_slice;
	t_img_info					*img;
	struct s_slice_sprite_info	*next;

}	t_slice_sp;


float	count_perp_angle(float angle, int dir)
{
	return (angle + dir * M_PI_2);
}

t_vector	shift_poz(t_vector poz, float angle, float shift)
{
	printf("\nbefore x = %f, y = %f\n", poz.x, poz.y);
	poz.x = poz.x + shift * cos(angle);
	poz.y = poz.y - shift * sin(angle);
	printf("after x = %f, y = %f\n", poz.x, poz.y);
	return (poz);
}

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

int	check_intersection_sprite(t_sprite sprite, double angle)
{
	double		left_angle;
	double		right_angle;
	double		angle_step;
	int			i;

	left_angle = sprite.left_angle;
	right_angle = sprite.right_angle;
	if (angle < left_angle && angle > right_angle)
	{
		angle_step = (left_angle - right_angle) / sprite.tex->width;
		// printf("angle_step = %f\n", angle_step);
		i = 0;
		while(!(angle < left_angle - i * angle_step && angle > left_angle - (i + 1) * angle_step) || left_angle - (i + 1) * angle_step < right_angle)
		{
			if (i > 100)
				printf("angle_step = %f left_wall = %f , right_wall = %f\n", angle_step, left_angle - i * angle_step, left_angle - (i + 1) * angle_step);
			i++;
		}
		return (i);
	}
	return(-1);
}

t_slice_sp	*add_new_sprite_slice(t_slice_sp *slices, float dist, t_img_info *img, int slice_num)
{
	t_slice_sp	*temp;

	temp = slices;
	if (slices == NULL)
	{
		slices =  ft_calloc(1, sizeof(t_slice_sp));
		slices->dist = dist;
		slices->img = img;
		slices->num_slice = slice_num;
		return (slices);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next =  ft_calloc(1, sizeof(t_slice_sp));
	temp->next->dist = dist;
	temp->next->img = img;
	temp->next->num_slice = slice_num;
	return (slices);
}


t_slice_sp	*find_intersections_sprites(t_data *data, float angle, float dist_to_wall)
{
	int			i;
	int			slice_num;
	t_slice_sp	*slices;

	i = 0;
	slices = NULL;
	dist_to_wall = 0;
	while (data->sprites && data->sprites[i].tex != NULL)
	{
		slice_num = check_intersection_sprite(data->sprites[i], angle);
		if (slice_num != -1)
		{
			slices = add_new_sprite_slice(slices, data->sprites[i].dist_to_pl, &(data->sprites[i].tex[data->sprites[i].frame]), slice_num);
		}
		i++;
	}
	return (slices);
}

void	draw_sprite_column(t_data *data, float angle, float dist_to_wall, int win_x_poz)
{
	t_slice_sp	*slice_lst;
	t_slice_sp	*temp;

	slice_lst = find_intersections_sprites(data, angle, dist_to_wall);
	temp = slice_lst;
	while (temp != NULL)
	{
		// printf("dist = %f, height = %f, num_slice = %d, left_angle = %f , right_angle = %f\n",\
		// 					temp->dist, slice_height(slice_lst->dist),\
		// 					temp->num_slice, data->sprites->left_angle, data->sprites->right_angle);
		if (temp != NULL && temp->dist < dist_to_wall)
			set_column_in_img(win_x_poz, temp->num_slice, slice_height(temp->dist), &data->window.img, *temp->img);
		temp = temp->next;
	}

}