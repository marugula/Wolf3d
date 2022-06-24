#include "cub3d.h"









int	main(int argc, char **argv)
{
	t_textures	textures;
	char		**map;

	(void) argv;
	if (argc != 2)
	{
		return (return_error("ERROR\n"));
	}
	check_format_map(argv[1]);
	map = copy_map_to_array(argv[1], &textures);
	// init_game();
	game(map, textures);

	return (0);
}