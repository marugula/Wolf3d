/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:57:42 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:56:59 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	size_t	len;
	char	*c;
	char	*sc;

	c = (char *) find;
	sc = (char *) s;
	if (*(c) != '\0')
	{
		len = ft_strlen(find);
		while (ft_strncmp (s, find, len) != 0)
		{
			sc = (char *) s;
			if (sc != c)
			{
				if (*sc++ == '\0' || slen-- < 1)
					return (0);
			}
			if (len > slen)
				return (0);
			s++;
		}
	}
	return ((char *) s);
}
