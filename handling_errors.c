#include "cub3d.h"

int	return_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

int	exit_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit (1);
}
