/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:00:33 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 12:24:49 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_loop_hook(t_data *data)
{
	init_control_key(data);
	mlx_hook(data->window.win, ON_KEYDOWN, 0, control_key_down, data);
	mlx_hook(data->window.win, ON_KEYUP, 0, control_key_up, data);
	mlx_hook(data->window.win, BUTTONMOVE, 0, mouse_move, data);
	mlx_loop_hook(data->window.mlx, redrawing, data);
	mlx_hook(data->window.win, ON_DESTROY, 0, deal_destroy, 0);
	mlx_loop(data->window.mlx);
}
