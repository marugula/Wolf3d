#ifndef ANALYSE_MAP_H
# define ANALYSE_MAP_H

#include "../cub3d.h"

# include <fcntl.h>


# define VALID_OK	0
# define VALID_ERR	1


/* check_format_map.c */
int		check_format_map(char *map_name);

/* init_array_map.c */
char	**init_array_map(void);
char	**add_new_line_in_array_map(char **map_array, int count_lines);

/* copy_map_to_array.c */
char	**copy_map_to_array(char *map_name);

/* check_game_map.c */
int	check_game_map(char **map);



#endif