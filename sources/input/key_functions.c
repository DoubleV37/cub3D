/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 08:44:08 by jduval            #+#    #+#             */
/*   Updated: 2023/06/19 10:03:20 by vviovi           ###   ########.fr       */
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

static void	mouse_control(t_data *data)
{
	int32_t	x;
	int32_t	y;

	mlx_get_mouse_pos(data->mlx, &x, &y);
	mlx_set_mouse_pos(data->mlx, WIDTH / 2 , data->player.height);
	if (x > data->player.mouse_x)
	{
		rotate_player(data, &data->player, RIGHTWARD);
		raycasting(data, &data->player);
	}
	else if (x < data->player.mouse_x)
	{
		rotate_player(data, &data->player, LEFTWARD);
		raycasting(data, &data->player);
	}
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
	mouse_control(data);
	return (flag);
}
