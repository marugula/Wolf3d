#include "analyse_map.h"

char	**init_array_map(void)
{
	char	**new_array;

	new_array = (char **) ft_calloc(sizeof(char *), 1 + 1);
	if (!new_array)
		exit_error("Error calloc");
	new_array[0] = NULL;
	new_array[1] = NULL;
	return (new_array);
}

char	**add_new_line_in_array_map(char **map_array, int count_lines)
{
	char	**new_array;
	int		i;

	new_array = (char **) ft_calloc(sizeof(char *), count_lines + 1);
	if (!new_array)
		exit_error("Error calloc");
	i = 0;
	while (map_array[i])
	{
		new_array[i] = map_array[i];
		i++;
	}
	free(map_array);
	return (new_array);
}
