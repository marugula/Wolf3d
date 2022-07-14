
#include "cub3d.h"

t_vector	sum_vectors(t_vector a, t_vector b)
{
	t_vector	new;

	new.x = a.x + b.x;
	new.y = a.y + b.y;
	return (new);
}

float	distance(t_vector point_from, t_vector point_to, float angle_ray)
{
	double	distance;

	distance = fabs(fabs(point_from.x - point_to.x) / cos (angle_ray));
	return ((float) distance);
}

float	distance_pyth(t_vector point_from, t_vector point_to)
{
	return (sqrt(pow(point_from.x - point_to.x, 2) + pow(point_from.y - point_to.y, 2)));
}

float	slice_height(float distance)
{
	float	height;

	height = (float) GAMEBOXSIZE / distance * (float) PLANEDIST;
	return (height);
}


int	nbr_of_slice_column(float point)
{
	int	nbr;

	nbr = (int) floor(fmod(point, GAMEBOXSIZE));
	return (nbr);
}

float	correct_distance(float distance, float angle)
{
	return (fabs(distance * cos(angle)));
}