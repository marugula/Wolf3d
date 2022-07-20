/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:58:37 by marugula          #+#    #+#             */
/*   Updated: 2022/07/20 17:53:29 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "../cub3d.h"

# define LEN_RAY 1500

# define NOTSORTED	0
# define SORTED		1

typedef struct s_raycast
{
	t_vector	point;
	t_vector	step;
}	t_raycast;

void		ray_cast(t_data *data);
/* draw_sprite.c */
void		draw_sprite_column( \
			t_data *data, float angle, float dist_to_wall, int x_win_poz);

/* find_intersecpoint.c */
t_vector	find_intersection_points( \
				t_data *data, float angle_ray, \
				int	*number_column, t_img_info *wall_texture);

/* slice_init.c */
t_slice_sp	*add_new_sprite_slice( \
				t_slice_sp *slices, t_sprite sprite, \
				int slice_num, t_player ray_info);

/* slicelst_utils.c */
void		*clear_slice_list(t_slice_sp *list);
int			slice_lst_is_sorted(t_slice_sp *slice_lst);
int			size_slice_lst(t_slice_sp *slice_lst);
void		swap_value_slice_list(t_slice_sp *slice1, t_slice_sp *slice2);
void		sort_slice_lst(t_slice_sp *slice_lst);

/* raycats_utils.c */
float		distance(t_vector point_from, t_vector point_to, float angle_ray);
float		distance_pyth(t_vector point_from, t_vector point_to);
float		slice_height(float distance, int height_img);
int			nbr_of_slice_column(float point);
float		correct_distance(float distance, float angle);


/* raycats_utils2.c */
int			is_wall_in_point(char **map, t_vector point);
float		count_perp_angle(float angle, int dir);
t_img_info	texture_mapping(t_imgs imgs, float angle, int is_axis);
t_vector	sum_vectors(t_vector a, t_vector b);
t_vector	shift_poz(t_vector poz, float angle, float shift);

/* raycats_utils3.c */
double		angle_between_two_dots(t_vector start, t_vector end, float pl_dir);
t_player	init_player(t_vector poz, float angle);
int			y_shift_poz_on_floor(t_slice_sp cat);
int			check_intersection_sprite(t_sprite sprite, double angle);

#endif