/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:49:29 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:56:04 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new;
	unsigned char	c2;
	size_t			i;

	new = (unsigned char *) s;
	c2 = (unsigned char) c;
	i = 0;
	while (n > i)
	{
		if (new[i] == c2)
		{
			return (new + i);
		}
		i++;
	}
	return (0);
}
