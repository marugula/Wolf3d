#include "analyse_map.h"

int	open_file_map(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_error("Error open file\n");
	return (fd);
}

int	is_line_empty(char *line)
{
	if (line[0] == '\0')
		return (1);
	return (0);
}

char	**fill_map_array(int fd)
{
	char	**map_array;
	char	*tmp_line;
	int		i;
	int		count_lines;

	map_array = init_array_map();
	count_lines = 2;
	tmp_line = get_next_line(fd);
	if (!tmp_line)
		exit_error("Error gnl\n");
	i = 0;
	while (tmp_line)
	{
		if (is_line_empty(tmp_line) == 0)
		{
			map_array[i] = tmp_line;
			i++;
			map_array = add_new_line_in_array_map(map_array, count_lines);
			count_lines++;
		}
		else
			free(tmp_line);
		tmp_line = get_next_line(fd);
	}
	return (map_array);
}

void	print_array_map(char **map_array)
{
	int	i = 0;

	while (map_array[i])
	{
		write(1, map_array[i], ft_strlen(map_array[i]));
		write(1, "\n", 1);
		i++;
	}
}

int	copy_map_to_array(char *map_name)
{
	int		fd;
	char	**map_array;

	fd = open_file_map(map_name);
	map_array = fill_map_array(fd);
	if (!map_array[0])
		exit_error("Error fill_map_array\n");
	print_array_map(map_array);
	return (0);
}
