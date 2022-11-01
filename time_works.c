/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_works.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:48:22 by marugula          #+#    #+#             */
/*   Updated: 2022/07/20 18:56:35 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned long	get_time(void)
{
	struct timeval		tv;
	unsigned long		time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000000 + tv.tv_usec;
	return (time);
}

float	deltatime_sec(t_dt time)
{
	return ((float)(time.pres - time.prev) / (float)1000000);
}

float	deltatime_msec(t_dt time)
{
	return ((float)(time.pres - time.prev) / (float)1000);
}

void	rewrite_time(t_dt *time)
{
	time->prev = time->pres;
	time->pres = get_time();
}
