/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 08:44:08 by jduval            #+#    #+#             */
/*   Updated: 2023/06/27 11:51:02 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42.h"

static void	movement_key(t_data *data);

void	user_inputs(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	movement_key(data);
	raycasting(data, &data->player);
	return ;
}

static void	movement_key(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W) == true)
		move_backward_forward(data, &data->player, FORWARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S) == true)
		move_backward_forward(data, &data->player, BACKWARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A) == true)
		move_left_right(data, &data->player, LEFTWARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D) == true)
		move_left_right(data, &data->player, RIGHTWARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) == true)
		rotate_player(&data->player, RIGHTWARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) == true)
		rotate_player(&data->player, LEFTWARD);
}
