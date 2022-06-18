#include "analyse_map.h"

int	get_hex_color(int r, int g, int b)
{
	int	rgb;

	//Надо посмотреть что потом нарисует mlx
	rgb = (r << 16) + (g << 8) + b;
	return (rgb);
}

int	find_one_color_in_rgb(char *map_line, int *i)
{
	char	tmp_line[4];
	int		indx;
	int		color;

	indx = 0;
	while (ft_isdigit(map_line[indx]))
	{
		tmp_line[indx] = map_line[indx];
		indx++;
	}
	tmp_line[indx] = '\0';
	color = ft_atoi(tmp_line);
	*i += indx + 1;
	return (color);
}

int	save_color_texture(char *map_line, int save_color)
{
	int	r;
	int	g;
	int	b;
	int	i;
	int	rgb;

	if (save_color != -1)
		exit_error("Error repeat texture instruction\n");
	i = ignore_spaces(map_line) + 1;
	i += ignore_spaces(&map_line[i]);
	r = find_one_color_in_rgb(&map_line[i], &i);
	g = find_one_color_in_rgb(&map_line[i], &i);
	b = find_one_color_in_rgb(&map_line[i], &i);
	rgb = get_hex_color(r, g, b);
	return (rgb);
}

char	*clip_img_txtr_from_line(char *map_line, char *save_txtr)
{
	int		i;
	int		count;
	char	*txtr_line;

	if (save_txtr)
		exit_error("Error repeat texture instruction\n");
	i = ignore_spaces(map_line) + 2;
	count = ignore_spaces(&map_line[i]);
	i = i + count;
	count = ft_strlen(&map_line[i]);
	txtr_line = (char *) ft_calloc (sizeof(char), count + 1);
	if (!txtr_line)
		exit_error("Error ft_calloc\n");
	count = 0;
	while (map_line[i] && ft_isspace(map_line[i]) == 0)
	{
		txtr_line[count++] = map_line[i++];
	}
	return (txtr_line);
}