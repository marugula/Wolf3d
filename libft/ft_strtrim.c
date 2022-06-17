/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:40:06 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:57:06 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itisset(char const s1, char const *set)
{
	char	*setset;

	setset = (char *) set;
	while (*setset != '\0')
	{
		if (s1 == *setset)
			return (1);
		setset++;
	}
	return (0);
}

static size_t	ft_strlen_without_set(const char *s, const char *set)
{
	size_t	begins;
	size_t	lens;
	size_t	ends;

	begins = 0;
	lens = 0;
	while (ft_itisset(s[begins], set) != 0 && ft_strlen(s) > begins)
		begins++;
	if (ft_strlen(s) == begins)
	{
		return (0);
	}
	ends = ft_strlen(s) - 1;
	while (ft_itisset(s[ends], set) != 0)
		ends--;
	ends++;
	return (ends - begins);
}

static char	*ft_newdest(char *dest, char const *s1, char const *set)
{
	size_t	i;
	size_t	begins;
	size_t	ends;

	i = 0;
	begins = 0;
	while (ft_itisset(s1[begins], set) != 0 && ft_strlen(s1) > begins)
		begins++;
	ends = ft_strlen(s1) - 1;
	while (ft_itisset(s1[ends], set) != 0)
		ends--;
	ends++;
	while (begins < ends)
	{
		dest[i] = s1[begins];
		begins++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	lens1_without_set;

	if (s1 == 0)
		return (0);
	lens1_without_set = ft_strlen_without_set(s1, set);
	if (lens1_without_set == 0)
	{
		dest = (char *) ft_calloc(1, sizeof(char));
		return (dest);
	}
	dest = (char *) ft_calloc((lens1_without_set + 1), sizeof(char));
	if (!dest)
		return (0);
	ft_newdest(dest, s1, set);
	return (dest);
}
