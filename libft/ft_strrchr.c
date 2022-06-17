/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:58:39 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:57:02 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	res;

	i = 0;
	res = -1;
	if (c == '\0')
	{
		while (s[i])
			i++;
		return ((char *)(&(s[i])));
	}
	while (s[i])
	{
		if (s[i] == (char)c)
			res = i;
		i++;
	}
	if (res == -1)
		return (NULL);
	return ((char *)(&(s[res])));
}
