#ifndef ANALYSE_MAP_H
# define ANALYSE_MAP_H

#include "../cub3d.h"

#include <fcntl.h>

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceilling;
}	t_textures;

int	check_format_map(char *map_name);
char	**init_array_map(void);
char	**add_new_line_in_array_map(char **map_array, int count_lines);
t_textures	init_texture_struct(char **map_array);

int	save_color_texture(char *map_line, int save_color);
char	*clip_img_txtr_from_line(char *map_line, char *save_txtr);
int	ignore_spaces(char *map_line);
int	is_line_texture(char *map_line);
int	is_line_map(char *map_line);
void	save_one_texture(char *map_line, t_textures *textures, int txtr_nbr);


# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5

#endif