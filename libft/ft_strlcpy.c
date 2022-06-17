/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:55:21 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:56:49 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	count;
	size_t	sz;

	count = 0;
	sz = ft_strlen(src);
	if (sz + 1 < n)
	{
		ft_memcpy(dest, src, sz + 1);
		dest[n - 1] = '\0';
	}
	else if (n != 0)
	{
		ft_memcpy(dest, src, n - 1);
		dest[n - 1] = '\0';
	}
	return (sz);
}
