/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:40:20 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:56:54 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*newstr;
	size_t	count;

	if (s == 0 || f == 0)
		return (0);
	str = (char *) s;
	newstr = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!newstr)
		return (0);
	count = 0;
	while (str[count] != '\0')
	{
		newstr[count] = (*f)(count, str[count]);
		count++;
	}
	newstr[count] = '\0';
	return (newstr);
}
