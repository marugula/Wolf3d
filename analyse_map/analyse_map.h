#ifndef ANALYSE_MAP_H
# define ANALYSE_MAP_H

#include "../cub3d.h"

# include <fcntl.h>

# define VALID_OK	0
# define VALID_ERR	1
# define MAX_W_MAP	300
# define MAX_H_MAP	300

typedef struct t_move_on_map
{
	int	x;
	int	y;
} t_dot;

/* check_format_map.c */
int			check_format_map(char *map_name);

/* check_game_map.c */
int			check_game_map(char **map);


/* trim_game_map.c */
char		**trim_map(char **map);


/* check_utils.c */
int			strarr_len(char **arr);
int			is_player_ch(char ch);
int			is_allowed_ch(char ch);
char		get_ch_in_dot(int x, int y, char **map);


/* checker_function.c */
int			check_all_dot(char **map);
int			check_side_wals(char **map);
int			check_first_or_last_line(char *line);


/* init_array_map.c */
char		**init_array_map(void);
char		**add_new_line_in_array_map(char **map_array, int count_lines);

/* init_texture_struct.c */
t_textures	init_texture_struct(char **map_array);

/* get_color_image_texture.c */
int			save_color_texture(char *map_line, int save_color);
char		*clip_img_txtr_from_line(char *map_line, char *save_txtr);

/* write_textures_to_struct.c */
int			ignore_spaces(char *map_line);
int			is_line_texture(char *map_line);
int			is_line_map(char *map_line);
void		save_one_texture(char *map_line, t_textures *textures, int txtr_nbr);



# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5

#endif
