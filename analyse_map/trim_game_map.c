/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_game_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:26:53 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 11:27:50 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse_map.h"

int	find_start_map(char **map)
{
	int	i;
	int	first_line_map_index;

	first_line_map_index = 0;
	while (map && map[first_line_map_index] != NULL)
	{
		i = ignore_spaces(map[first_line_map_index]);
		if (map[first_line_map_index][i] == '1' || \
			map[first_line_map_index][i] == '0')
			return (first_line_map_index);
		first_line_map_index++;
	}
	return (-1);
}

char	**trim_map(char **map)
{
	char	**game_map;
	int		size_arr;
	int		index_first_line;
	int		i;

	index_first_line = find_start_map(map);
	if (index_first_line == -1)
		return (NULL);
	size_arr = strarr_len(&map[index_first_line]);
	game_map = ft_calloc(size_arr + 1, sizeof(char *));
	if (game_map == NULL)
		exit_error("Error ft_calloc in trim_map\n");
	i = 0;
	while (map[index_first_line + i] != NULL)
	{
		game_map[i] = ft_strdup(map[index_first_line + i]);
		i++;
	}
	return (game_map);
}
