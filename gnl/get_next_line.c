#include "get_next_line.h"

char	*get_line(char *remainder)
{
	int		i;
	char	*line;

	if (!remainder)
		return (NULL);
	i = find_index_of_char(remainder, '\n');
	line = (char *) malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_remainder(char *save)
{
	int		i;
	int		j;
	char	*remainder;

	i = find_index_of_char(save, '\n');
	if (!save[i] || !save[i + 1])
	{
		free(save);
		return (NULL);
	}
	remainder = (char *)malloc(sizeof(char) * (ft_strlen1(save) - i + 1));
	if (!remainder)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		remainder[j++] = save[i++];
	remainder[j] = '\0';
	free(save);
	return (remainder);
}

char	*reading_one_line(int fd, char *remainder)
{
	char	buff[BUFFER_SIZE + 1];
	int		read_bytes;

	read_bytes = 1;
	while (!check_char_in_line(remainder, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		if (read_bytes == 0)
			return (remainder);
		buff[read_bytes] = '\0';
		remainder = join_lines(remainder, buff);
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = reading_one_line(fd, remainder);
	if (!remainder)
		return (NULL);
	line = get_line(remainder);
	if (!line)
		return (NULL);
	remainder = get_remainder(remainder);
	return (line);
}
