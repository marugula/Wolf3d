/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:07:55 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/15 15:13:12 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_sprites_in_map(char **map)
{
	int			i;
	t_vector	poz;

	i = 0;
	poz.y = 0;
	while (map[(int)poz.y])
	{
		poz.x = 0;
		while (map[(int)poz.y][(int)poz.x])
		{
			if (map[(int)poz.y][(int)poz.x] == 'C')
			{
				i++;
			}
			if (map[(int)poz.y][(int)poz.x] == 'M')
			{
				i++;
			}
			poz.x++;
		}
		poz.y++;
	}
	return (i);
}

t_sprite	init_new_sprite(t_vector poz, t_img_info *tex)
{
	t_sprite	new_sprite;

	new_sprite.poz = poz;
	new_sprite.tex = tex;
	new_sprite.frame = 0;
	return (new_sprite);
}

void	find_pos_sprites(t_data *data)
{
	t_vector	poz;
	int			i;

	data->sprites = NULL;
	i = count_sprites_in_map(data->map);
	if (i == 0)
		return ;
	data->sprites = (t_sprite *) ft_calloc (i + 1, sizeof(t_sprite));
	if (!data->sprites)
		exit_error("error ft_calloc sprites\n");
	poz.y = 0;
	i = 0;
	while (data->map[(int)poz.y])
	{
		poz.x = 0;
		while (data->map[(int)poz.y][(int)poz.x])
		{
			if (data->map[(int)poz.y][(int)poz.x] == 'C')
				data->sprites[i++] = init_new_sprite(poz, data->imgs.cat);
			if (data->map[(int)poz.y][(int)poz.x] == 'M')
				data->sprites[i++] = init_new_sprite(poz, data->imgs.minotaur);
			poz.x++;
		}
		poz.y++;
	}
	data->sprites[i].tex = NULL;
}
