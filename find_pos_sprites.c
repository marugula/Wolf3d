/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:27:27 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/19 13:28:10 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_sprites_in_map(char **map)
{
	int			count;
	t_vector	poz;

	count = 0;
	poz.y = 0;
	while (map[(int)poz.y])
	{
		poz.x = 0;
		while (map[(int)poz.y][(int)poz.x])
		{
			if (map[(int)poz.y][(int)poz.x] == 'C' \
			|| map[(int)poz.y][(int)poz.x] == 'M' \
			|| map[(int)poz.y][(int)poz.x] == 'D')
			{
				count++;
			}
			poz.x++;
		}
		poz.y++;
	}
	return (count);
}


t_sprite	init_new_sprite(t_vector poz, t_img_info *tex, int is_door)
{
	t_sprite	new_sprite;

	new_sprite.poz = init_vector (poz.x * GAMEBOXSIZE + GAMEBOXSIZE / 2, \
									poz.y * GAMEBOXSIZE + GAMEBOXSIZE / 2);
	new_sprite.tex = tex;
	new_sprite.is_door = is_door;
	new_sprite.frame = random() % 6 + 1;
	new_sprite.animation_dir = 1;
	return (new_sprite);
}

int	find_door_direction(t_vector dot, char **map)
{
	char	ch_at_dot2;
	char	ch_at_dot1;

	ch_at_dot1 = get_ch_in_dot((int) dot.x - 1, (int) dot.y, map);
	ch_at_dot2 = get_ch_in_dot((int) dot.x + 1, (int) dot.y, map);
	if (ch_at_dot1 == '1' && ch_at_dot2 == '1')
		return (IS_DOORAXIS);
	return (IS_DOORORDINAT);
}

void	find_poz_for_sprites(t_data *data)
{
	t_vector	poz;
	int			count;

	poz.y = 0;
	count = 0;
	while (data->map[(int)poz.y])
	{
		poz.x = 0;
		while (data->map[(int)poz.y][(int)poz.x])
		{
			if (data->map[(int)poz.y][(int)poz.x] == 'C')
				data->sprites[count++] = \
				init_new_sprite (poz, data->imgs.cat, IS_SPRITE);
			if (data->map[(int)poz.y][(int)poz.x] == 'M')
				data->sprites[count++] = \
				init_new_sprite(poz, data->imgs.minotaur, IS_SPRITE);
			if (data->map[(int)poz.y][(int)poz.x] == 'D')
				data->sprites[count++] = init_new_sprite \
				(poz, data->imgs.door, find_door_direction(poz, data->map));
			poz.x++;
		}
		poz.y++;
	}
	data->sprites[count].tex = NULL;
}

void	init_sprites_struct(t_data *data)
{
	int			count;

	data->sprites = NULL;
	count = count_sprites_in_map(data->map);
	if (count == 0)
		return ;
	data->sprites = (t_sprite *) ft_calloc (count + 1, sizeof(t_sprite));
	if (!data->sprites)
		exit_error("error ft_calloc sprites\n");
	find_poz_for_sprites(data);
}
