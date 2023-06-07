/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:45:12 by jduval            #+#    #+#             */
/*   Updated: 2023/06/07 14:58:04 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdbool.h>

int	move_backward_forward(t_data *data, t_player *player, t_dir dir)
{
	float	way;
	float	x;
	float	y;
	bool	collide[2];

	collide[X] = false;
	collide[Y] = false;
	way = 1.0f;
	draw_pov(data, player, 0);
	if (dir == BACKWARD)
		way = -1.0f;
	x = player->pos[X] + data->tools.dir[X] * way * player->speed;
	if (check_collide(data, player->pos, x, player->pos[Y]) == false)
		collide[X] = true;
	y = player->pos[Y] + data->tools.dir[Y] * way * player->speed;
	if (check_collide(data, player->pos, player->pos[X], y) == false)
		collide[Y] = true;
	if (collide[X] == true)
		player->pos[X] = x;
	if (collide[Y] == true)
		player->pos[Y] = y;
	draw_pov(data, player, 1);
	return (0);
}
