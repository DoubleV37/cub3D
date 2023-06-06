/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 08:44:08 by jduval            #+#    #+#             */
/*   Updated: 2023/06/05 11:53:43 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42.h"

void	key_input(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	else if (movement_key(data) == 0)
		return ;
	return ;
}

int	movement_key(t_data *data)
{
	int	flag;

	flag = 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W) == true)
	{
		flag = move_backward_forward(data, &data->player, FORWARD);
		raycasting(data, &data->player);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S) == true)
	{
		flag = move_backward_forward(data, &data->player, BACKWARD);
		raycasting(data, &data->player);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A) == true)
	{
		flag = move_left_right(data, &data->player, LEFTWARD);
		raycasting(data, &data->player);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D) == true)
	{
		flag = move_left_right(data, &data->player, RIGHTWARD);
		raycasting(data, &data->player);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) == true)
	{
		flag = rotate_player(data, &data->player, RIGHTWARD);
		raycasting(data, &data->player);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) == true)
	{
		flag = rotate_player(data, &data->player, LEFTWARD);
		raycasting(data, &data->player);
	}
	return (flag);
}
