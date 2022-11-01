/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:46:47 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 15:19:42 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse_map.h"

int	check_first_or_last_line(char *line)
{
	char	*checked_line;
	char	*temp;

	checked_line = ft_strtrim(line, " ");
	if (checked_line == NULL)
		exit_error("Error check first or last line\n");
	temp = checked_line;
	while (*temp)
	{
		if (!(*temp == '1' || *temp == ' '))
		{
			free(checked_line);
			return (VALID_ERR);
		}
		temp++;
	}
	free(checked_line);
	return (0);
}

int	check_first_and_last_char(char	*str)
{
	char	*checked_line;
	int		ret_val;

	checked_line = ft_strtrim(str, " ");
	if (checked_line == NULL)
		exit_error("Error check first or last char\n");
	if (checked_line[0] != '1' || checked_line[0] != '1')
		ret_val = VALID_ERR;
	else
		ret_val = VALID_OK;
	free(checked_line);
	return (ret_val);
}

int	check_side_wals(char **map)
{
	while (*map != NULL)
	{
		if (check_first_and_last_char(*map) == VALID_ERR)
			return (VALID_ERR);
		map++;
	}
	return (VALID_OK);
}

int	check_symb_in_map(t_dot dot, char **map)
{
	if (map[dot.y][dot.x] == ' ' && \
			check_space_around_dot(dot, map) == VALID_ERR)
		return (VALID_ERR);
	if (map[dot.y][dot.x] == '0' && \
			check_zero_around_zero(dot, map) == VALID_ERR)
		return (VALID_ERR);
	if (map[dot.y][dot.x] == 'D' && \
			check_wall_around_door(dot, map) == VALID_ERR)
		return (VALID_ERR);
	if (is_allowed_ch(map[dot.y][dot.x]) == VALID_ERR)
		return (VALID_ERR);
	return (VALID_OK);
}

int	check_all_dot(char **map)
{
	t_dot	dot;
	int		count_players;

	dot.y = 0;
	count_players = 0;
	while (map[dot.y] != NULL)
	{
		dot.x = 0;
		while (map[dot.y][dot.x] != 0)
		{
			if (check_symb_in_map(dot, map) == VALID_ERR)
				return (VALID_ERR);
			if (is_player_ch(map[dot.y][dot.x]))
				count_players++;
			dot.x++;
		}
		dot.y++;
	}
	if (count_players == 1)
		return (VALID_OK);
	else
		return (VALID_ERR);
}
