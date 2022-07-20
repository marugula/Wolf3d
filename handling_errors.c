/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:47:46 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 10:47:47 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	return_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

int	exit_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit (1);
}