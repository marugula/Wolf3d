#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <math.h>

# define HEIGHT			540
# define WIDTH			960
# define FOV			M_PI / 2.9
# define STEPANGLE		FOV / WIDTH
# define TANPI_6		0.57735026
# define PLANEDIST		(WIDTH / 2) / TANPI_6
# define GAMEBOXSIZE	64

# define SPACEVISIBLE	1000


# define BUTTONPRESS		4
# define BUTTONRELEASE		5
# define BUTTONMOVE			6
# define ON_DESTROY			17
# define ON_KEYDOWN			2
# define ON_KEYUP			3



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

typedef struct s_key
{
	float		press_x;
	float		mouse_move;
	int			y;
	int			x;
	int			direct;
	// int			right;
}	t_key;

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
	t_key			key;
}	t_data;

int	return_error(char *str);
int	exit_error(char *str);

int	check_format_map(char *map_name);
char **copy_map_to_array(char *map_name, t_textures *textures);

int	ft_isspace(char c);
int	ft_atoi_base(char *str, int base);

t_player	init_player_direct_and_poz(char **map);



/* marugula chainges))) */
void			game(char **map, t_textures textures);

/* init_imgs.c */
void			init_sides_img(t_imgs *imgs, t_textures texture, void *mlx_ptr);
void			init_img(t_img_info *img, char	*texture_path, void *mlx_ptr);
void			creat_window_img(t_game_window *mlx);

/* paint_engine.c */
unsigned int	get_color_in_pixel(int x, int y, t_img_info img);
void			change_pixel_in_img(int x, int y, t_img_info *img, unsigned int color);
void			set_column_in_img(int x_poz, int num_column, int heigth, t_img_info *winimg, t_img_info texture);
void			fill_floor_and_cell_window_img(t_img_info *img, t_textures textures);
unsigned int	color_shift(int color, float intensive);


/* raycast_utils.c */
t_vector	sum_vectors(t_vector a, t_vector b);
float		distance(t_vector point_from, t_vector point_to, float angle_ray);
float		slice_height(float distance);
int			nbr_of_slice_column(float point);
float		correct_distance(float distance, float angle);

/* raycast.c */
void		ray_cast(t_data *data);
int			is_wall_in_point(char **map, t_vector point);



/* analyse/utils.c */
int	strarr_len(char **arr);
int	redrawing(t_data *data);



int	init_game(void);

enum e_keys
{
	a = 0,
	s,
	d,
	w = 13,
	left = 123,
	right,
	esc = 53
};

void	init_control_key(t_data *data);
int	deal_destroy(void);
int	control_pl_dir(t_data *data);
int	control_pl_poz(t_data *data);
int	control_key_down(int key, t_data *data);
int	control_key_up(int key, t_data *data);
int	mouse_move(int x, int y, t_data *data);

#endif