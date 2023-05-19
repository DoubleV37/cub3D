/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:45:12 by jduval            #+#    #+#             */
/*   Updated: 2023/05/19 17:47:31 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	move_backward_forward(t_data *data, t_player *player, t_dir dir)
{
	float	inc[2];
	int		way;

	way = 1;
	if (dir == BACKWARD)
		way = -1;
	inc[X] = calculate_incr_x(player) * way;
	inc[Y] = calculate_incr_y(player) * way;
	if (check_collide(player, inc, data->setup.unit, data->map) == true)
		return (0);
	draw_line(data->img[PLAYER], player->view, color_pixel(255, 255, 255, 0));
	draw_player(data->img[PLAYER], player, data->setup.unit, 0);
	player->pos[X] += inc[X];
	player->pos[Y] += inc[Y];
	player->view[X] = player->pos[X];
	player->view[Y] = player->pos[Y];
	player->view[X + 2] += inc[X];
	player->view[Y + 2] += inc[Y];
	draw_line(data->img[PLAYER], player->view, color_pixel(255, 255, 255, 255));
	draw_player(data->img[PLAYER], player, data->setup.unit, 1);
	return (0);
}

int	move_rightward_leftward(t_data *data, t_player *player, t_dir dir)
{
	float	inc[2];
	int		way;

	way = 1;
	if (dir == BACKWARD)
		way = -1;
	inc[X] = calculate_incr_x(player) * way;
	inc[Y] = calculate_incr_y(player) * way;
	if (check_collide(player, inc, data->setup.unit, data->map) == true)
		return (0);
	draw_line(data->img[PLAYER], player->view, color_pixel(255, 255, 255, 0));
	draw_player(data->img[PLAYER], player, data->setup.unit, 0);
	player->pos[X] += inc[X];
	player->pos[Y] += inc[Y];
	player->view[X] = player->pos[X];
	player->view[Y] = player->pos[Y];
	player->view[X + 2] += inc[X];
	player->view[Y + 2] += inc[Y];
	draw_line(data->img[PLAYER], player->view, color_pixel(255, 255, 255, 255));
	draw_player(data->img[PLAYER], player, data->setup.unit, 1);
	return (0);
}
