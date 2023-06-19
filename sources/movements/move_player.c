/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:45:12 by jduval            #+#    #+#             */
/*   Updated: 2023/06/19 18:30:50 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdbool.h>

void	move_backward_forward(t_data *data, t_player *player, t_dir dir)
{
	float	way;
	float	x;
	float	y;

	way = 1.0f;
	if (dir == BACKWARD)
		way = -1.0f;
	x = player->pos[X] + data->tools.dir[X] * way * player->speed;
	if (check_collide(data, player->pos, x, player->pos[Y]) == false)
		player->pos[X] = x;
	y = player->pos[Y] + data->tools.dir[Y] * way  * player->speed;
	if (check_collide(data, player->pos, player->pos[X], y) == false)
		player->pos[Y] = y;
	return ;
}
