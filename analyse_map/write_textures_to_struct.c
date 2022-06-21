#include "analyse_map.h"

int	ignore_spaces(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i] && ft_isspace(map_line[i]) == 1)
		i++;
	return (i);
}

int	determine_texture(char *map_line)
{
	int		rez_cmp;
	char	*names_textures[6];
	int		i;

	names_textures[0] = "NO ";
	names_textures[1] = "SO ";
	names_textures[2] = "WE ";
	names_textures[3] = "EA ";
	names_textures[4] = "F ";
	names_textures[5] = "C ";
	rez_cmp = -1;
	i = 0;
	while (i <= 5)
	{
		rez_cmp = ft_strncmp(map_line, names_textures[i], \
							ft_strlen(names_textures[i]));
		if (rez_cmp == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	is_line_texture(char *map_line)
{
	int	i;
	int	txtr_nbr;

	i = ignore_spaces(map_line);
	txtr_nbr = determine_texture(&map_line[i]);
	if (txtr_nbr == -1)
		exit_error("Error line texture format\n");
	return (txtr_nbr);
}

int	is_line_map(char *map_line)
{
	int	i;

	i = ignore_spaces(map_line);
	if (map_line[i] && ft_isdigit(map_line[i]))
		return (1);
	return (0);
}

void	save_one_texture(char *map_line, t_textures *textures, int txtr_nbr)
{
	if (txtr_nbr == NO)
		textures->north = clip_img_txtr_from_line(map_line, textures->north);
	if (txtr_nbr == SO)
		textures->south = clip_img_txtr_from_line(map_line, textures->south);
	if (txtr_nbr == WE)
		textures->west = clip_img_txtr_from_line(map_line, textures->west);
	if (txtr_nbr == EA)
		textures->east = clip_img_txtr_from_line(map_line, textures->east);
	if (txtr_nbr == F)
		textures->floor = save_color_texture(map_line, textures->floor);
	if (txtr_nbr == C)
		textures->ceilling = save_color_texture(map_line, textures->ceilling);
}
