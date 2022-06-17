/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:59:11 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:57:09 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	slen;
	size_t	new_len;

	if (s == 0)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	new = (char *)malloc(sizeof(*s) * (len + 1));
	slen = len;
	if (!new)
		return (0);
	while (len > 0 && *(s + start) != '\0')
	{
		*new = *(s + start);
		start++;
		new++;
		len--;
	}
	*new = '\0';
	return (new - slen);
}
