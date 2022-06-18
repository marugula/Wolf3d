#ifndef ANALYSE_MAP_H
# define ANALYSE_MAP_H

#include "../cub3d.h"

#include <fcntl.h>

int	check_format_map(char *map_name);
char	**init_array_map(void);
char	**add_new_line_in_array_map(char **map_array, int count_lines);


#endif