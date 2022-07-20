/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:26:05 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 11:26:18 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse_map.h"

int	open_file_map(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_error("Error open file\n");
	return (fd);
}

int	is_line_empty(char *line)
{
	if (line[0] == '\0')
		return (1);
	return (0);
}

char	**fill_map_array(int fd)
{
	char	**map_array;
	char	*tmp_line;
	int		i;
	int		count_lines;

	map_array = init_array_map();
	count_lines = 2;
	tmp_line = get_next_line(fd);
	if (!tmp_line)
		exit_error("Error gnl\n");
	i = 0;
	while (tmp_line)
	{
		if (is_line_empty(tmp_line) == 0)
		{
			map_array[i] = tmp_line;
			i++;
			map_array = add_new_line_in_array_map(map_array, count_lines);
			count_lines++;
		}
		else
			free(tmp_line);
		tmp_line = get_next_line(fd);
	}
	return (map_array);
}

void	*clear_arr_str(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (str);
}

char	**copy_map_to_array(char *map_name, t_textures *textures)
{
	int			fd;
	char		**map_array;
	char		**game_map;

	fd = open_file_map(map_name);
	map_array = fill_map_array(fd);
	if (!map_array[0])
		exit_error("Error fill_map_array\n");
	*textures = init_texture_struct(map_array);
	game_map = trim_map(map_array);
	clear_arr_str(map_array);
	if (game_map == NULL)
		exit_error("File have not map\n");
	if (check_game_map(game_map) == VALID_ERR)
		exit_error("Map incorect\n");
	return (game_map);
}
