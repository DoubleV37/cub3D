/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:31:35 by jduval            #+#    #+#             */
/*   Updated: 2023/06/07 14:56:24 by vviovi           ###   ########.fr       */
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
	perp[X] = -data->tools.dir[Y];
	perp[Y] = +data->tools.dir[X];
	if (dir == LEFTWARD)
		way = -1.0f;
	check[X] = player->pos[X] + perp[X] * way * player->speed;
	check[Y] = player->pos[Y] + perp[Y] * way * player->speed;
	if (check_collide(data, player->pos, check[X], check[Y]) == false)
	{
		draw_pov(data, player, 0);
		player->pos[X] += perp[X] * way * player->speed;
		player->pos[Y] += perp[Y] * way * player->speed;
		draw_pov(data, player, 1);
	}
	return (0);
}
