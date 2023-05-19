/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:45:12 by jduval            #+#    #+#             */
/*   Updated: 2023/05/18 17:28:59 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static bool check_collide(t_data *data, t_player *player, int inc_x, int inc_y);
static bool	hit_obstacle(t_data *data, t_player *player, t_dir dir);

int	move_player(t_data *data, t_player *player, t_dir dir)
{
	int	old_pos[2];

	old_pos[X] = player->pos[X];
	old_pos[Y] = player->pos[Y];
	if (hit_obstacle(data, player, dir) == true)
		return (0);
	draw_player(data->img[PLAYER], old_pos, data->setup.unit, 0);
	draw_player(data->img[PLAYER], player->pos, data->setup.unit, 1);
	return (0);
}
static bool	hit_obstacle(t_data *data, t_player *player, t_dir dir)
{
	int		pace;
	bool	flag;

	flag = false;
	pace = player->pace;
	if (dir == FORWARD)
		flag = check_collide(data, player, 0, pace * (-1));
	else if (dir == BACKWARD)
		flag = check_collide(data, player, 0, pace);
	else if (dir == LEFTWARD)
		flag = check_collide(data, player, pace * (-1), 0);
	else
		flag = check_collide(data, player, pace, 0);
	return (flag);
}

static bool check_collide(t_data *data, t_player *player, int inc_x, int inc_y)
{
	int	index[2];

	index[X] = (player->pos[X] + inc_x) / data->setup.unit;
	index[Y] = (player->pos[Y] + inc_y) / data->setup.unit;
	if (data->map[index[Y]][index[X]] != '0')
		return (true);
	player->pos[X] += inc_x;
	player->pos[Y] += inc_y;
	return (false);
}
