/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:32:47 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:54:25 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	char	*new;
	size_t	count;

	new = (char *) b;
	count = 0;
	while (count < len)
	{
		new[count] = '\0';
		count++;
	}
}
