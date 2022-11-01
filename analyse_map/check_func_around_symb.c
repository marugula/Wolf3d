/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func_around_symb.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:35:20 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 11:37:01 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse_map.h"

int	check_wall_around_door(t_dot dot, char **map)
{
	char	ch_at_dot2;
	char	ch_at_dot1;
	char	ch_at_dot3;
	char	ch_at_dot4;

	ch_at_dot1 = get_ch_in_dot(dot.x - 1, dot.y, map);
	ch_at_dot2 = get_ch_in_dot(dot.x + 1, dot.y, map);
	ch_at_dot3 = get_ch_in_dot(dot.x, dot.y - 1, map);
	ch_at_dot4 = get_ch_in_dot(dot.x, dot.y + 1, map);
	if (ch_at_dot1 == '1' && ch_at_dot2 == '1'\
		&& (ch_at_dot3 == '0' || is_player_ch(ch_at_dot3)) \
		&& (ch_at_dot4 == '0' || is_player_ch(ch_at_dot4)))
		return (VALID_OK);
	if (ch_at_dot3 == '1' && ch_at_dot4 == '1'\
		&& (ch_at_dot1 == '0' || is_player_ch(ch_at_dot1)) \
		&& (ch_at_dot2 == '0' || is_player_ch(ch_at_dot2)))
		return (VALID_OK);
	return (VALID_ERR);
}

int	check_zero_around_zero(t_dot dot, char **map)
{
	char	ch_at_dot;

	ch_at_dot = get_ch_in_dot(dot.x - 1, dot.y, map);
	if (ch_at_dot == ' ' || ch_at_dot == 0)
		return (VALID_ERR);
	ch_at_dot = get_ch_in_dot(dot.x + 1, dot.y, map);
	if (ch_at_dot == ' ' || ch_at_dot == 0)
		return (VALID_ERR);
	ch_at_dot = get_ch_in_dot(dot.x, dot.y - 1, map);
	if (ch_at_dot == ' ' || ch_at_dot == 0)
		return (VALID_ERR);
	ch_at_dot = get_ch_in_dot(dot.x, dot.y + 1, map);
	if (ch_at_dot == ' ' || ch_at_dot == 0)
		return (VALID_ERR);
	return (VALID_OK);
}

int	check_space_around_dot(t_dot dot, char **map)
{
	char	ch_at_dot;

	ch_at_dot = get_ch_in_dot(dot.x - 1, dot.y, map);
	if (!(ch_at_dot == 0 || ch_at_dot == ' ' || ch_at_dot == '1'))
		return (VALID_ERR);
	ch_at_dot = get_ch_in_dot(dot.x + 1, dot.y, map);
	if (!(ch_at_dot == 0 || ch_at_dot == ' ' || ch_at_dot == '1'))
		return (VALID_ERR);
	ch_at_dot = get_ch_in_dot(dot.x, dot.y - 1, map);
	if (!(ch_at_dot == 0 || ch_at_dot == ' ' || ch_at_dot == '1'))
		return (VALID_ERR);
	ch_at_dot = get_ch_in_dot(dot.x, dot.y + 1, map);
	if (!(ch_at_dot == 0 || ch_at_dot == ' ' || ch_at_dot == '1'))
		return (VALID_ERR);
	return (VALID_OK);
}
