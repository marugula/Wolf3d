#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "gnl/get_next_line.h"
# include <sys/time.h>
# include <stdio.h>
# include <math.h>

# define HEIGHT			720
# define WIDTH			1080
# define FOV			(M_PI / 3)
# define STEPANGLE		FOV / WIDTH
# define TANPI_6		0.57735026
# define PLANEDIST		(WIDTH / 2) / TANPI_6
# define GAMEBOXSIZE	64

# define SPEED_MOUSE_MOVE	0.3
# define SPEED_PL_MOVE		200

# define SPACEVISIBLE	1000

# define MINIMAP_H		200
# define MINIMAP_W		250


# define BUTTONPRESS		4
# define BUTTONRELEASE		5
# define BUTTONMOVE			6
# define ON_DESTROY			17
# define ON_KEYDOWN			2
# define ON_KEYUP			3

# define ANIM_PERIOD		3

# define ISDOORAXIS			1
# define ISDOORORDINAT		2
# define ISSPRITE			0

# define IS_DOORAXIS	1
# define IS_DOORORDINAT	2
# define IS_SPRITE		0



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
	t_img_info	cat[8];
	t_img_info	door[8];
	t_img_info	minotaur[8];
	t_img_info	player_icn;
}	t_imgs;

typedef struct s_two_dem_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_player_data
{
	t_vector	poz;
	float		direction;
}	t_player;

typedef struct s_slice_sprite_info
{
	float						dist;
	int							num_slice;
	int							is_door;
	t_img_info					*img;
	struct s_slice_sprite_info	*next;

}	t_slice_sp;

typedef struct s_sprite
{
	t_vector	poz;
	t_img_info	*tex;
	int			is_door;
	int			frame;
	int			animation_dir;
	float		dist_to_pl;
	float		left_angle;
	float		right_angle;
}	t_sprite;

typedef	struct s_delta_time
{
	unsigned long	prev;
	unsigned long	pres;
}	t_dt;

typedef struct s_map_data
{
	char			**map;
	t_textures		texture;
	t_sprite		*sprites;
	t_game_window	window;
	t_imgs			imgs;
	t_player		pl;
	t_key			key;
	t_dt			time;
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
void			init_cat_imgs(t_data *data);
void			init_minotaur_imgs(t_data *data);
void			init_door_imgs(t_data *data);
t_game_window	init_game_window(void);




/* paint_engine.c */
unsigned int	get_color_in_pixel(int x, int y, t_img_info img);
void			change_pixel_in_img(int x, int y, t_img_info *img, unsigned int color);
void			set_column_in_img(int x_poz, int num_column, int heigth, t_img_info *winimg, t_img_info texture);
void			draw_wall_column(int x_poz, int num_column, int heigth, t_img_info *winimg, t_img_info texture);
void			fill_floor_and_cell_window_img(t_img_info *img, t_textures textures);
unsigned int	color_shift(int color, float intensive);

/* raycast_utils.c */
t_vector		sum_vectors(t_vector a, t_vector b);
float			slice_height(float distance, int height_img);
int				nbr_of_slice_column(float point);
float			correct_distance(float distance, float angle);
float			distance(t_vector point_from, t_vector point_to, float angle_ray);
float			distance_pyth(t_vector point_from, t_vector point_to);
float			intensity(float prop);
unsigned int	color_shift(int color, float intensive);



/* raycast.c */
void		ray_cast(t_data *data);
int			is_wall_in_point(char **map, t_vector point);
int			redrawing(t_data *data);

/* draw_minimap.c */
void		draw_minimap(t_data *data);
int			max_len(char **map);

/* draw_sprites.c */
void		draw_sprite_column(t_data *data, float angle, float dist_to_wall, int win_x_poz);
float		count_perp_angle(float angle, int dir);
double	angle_between_two_dots(t_vector start, t_vector end, float pl_dir);
t_vector	shift_poz(t_vector poz, float angle, float shift);

/* analyse/utils.c */
int			strarr_len(char **arr);


/* find_pos_sprites.c */
void	init_sprites_struct(t_data *data);

/* check_utils.c */
char		get_ch_in_dot(int x, int y, char **map);

/*init_loop_hook.c*/
void		init_loop_hook(t_data *data);

/* init_vector.c */
t_vector	init_vector(float x, float y);

/* time_works.c */
unsigned long	get_time(void);
float			deltatime_sec(t_dt time);
void			rewrite_time(t_dt *time);
float			deltatime_msec(t_dt time);

/* animation.c */
void			open_door_animation(t_sprite *door, t_vector pl);
void			sprite_animation(t_sprite *sprites, t_vector pl);



// int	init_game(void);

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