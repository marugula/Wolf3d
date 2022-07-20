/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_engine_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:54:10 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 19:12:40 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_color_in_pixel(int x, int y, t_img_info img)
{
	char	*dst;

	if (y < 0 || y >= img.height || x < 0 || x >= img.width)
		return (0);
	dst = img.addr + (y * img.size_line + x * (img.bits_p_pix / 8));
	return (*(unsigned int *) dst);
}

void	change_pixel_in_img(int x, int y, t_img_info *img, unsigned int color)
{
	char	*dst;

	if (y < 0 || y >= img->height || x < 0 \
		|| x >= img->width || color == 4278190080)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bits_p_pix / 8));
	*(unsigned int *)dst = color;
}

unsigned int	color_shift(int color, float intensive)
{
	unsigned int	r;
	unsigned int	b;
	unsigned int	g;
	unsigned int	new_color;

	r = (color >> 16) * intensive;
	b = ((color >> 8) & 0x00FF) * intensive;
	g = (color & 0x0000FF) * intensive;
	new_color = g | (b << 8) | (r << 16);
	return (new_color);
}

float	intensity(float prop)
{
	if (prop > 1)
		return (0);
	if (prop < 0)
		return (1);
	return (1 - prop);
}
