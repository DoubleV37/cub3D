/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:31:35 by jduval            #+#    #+#             */
/*   Updated: 2023/05/22 17:21:06 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int	move_left_right(t_data *data, t_player *player, t_dir dir)
{
	float	perp[2];
	float	check[2];
	float	way;

	way = 1.0f;
	perp[X] = -player->vector[Y];
	perp[Y] = +player->vector[X];
	if (dir == LEFTWARD)
		way = -1.0f;
	check[X] = player->pos[X] + perp[X] * way * player->pace;
	check[Y] = player->pos[Y] + perp[Y] * way * player->pace;
	if (check_collide(check, data->setup.unit, data->map) == false)
	{
		draw_pov(data->img[PLAYER], player, 0);
		player->pos[X] += perp[X] * way * player->pace;
		player->pos[Y] += perp[Y] * way * player->pace;
		draw_pov(data->img[PLAYER], player, 1);
	}
	return (0);
}
