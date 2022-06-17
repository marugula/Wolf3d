/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:52:04 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:56:34 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	char			*new;
	unsigned char	cc;

	i = 0;
	cc = (unsigned char) c;
	new = (char *) s;
	if (new[i] == '\0' && cc == '\0')
		return (new);
	while (new[i] != cc)
	{
		i++;
		if (new[i] == '\0')
		{
			if (cc == '\0')
				return (new + i);
			return (0);
		}
	}
	return (new + i);
}
