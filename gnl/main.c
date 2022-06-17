// #include "get_next_line.h"
// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("file", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		write(1, "ERR\n", 4);
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		write(1, line, ft_strlen1(line));
// 		write(1, "\n", 1);
// 		free(line);
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break;
		
// 	}
// 	write(1, "END\n", 4);
// 	return (0);
// }