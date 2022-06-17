/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:36:20 by tamchoor          #+#    #+#             */
/*   Updated: 2022/04/27 11:46:42 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	num;
	void	*addr;

	num = count * size;
	addr = malloc(num);
	if (addr)
	{
		ft_memset(addr, 0, num);
	}
	return (addr);
}
