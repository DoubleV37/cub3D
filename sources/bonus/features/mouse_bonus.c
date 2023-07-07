/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:41:23 by jduval            #+#    #+#             */
/*   Updated: 2023/07/07 09:14:23 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	mouse_control(t_data *data)
{
	int32_t	x;
	int32_t	y;

	if (data->mouse == true)
	{
		mlx_get_mouse_pos(data->mlx, &x, &y);
		mlx_set_mouse_pos(data->mlx, WIDTH / 2, HEIGHT / 2);
		if (x > WIDTH / 2)
			rotate_player(&data->player, RIGHTWARD);
		else if (x < WIDTH / 2)
			rotate_player(&data->player, LEFTWARD);
	}
}
