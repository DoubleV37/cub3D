/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:31:35 by jduval            #+#    #+#             */
/*   Updated: 2023/06/19 18:31:12 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	move_left_right(t_data *data, t_player *player, t_dir dir)
{
	float	perp[2];
	float	way;
	float	x;
	float	y;

	way = 1.0f;
	perp[X] = -data->tools.dir[Y];
	perp[Y] = +data->tools.dir[X];
	if (dir == LEFTWARD)
		way = -1.0f;
	x = player->pos[X] + perp[X] * way * player->speed;
	if (check_collide(data, player->pos, x, player->pos[Y]) == false)
		player->pos[X] = x;
	y = player->pos[Y] + perp[Y] * way * player->speed;
	if (check_collide(data, player->pos, player->pos[X], y) == false)
		player->pos[Y] = y;
	return ;
}
