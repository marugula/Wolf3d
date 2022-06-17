/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:53:40 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:56:46 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*new_d;
	const char	*new_s;
	size_t		n;
	size_t		dlen;

	new_d = (char *) dst;
	new_s = (const char *) src;
	n = dstsize;
	while (n-- != 0 && *new_d != 0)
		new_d++;
	dlen = new_d - dst;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(new_s));
	while (*new_s != '\0')
	{
		if (n != 1)
		{
			*new_d++ = *new_s;
			n--;
		}
		new_s++;
	}
	*new_d = '\0';
	return (dlen + (new_s - src));
}
