/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:31:35 by jduval            #+#    #+#             */
/*   Updated: 2023/06/08 13:45:08 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int	move_left_right(t_data *data, t_player *player, t_dir dir)
{
	float	perp[2];
	float	check[2];
	float	way;
	bool	collide[2];

	way = 1.0f;
	perp[X] = -data->tools.dir[Y];
	perp[Y] = +data->tools.dir[X];
	if (dir == LEFTWARD)
		way = -1.0f;
	draw_pov(data, player, 0);
	check[X] = player->pos[X] + perp[X] * way * player->speed;
	if (check_collide(data, player->pos, check[X], player->pos[Y]) == false)
		collide[X] = true;
	check[Y] = player->pos[Y] + perp[Y] * way * player->speed;
	if (check_collide(data, player->pos, player->pos[X], check[Y]) == false)
		collide[Y] = true;
	if (collide[X] == true)
		player->pos[X] += perp[X] * way * player->speed;
	if (collide[Y] == true)
		player->pos[Y] += perp[Y] * way * player->speed;
	draw_pov(data, player, 1);
	return (0);
}
