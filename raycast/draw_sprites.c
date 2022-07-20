/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:23:12 by marugula          #+#    #+#             */
/*   Updated: 2022/07/20 16:24:36 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

t_slice_sp	*find_intersections_sprites(t_data *data, float angle, float dist_to_wall)
{
	int			i;
	int			slice_num;
	t_slice_sp	*slices;

	i = 0;
	slices = NULL;
	while (data->sprites && data->sprites[i].tex != NULL)
	{
		slice_num = check_intersection_sprite(data->sprites[i], angle);
		if (slice_num != -1 && data->sprites[i].dist_to_pl < dist_to_wall)
			slices = add_new_sprite_slice(slices, data->sprites[i], slice_num, init_player(data->pl.poz, angle));
		i++;
	}
	return (slices);
}

void	draw_slice_in_win(int x_win_poz, int y_win_poz, t_slice_sp slice, t_img_info *winimg)
{

	int					step;
	float				prop;
	unsigned int		color;
	int					height;

	height =  slice_height(slice.dist, slice.img->height);
	prop = (float) slice.img->height / (float) height;
	step = 0;
	while (step < height && y_win_poz + step < HEIGHT)
	{
		color = get_color_in_pixel(slice.num_slice, round(step * prop), *slice.img);
		if (color != 0 && color != 4278190080)
			change_pixel_in_img(x_win_poz, y_win_poz + step, winimg, color_shift(color, intensity((float) (GAMEBOXSIZE / 1.5) / (float) slice_height(slice.dist, GAMEBOXSIZE))));
		step++;
	}
}

void	draw_sprite_column(t_data *data, float angle, float dist_to_wall, int x_win_poz)
{
	t_slice_sp	*slice_lst;
	t_slice_sp	*temp;

	slice_lst = find_intersections_sprites(data, angle, dist_to_wall);
	if (slice_lst == NULL)
		return ;
	sort_slice_lst(slice_lst);
	temp = slice_lst;
	while (temp != NULL)
	{
		if (temp != NULL && temp->dist < dist_to_wall)
		{
			temp->dist = correct_distance(temp->dist, fabs(data->pl.direction - angle));
			draw_slice_in_win(x_win_poz, y_shift_poz_on_floor(*temp), *temp, &data->window.img);
		}
		temp = temp->next;
	}
	clear_slice_list(slice_lst);
}