#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "gnl/get_next_line.h"
# include <stdio.h>


#include <stdio.h>


typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceilling;
}	t_textures;

typedef struct s_map_data
{
	char		**map;
	t_textures	texture;
}	t_data;

int	return_error(char *str);
int	exit_error(char *str);

int	check_format_map(char *map_name);
char **copy_map_to_array(char *map_name);

int	ft_isspace(char c);
int	ft_atoi_base(char *str, int base);


#endif