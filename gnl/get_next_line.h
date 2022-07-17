#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
int		find_index_of_char(char *str, char symbol);
size_t	ft_strlen1(char *str);
char	*check_char_in_line(char *str, int c);
char	*join_lines(char *str1, char *str2);

#endif
