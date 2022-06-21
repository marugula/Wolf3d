#include "analyse_map.h"

void	set_default_textures(t_textures *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = -1;
	textures->ceilling = -1;
}

void	fill_struct_textures(char **map_array, t_textures *textures)
{
	int	i;
	int	txtr_nbr;

	i = 0;
	while (map_array[i] && is_line_map(map_array[i]) == 0)
	{
		txtr_nbr = is_line_texture(map_array[i]);
		save_one_texture(map_array[i], textures, txtr_nbr);
		i++;
	}
}

void	check_all_textures_presented(t_textures *textures)
{
	if (textures->north == NULL || textures->south == NULL
		|| textures->west == NULL || textures->east == NULL
		|| textures->floor == -1 || textures->ceilling == -1)
		exit_error("error check_all_textures_presented\n");
}

t_textures	init_texture_struct(char **map_array)
{
	t_textures	textures;

	set_default_textures(&textures);
	fill_struct_textures(map_array, &textures);
	check_all_textures_presented(&textures);

	return (textures);
}