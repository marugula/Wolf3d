/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:28:16 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 11:28:20 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_index_of_char(char *str, char symbol)
{
	int	indx;

	indx = 0;
	while (str[indx] && str[indx] != symbol)
	{
		indx++;
	}
	return (indx);
}

size_t	ft_strlen1(char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*check_char_in_line(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen1(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*line_copy(char *dest, const char *src)
{
	int	count;

	count = 0;
	if (!(dest) || !src)
		return (dest);
	while (src[count])
	{
		dest[count] = src[count];
		count++;
	}
	return (dest);
}

char	*join_lines(char *str1, char *str2)
{
	int		i;
	int		c;
	char	*str;
	int		len_str1;

	if (!str1)
		len_str1 = 0;
	else
		len_str1 = ft_strlen1(str1);
	if (!str2)
		return (NULL);
	str = malloc((len_str1 + ft_strlen1(str2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	line_copy(str, str1);
	c = 0;
	i = len_str1;
	while (str2[c] != '\0')
		str[i++] = str2[c++];
	str[len_str1 + ft_strlen1(str2)] = '\0';
	free(str1);
	return (str);
}
