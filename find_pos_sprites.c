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
			if (map[(int)poz.y][(int)poz.x] == 'C' || map[(int)poz.y][(int)poz.x] == 'M' || map[(int)poz.y][(int)poz.x] == 'D')
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

	new_sprite.poz = poz;
	new_sprite.tex = tex;
	new_sprite.is_door = is_door;
	new_sprite.frame = random() % 6 + 1;
	new_sprite.animation_dir = 1;
	return (new_sprite);
}

void	find_pos_sprites(t_data *data)
{
	t_vector	poz;
	int			count;

	data->sprites = NULL;
	count = count_sprites_in_map(data->map);
	if (count == 0)
		return ;
	data->sprites = (t_sprite *) ft_calloc (count + 1, sizeof(t_sprite));
	if (!data->sprites)
		exit_error("error ft_calloc sprites\n");
	poz.y = 0;
	count = 0;
	while (data->map[(int)poz.y])
	{
		poz.x = 0;
		while (data->map[(int)poz.y][(int)poz.x])
		{
			if (data->map[(int)poz.y][(int)poz.x] == 'C')
				data->sprites[count++] = init_new_sprite(init_vector(poz.x * GAMEBOXSIZE + GAMEBOXSIZE / 2, poz.y * GAMEBOXSIZE + GAMEBOXSIZE / 2), data->imgs.cat, IS_SPRITE);
			if (data->map[(int)poz.y][(int)poz.x] == 'M')
				data->sprites[count++] = init_new_sprite(init_vector(poz.x * GAMEBOXSIZE + GAMEBOXSIZE / 2, poz.y * GAMEBOXSIZE + GAMEBOXSIZE / 2), data->imgs.minotaur, IS_SPRITE);
			if (data->map[(int)poz.y][(int)poz.x] == 'D')
				data->sprites[count++] = init_new_sprite(init_vector(poz.x * GAMEBOXSIZE + GAMEBOXSIZE / 2, poz.y * GAMEBOXSIZE + GAMEBOXSIZE / 2), data->imgs.door, IS_DOOR);
			poz.x++;
		}
		poz.y++;
	}
	data->sprites[count].tex = NULL;
}
