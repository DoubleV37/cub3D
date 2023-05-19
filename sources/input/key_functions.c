/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 08:44:08 by jduval            #+#    #+#             */
/*   Updated: 2023/05/19 17:47:33 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42.h"

int	movement_key(t_data *data)
{
	int	flag;

	flag = 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W) == true)
		flag = move_backward_forward(data, &data->player, FORWARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S) == true)
		flag = move_backward_forward(data, &data->player, BACKWARD);
	//if (mlx_is_key_down(data->mlx, MLX_KEY_A) == true)
//		flag = move_player(data, &data->player, LEFTWARD);
//	if (mlx_is_key_down(data->mlx, MLX_KEY_D) == true)
//		flag = move_player(data, &data->player, RIGHTWARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) == true)
		flag = rotate_player(data, &data->player, RIGHTWARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) == true)
		flag = rotate_player(data, &data->player, LEFTWARD);
	return (flag);
}
