/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:10:03 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:56:12 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*new;
	char	*b;
	size_t	i;

	new = (char *) src;
	b = (char *) dest;
	if (b < new)
	{
		i = 0;
		while (i < len)
		{
			b[i] = new[i];
			i++;
		}
	}
	else if (b > new)
	{
		i = len;
		while (i > 0)
		{
			b[i - 1] = new[i - 1];
			i--;
		}
	}
	return (dest);
}
