/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:16:55 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:54:22 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_tab(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

static long	ft_minus(int c, unsigned int *ptr_i)
{
	int	minus;

	minus = 1;
	if (c == '-' || c == '+')
	{
		if (c == '-')
			minus = minus * (-1);
		(*ptr_i)++;
	}
	return (minus);
}

static unsigned int	ft_strlen_dig(const char *s)
{
	long unsigned int	count;

	count = 0;
	while (ft_isdigit(s[count]))
	{
		count++;
	}
	return (count);
}

static long
	ft_find_res(long res, unsigned int count,
		long minus, const char *str)
{
	if (count <= 19)
	{
		if (count == 19 && minus == 1
			&& ft_strncmp(str, "9223372036854775807", 19) > 0)
			res = 9223372036854775807L;
		else if (count == 19 && minus == -1
			&& ft_strncmp(str, "9223372036854775808", 19) > 0)
			res = -9223372036854775807L - 1L;
		else
		{
			while (ft_isdigit(*(str)))
			{
				res = res * 10 + *(str) - '0';
				(str)++;
			}
		}
	}
	if (count > 19)
	{
		if (minus == 1)
			res = 9223372036854775807L;
		if (minus == -1)
			res = -9223372036854775807L - 1L;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	long			minus;
	long			res;
	unsigned int	i;
	unsigned int	count;

	res = 0;
	i = 0;
	while (ft_tab(str[i]))
		i++;
	minus = ft_minus(str[i], &i);
	count = ft_strlen_dig(str + i);
	res = ft_find_res(res, count, minus, str + i);
	res = res * minus;
	return ((int) res);
}
