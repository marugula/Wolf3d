#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		return (return_error("ERROR\n"));
	}
	check_format_map(argv[1]);
	copy_map_to_array(argv[1]);

	return (0);
}