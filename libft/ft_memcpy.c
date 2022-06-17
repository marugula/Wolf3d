/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:34:05 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:56:09 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*new;
	char	*b;
	size_t	count;

	count = 0;
	new = (char *) src;
	b = (char *) dest;
	if (new == b)
		return (dest);
	while (count < n)
	{
		b[count] = new[count];
		count++;
	}
	return (dest);
}
