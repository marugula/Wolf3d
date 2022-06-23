#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <math.h>



# define HEIGHT			540
# define WIDTH			960
# define FOV			M_PI / 3
# define STEPANGLE		FOV / WIDTH
# define TANPI_6			0.57735026
# define PLANEDIST		( WIDTH / 2) / TANPI_6
# define GAMEBOXSIZE	64

# define SPACEVISIBLE	1000

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

typedef struct	s_two_dem_vector
{
	float	x;
	float	y;
} t_vector;

typedef struct	s_player_data
{
	t_vector	poz;
	float		direction;
} t_player;


typedef struct s_map_data
{
	char			**map;
	t_textures		texture;
	t_game_window	window;
	t_imgs			imgs;
	t_player		pl;
}	t_data;

int	return_error(char *str);
int	exit_error(char *str);

int	check_format_map(char *map_name);
char **copy_map_to_array(char *map_name, t_textures *textures);

int	ft_isspace(char c);
int	ft_atoi_base(char *str, int base);


/* marugula chainges))) */
void			game(char **map, t_textures textures);

/* init_imgs.c */
void			init_sides_img(t_imgs *imgs, t_textures texture, void *mlx_ptr);
void			init_img(t_img_info *img, char	*texture_path, void *mlx_ptr);
void			creat_window_img(t_game_window *mlx);

/* paint_engine.c */
unsigned int	get_color_in_pixel(int x, int y, t_img_info img);
void			change_pixel_in_img(int x, int y, t_img_info *img, unsigned int color);
void			set_column_in_img(int x_poz, int y_poz, int num_column, int heigth, t_img_info *winimg, t_img_info texture);
void			fill_floor_and_cell_window_img(t_img_info *img, t_textures textures);
unsigned int	color_shift(int color, float intensive);

/* analyse/utils.c */
int	strarr_len(char **arr);



int	init_game(void);


#endif