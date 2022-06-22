#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <math.h>



typedef struct s_point
{
	float		x;
	float		y;
	float		z;
}	t_point;

typedef struct s_img_info
{
	void	*img;
	int		width;
	int		height;
	char	*addr;
	int		bits_p_pix;
	int		size_line;
	int		endian;
}	t_img_info;

typedef struct s_game_window
{
	void		*mlx;
	void		*win;
	t_img_info	img;
}	t_game_window;

# define HEIGHT			540
# define WIDTH			960


typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceilling;
}	t_textures;


typedef struct s_imgs
{
	t_img_info	north;
	t_img_info	south;
	t_img_info	west;
	t_img_info	east;
}	t_imgs;

typedef struct s_map_data
{
	char			**map;
	t_textures		texture;
	t_game_window	window;
	t_imgs			imgs;
}	t_data;

int	return_error(char *str);
int	exit_error(char *str);

int	check_format_map(char *map_name);
char **copy_map_to_array(char *map_name);

int	ft_isspace(char c);
int	ft_atoi_base(char *str, int base);


/* marugula game)))) */
void game();


int	init_game(void);


#endif