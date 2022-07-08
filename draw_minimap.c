#include "cub3d.h"



void	draw_borders(t_img_info *win, float width, float heigth)
{
	t_vector	point;

	point = init_vector(0, 0);
	while (point.y < heigth)
	{
		change_pixel_in_img(point.x, point.y, win, 0xfffff);
		point.y++;
	}
	point = init_vector(width, 0);
	while (point.y < heigth)
	{
		change_pixel_in_img(point.x, point.y, win, 0xfffff);
		point.y++;
	}
	point = init_vector(0, 0);
	while (point.x < width)
	{
		change_pixel_in_img(point.x, point.y, win, 0xfffff);
		point.x++;
	}
	point = init_vector(0, heigth);
	while (point.x < width)
	{
		change_pixel_in_img(point.x, point.y, win, 0xfffff);
		point.x++;
	}
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


void	draw_cell(float size, t_vector poz, t_img_info *win)
{
	t_vector	i;

	i = poz;
	while (i.y < poz.y + size)
	{
		i.x = poz.x;
		while (i.x < poz.x + size)
		{
			change_pixel_in_img(i.x, i.y, win, 0x0);
			i.x++;
		}
		i.y++;
	}
}

void	draw_wall(t_data *data, float size_cell )
{
	t_vector	poz;

	poz = init_vector(0, 0);
	while (poz.y < strarr_len(data->map))
	{
		poz.x = 0;
		while (poz.x < (int)ft_strlen(data->map[(int)poz.y]))
		{
			if (data->map[(int)poz.y][(int)poz.x] == '1')
				draw_cell(size_cell, init_vector(poz.x * size_cell, poz.y * size_cell), &(data->window.img));
			poz.x++;
		}
		poz.y++;
	}
}

void	draw_player(t_vector pl_poz, float size_cell, t_img_info *win)
{
	float	prop;

	prop = size_cell / GAMEBOXSIZE;
	draw_cell(5, init_vector(pl_poz.x * prop, pl_poz.y * prop), win);
}

void	draw_ray(t_vector poz, float angle, float len, t_img_info *win)
{
	t_vector	point;

	point = poz;
	while (distance(point, poz, angle) < len)
	{
		printf("x = %f, y = %f angle = %f\n", poz.x , poz.y , angle);
		change_pixel_in_img(point.x, point.y, win, 0x0);
		point.x += cos(angle);
		point.y -= sin(angle);
	}
}





// void draw_player_icn(t_vector poz, float angle, t_img_info pl_icn,  t_img_info *win)
// {
// 	float	radius_rotate;
// 	float	angle_with_axis;
// 	int		x;
// 	int		y;

// 	y = 0;
// 	while (y < )


// }

void	draw_minimap(t_data *data)
{
	float		size_cell;


	size_cell = count_size_cell(data->map);
	draw_borders(&(data->window.img), max_len(data->map) * size_cell, strarr_len(data->map) * size_cell);
	draw_wall(data, size_cell);
	draw_player(data->pl.poz, size_cell, &data->window.img);
}