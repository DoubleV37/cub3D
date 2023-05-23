/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:45:12 by jduval            #+#    #+#             */
/*   Updated: 2023/05/23 17:23:27 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

int	move_backward_forward(t_data *data, t_player *player, t_dir dir)
{
	float	way;
	float	next[2];

	way = 1.0f;
	if (dir == BACKWARD)
		way = -1.0f;
	next[X] = player->pos[X] + data->tools.dir[X] * way * player->speed;
	next[Y] = player->pos[Y] + data->tools.dir[Y] * way * player->speed;
	if (check_collide(next, data->tools.unit, data->map) == false)
	{
		draw_pov(data, player, 0);
		player->pos[X] = next[X];
		player->pos[Y] = next[Y];
		draw_pov(data, player, 1);
	}
	return (0);
}
