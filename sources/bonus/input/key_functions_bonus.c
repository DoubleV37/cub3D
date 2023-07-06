/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 08:44:08 by jduval            #+#    #+#             */
/*   Updated: 2023/07/06 16:42:41 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "MLX42.h"

static void	movement_key(t_data *data);
static void	set_bool_key(t_data *data, int type);

void	modifier_inputs(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.action != MLX_RELEASE)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
	else if (data->there_is_door == true && keydata.key == MLX_KEY_F)
		door_control(data);
	else if (keydata.key == MLX_KEY_LEFT_ALT)
		set_bool_key(data, 1);
	else if (keydata.key == MLX_KEY_TAB)
		set_bool_key(data, 0);
}

void	user_inputs(void *param)
{
	t_data	*data;

	data = param;
	door_animation(data->doors, data->door_frames);
	movement_key(data);
	mouse_control(data);
	raycasting(data, &data->player);
	if (data->img[MAP]->enabled == true)
		put_minimap(data, &data->minimap);
	return ;
}

static void	set_bool_key(t_data *data, int type)
{
	if (type == 1)
	{
		if (data->mouse == true)
		{
			data->mouse = false;
			mlx_set_cursor_mode(data->mlx, 0x00034001);
		}
		else
		{
			data->mouse = true;
			mlx_set_cursor_mode(data->mlx, 0x00034002);
			mlx_set_mouse_pos(data->mlx, WIDTH / 2, HEIGHT / 2);
		}
	}
	else
	{
		if (data->img[MAP]->enabled == true)
			data->img[MAP]->enabled = false;
		else
			data->img[MAP]->enabled = true;
	}
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
