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

	if (y < 0 || y >= img->height || x < 0 || x >= img->width)
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
	// printf("newColor = %x\n", newColor);
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

void	set_column_in_img(int x_poz, int num_column, int heigth, t_img_info *winimg, t_img_info texture)
{
	int		y;
	int		y_poz;
	float	prop;
	int		src_y;
	int		color;

	y_poz = HEIGHT / 2 - heigth / 2;
	y = 0;
	prop = (float) texture.height / (float) heigth;
	while (y < heigth)
	{
		src_y = round((double) y * prop);
		color = get_color_in_pixel(num_column, src_y, texture);
		if (color != 0)
			change_pixel_in_img(x_poz, y_poz + y, winimg, color_shift(color, intensity((float) (GAMEBOXSIZE / 1.5) / (float) heigth)));
		y++;
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
