/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:44:14 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/19 13:44:27 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse_map.h"

int	check_size_map(char **map)
{
	if (max_len(map) > MAX_W_MAP || \
		strarr_len(map) > MAX_H_MAP)
		return (VALID_ERR);
	return (VALID_OK);
}

int	check_game_map(char **map)
{
	if (strarr_len(map) < 3)
		return (VALID_ERR);
	if (check_size_map(map) == VALID_ERR || \
		check_first_or_last_line(map[0]) == VALID_ERR || \
		check_first_or_last_line(map[strarr_len(map) - 1]) == VALID_ERR || \
		check_side_wals(map) == VALID_ERR || \
		check_all_dot(map) == VALID_ERR)
		return (VALID_ERR);
	return (VALID_OK);
}
