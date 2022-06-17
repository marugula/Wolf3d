/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:16:50 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:56:43 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	lens1;
	size_t	lens2;
	size_t	i;

	if (s1 == 0 || s2 == 0)
		return (0);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	dest = (char *) ft_calloc((lens1 + lens2 + 1), sizeof(char));
	if (!dest)
		return (0);
	ft_memcpy(dest, s1, lens1);
	i = 0;
	while (lens2 > 0)
	{
		dest[lens1] = s2[i];
		lens2--;
		lens1++;
		i++;
	}
	dest[lens1] = '\0';
	return (dest);
}
