/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:23:12 by marugula          #+#    #+#             */
/*   Updated: 2022/07/19 12:04:07 by tamchoor         ###   ########.fr       */
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
	poz.x = poz.x + shift * cos(angle);
	poz.y = poz.y - shift * sin(angle);
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

	double		angle_step;
	int			i;

	angle_step = (sprite.left_angle - sprite.right_angle) / sprite.tex->width;
	if (angle < sprite.left_angle && angle > sprite.right_angle)
	{
		i = (int)floor((angle - sprite.right_angle) / angle_step);
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

void	*clear_slice_list(t_slice_sp *list)
{
	t_slice_sp *temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	return (NULL);
}

# define NOTSORTED	0
# define SORTED		1

int	slice_lst_is_sorted(t_slice_sp *slice_lst)
{
	while (slice_lst && slice_lst->next)
	{
		if (slice_lst->dist < slice_lst->next->dist)
			return (NOTSORTED);
		slice_lst = slice_lst->next;
	}
	return (SORTED);
}

int	size_slice_lst(t_slice_sp *slice_lst)
{
	int	i;

	i = 0;
	while (slice_lst != NULL)
	{
		slice_lst = slice_lst->next;
		i++;
	}
	return (i);
}

void	swap_value_slice_list(t_slice_sp *slice1, t_slice_sp *slice2)
{
	t_slice_sp	temp;

	temp.dist = slice1->dist;
	temp.img = slice1->img;
	temp.num_slice = slice1->num_slice;
	slice1->dist = slice2->dist;
	slice1->img = slice2->img;
	slice1->num_slice = slice2->num_slice;
	slice2->dist =temp.dist;
	slice2->img =temp.img;
	slice2->num_slice =temp.num_slice;
}

void	sort_slice_lst(t_slice_sp *slice_lst)
{
	t_slice_sp	*iterator;

	while (slice_lst_is_sorted(slice_lst) != SORTED)
	{
		iterator = slice_lst;
		while (iterator->next != NULL)
		{
			if (iterator->dist < iterator->next->dist)
			{
				swap_value_slice_list(iterator, iterator->next);
			}
			iterator = iterator->next;
		}
	}
}

void	draw_slice_in_win(int x_win_poz, int y_win_poz, t_slice_sp slice, t_img_info *winimg)
{

	int					step;
	float				prop;
	unsigned int		color;
	int					height;

	height =  slice_height(slice.dist, slice.img->height);
	prop = (float) slice.img->height / (float) height;
	y_win_poz = (float)(HEIGHT + slice_height(slice.dist, GAMEBOXSIZE)) / 2 - height;
	step = 0;
	while (step < height && y_win_poz + step < HEIGHT)
	{
		color = get_color_in_pixel(slice.num_slice, round(step * prop), *slice.img);
		if (color != 0 && color != 4278190080)
			change_pixel_in_img(x_win_poz, y_win_poz + step, winimg, color_shift(color, intensity((float) (GAMEBOXSIZE / 1.5) / (float) slice_height(slice.dist, GAMEBOXSIZE))));
		step++;
	}
}

int		y_shift_poz_for_cats(t_slice_sp cat, float angle)
{
	float	correct_dist;

	correct_dist = correct_distance(cat.dist, angle);
	return ((float)(HEIGHT + slice_height(correct_dist, GAMEBOXSIZE)) / 2 \
												- slice_height(correct_dist, cat.img->height));
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
		// printf("draw_sprite_circle\n");
		if (temp != NULL && temp->dist < dist_to_wall)
			draw_slice_in_win(x_win_poz,y_shift_poz_for_cats(*temp, fabs(angle - data->pl.direction)), *temp, &data->window.img);
		temp = temp->next;
	}
	clear_slice_list(slice_lst);
}