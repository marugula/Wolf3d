/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:54:52 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 16:01:51 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_str(char *is_s, char c)
{
	size_t	k;
	size_t	i;

	i = 0;
	k = 0;
	while (is_s[k] != '\0')
	{
		while (is_s[k] == c)
			k++;
		if (is_s[k] != c && is_s[k] != '\0')
			i++;
		while (is_s[k] != c && is_s[k] != '\0')
			k++;
	}
	return (i);
}

static int	ft_mallocfree(char **dest, int j)
{
	j--;
	while (j > 0)
	{
		free(dest[j - 1]);
		j--;
	}
	free(dest);
	return (-1);
}

static int	ft_mallocdest(char **dest, char *is_s, char c, size_t k)
{
	size_t	j;
	size_t	count;

	k = 0;
	j = 0;
	while (is_s[k] != '\0')
	{
		count = 0;
		while (is_s[k] == c)
			k++;
		if (is_s[k] == '\0')
			break ;
		j++;
		while (is_s[k] != c && is_s[k] != '\0')
		{
			count++;
			k++;
		}
		dest[j - 1] = (char *) ft_calloc((count + 1), sizeof(char));
		if (!dest[j - 1])
			return (ft_mallocfree(dest, j));
	}
	return (0);
}

static void	ft_writedest(char **dest, char *is_s, char c, size_t k)
{
	size_t	j;
	size_t	count;

	k = 0;
	j = 0;
	while (is_s[k] != '\0')
	{
		count = 0;
		while (is_s[k] == c)
			k++;
		if (is_s[k] == '\0')
			break ;
		j++;
		while (is_s[k] != c && is_s[k] != '\0')
		{
			dest[j - 1][count] = is_s[k];
			count++;
			k++;
		}
		dest[j - 1][count] = '\0';
	}
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	char	*is_s;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	is_s = (char *)s;
	i = ft_count_str(is_s, c);
	dest = 0;
	k = 0;
	j = 0;
	dest = (char **) malloc((i + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	if (ft_mallocdest(dest, is_s, c, k) == -1)
		return (NULL);
	ft_writedest(dest, is_s, c, k);
	dest[i] = 0;
	return (dest);
}
