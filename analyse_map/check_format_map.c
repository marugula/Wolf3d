/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:44:01 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/19 13:44:02 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse_map.h"

int	check_format_map(char *map_name)
{
	int	len_of_name;
	int	res_of_check;

	len_of_name = ft_strlen(map_name);
	res_of_check = ft_strncmp(&map_name[len_of_name - 4], ".cub", 4);
	if (res_of_check != 0 || len_of_name == 4)
		exit_error("Error map format\n");
	return (0);
}