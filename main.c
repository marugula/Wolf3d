/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:36:13 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 12:36:20 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_textures	textures;
	char		**map;

	(void) argv;
	if (argc != 2)
	{
		return (return_error("ERROR\n"));
	}
	check_format_map(argv[1]);
	map = copy_map_to_array(argv[1], &textures);
	game(map, textures);

	return (0);
}
