/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:33:08 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 19:02:25 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	shift_x(t_vector pixel, t_player pl, int size_img, float size_cell)
{
	float	prop_shift;
	float	prop_size_icn;

	prop_shift = size_cell / GAMEBOXSIZE;
	prop_size_icn = size_img / (4 * size_cell);
	return (pl.poz.x * prop_shift + (pixel.x - size_img / \
			(2 * prop_size_icn)) * sin(pl.direction + M_PI) \
			- (pixel.y - size_img / \
			(2 * prop_size_icn)) * cos(pl.direction + M_PI));
}

float	shift_y(t_vector pixel, t_player pl, int size_img, float size_cell)
{
	float	prop_shift;
	float	prop_size_icn;

	prop_shift = size_cell / GAMEBOXSIZE;
	prop_size_icn = size_img / (4 * size_cell);
	return (pl.poz.y * prop_shift + (pixel.x - size_img / \
		(2 * prop_size_icn)) * cos(pl.direction + M_PI) + \
		(pixel.y - size_img / (2 * prop_size_icn)) * \
		sin(pl.direction + M_PI));
}

int	max_len(char **map)
{
	int	maxlen;
	int	i;

	i = 0;
	maxlen = 0;
	while (map && map[i])
	{
		if (maxlen < (int)ft_strlen(map[i]))
			maxlen = ft_strlen(map[i]);
		i++;
	}
	return (maxlen);
}

float	count_size_cell(char **map)
{
	int	maxlen;
	int	maxheight;

	maxlen = max_len(map);
	maxheight = strarr_len(map);
	if (maxlen > maxheight)
		return (MINIMAP_W / maxlen);
	return (MINIMAP_H / maxheight);
}
