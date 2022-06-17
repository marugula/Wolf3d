/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:15:07 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 15:55:37 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_nbr(int i, long nbr)
{
	if (nbr < 0)
	{
		i++;
		nbr = nbr * (-1);
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static char	*ft_s_null(char *s)
{
	s = (char *) ft_calloc (2, sizeof(char));
	s[0] = '0';
	s[1] = '\0';
	return (s);
}

static char	*ft_new_s(char *s, int i, long nbr, int minus)
{
	if (nbr < 0)
		nbr = nbr * (-1);
	s[i] = '\0';
	i--;
	while (i > 0 || (minus != -1 && i >= 0))
	{
		s[i] = (char)(nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	if (minus == -1)
		s[0] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		minus;
	long	nbr;
	int		i;

	nbr = (long) n;
	s = 0;
	minus = 1;
	if (nbr < 0)
		minus = (-1);
	if (nbr == 0)
		return (ft_s_null(s));
	i = 0;
	i = ft_len_nbr(i, nbr);
	s = (char *) ft_calloc((i + 1), sizeof(char));
	if (!s)
		return (0);
	s = ft_new_s(s, i, nbr, minus);
	return (s);
}
