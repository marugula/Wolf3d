/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:45:22 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:56:07 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*ss1;
	unsigned char	*ss2;
	int				c;

	count = 0;
	ss1 = (unsigned char *) s1;
	ss2 = (unsigned char *) s2;
	while (count < n)
	{
		c = ss1[count] - ss2[count];
		if (c != 0)
		{
			return (c);
		}
		count++;
	}
	return (0);
}
