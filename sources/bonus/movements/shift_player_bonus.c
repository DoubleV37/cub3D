/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:31:35 by jduval            #+#    #+#             */
/*   Updated: 2023/07/05 11:30:21 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <math.h>

void	move_left_right(t_data *data, t_player *player, t_dir dir)
{
	float	perp[2];
	float	way;
	float	x;
	float	y;

	way = 1.0f;
	perp[X] = -player->dir[Y];
	perp[Y] = +player->dir[X];
	if (dir == LEFTWARD)
		way = -1.0f;
	x = player->pos[X] + perp[X] * way * (player->speed / 1.3f);
	if (check_collide(data, x, player->pos[Y]) == false)
		player->pos[X] = x;
	y = player->pos[Y] + perp[Y] * way * (player->speed / 1.3f);
	if (check_collide(data, player->pos[X], y) == false)
		player->pos[Y] = y;
	player->indexs[X] = player->pos[X] / SIZE;
	player->indexs[Y] = player->pos[Y] / SIZE;
	return ;
}
