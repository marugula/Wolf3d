# include "cub3d.h"

unsigned int	get_color_in_pixel(int x, int y, t_img_info img)
{
	char	*dst;

	if (y < 0 || y >= img.height || x < 0 || x >= img.width)
		return (0);
	dst = img.addr + (y * img.size_line + x * (img.bits_p_pix / 8));
	return (*(unsigned int*)dst);
}

void	change_pixel_in_img(int x, int y, t_img_info *img, unsigned int color)
{
	char	*dst;

	if (y < 0 || y >= img->height || x < 0 || x >= img->width || color == 4278190080)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bits_p_pix / 8));
	*(unsigned int*)dst = color;
}

unsigned int color_shift(int color, float intensive)
{
	unsigned int r = (color >> 16) * intensive;
	unsigned int b = ((color >> 8) & 0x00FF) * intensive;
	unsigned int g = (color & 0x0000FF) * intensive;
	unsigned int newColor = g | (b << 8) | (r << 16);
	return (newColor);
}

float	intensity(float prop)
{
	if (prop > 1)
		return (0);
	if (prop < 0)
		return (1);
	return (1 - prop);
}



void	draw_wall_column(int x_poz, int num_column, int heigth, t_img_info *winimg, t_img_info texture)
{
	int					mid_window;
	int					step;
	float				prop;
	int					img_poz;
	unsigned int		color;

	prop = (float) texture.height / (float) heigth;
	mid_window = HEIGHT / 2;
	step = 0;
	while (step < heigth / 2 && step < HEIGHT / 2)
	{
		// printf("draw_wall_circle\n");
		img_poz = round((double) (heigth / 2 + step) * prop);
		color = get_color_in_pixel(num_column, img_poz, texture);
		if (color != 0 && color != 4278190080)
			change_pixel_in_img(x_poz, mid_window + step, winimg, color_shift(color, intensity((float) (GAMEBOXSIZE / 1.5) / (float) heigth)));
		img_poz = round((double) (heigth / 2 - step) * prop);
		color = get_color_in_pixel(num_column, img_poz, texture);
		if (color != 0 && color != 4278190080)
			change_pixel_in_img(x_poz, mid_window - step, winimg, color_shift(color, intensity((float) (GAMEBOXSIZE / 1.5) / (float) heigth)));
		step++;
	}
}


void	fill_floor_and_cell_window_img(t_img_info *img, t_textures textures)
{
	int		x;
	int		y;
	float	intesive;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		intesive = fabs((float) y - HEIGHT / 2) / (HEIGHT / 2);
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				change_pixel_in_img(x, y, img, color_shift(textures.ceilling, intesive));
			else
				change_pixel_in_img(x, y, img, color_shift(textures.floor, intesive));
			x++;
		}
		y++;
	}
}
