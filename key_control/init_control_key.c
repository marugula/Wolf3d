/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_control_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:51:18 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 10:33:32 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_control_key(t_data *data)
{
	data->key.direct = 0;
	data->key.y = 0;
	data->key.x = 0;
	data->key.mouse_move = 0;
}
