/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:45:12 by jduval            #+#    #+#             */
/*   Updated: 2023/07/07 09:05:48 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	move_backward_forward(t_data *data, t_player *player, t_dir dir)
{
	float	way;
	float	x;
	float	y;

	way = 1.0f;
	if (dir == BACKWARD)
		way = -1.0f;
	x = player->pos[X] + player->dir[X] * player->speed * way;
	if (check_collide(data, x, player->pos[Y]) == false)
		player->pos[X] = x;
	y = player->pos[Y] + player->dir[Y] * player->speed * way;
	if (check_collide(data, player->pos[X], y) == false)
		player->pos[Y] = y;
	player->indexs[X] = player->pos[X] / (float)SIZE;
	player->indexs[Y] = player->pos[Y] / (float)SIZE;
	return ;
}
