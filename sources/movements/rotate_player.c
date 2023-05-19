/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:20:15 by jduval            #+#    #+#             */
/*   Updated: 2023/05/19 17:21:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	incr_angle(t_player *player, t_dir dir);

int	rotate_player(t_data *data, t_player *player, t_dir dir)
{
	draw_line(data->img[PLAYER], player->view, color_pixel(255, 255, 255, 0));
	if (dir == LEFTWARD)
		calc_rotation(player->view, &player->rotate, 0);
	else
		calc_rotation(player->view, &player->rotate, 1);
	incr_angle(player, dir);
	draw_line(data->img[PLAYER], player->view, color_pixel(255, 255, 255, 255));
	draw_player(data->img[PLAYER], player, data->setup.unit, 1);
	return (0);
}

static void	incr_angle(t_player *player, t_dir dir)
{
	if (dir == LEFTWARD)
	{
		if (player->angle + player->rotate.angle > 360)
			player->angle += player->rotate.angle - 360;
		else
			player->angle += player->rotate.angle;
	}
	else
	{
		if (player->angle - player->rotate.angle < 0)
			player->angle = 360 - player->rotate.angle - player->angle;
		else
			player->angle -= player->rotate.angle;
	}
}
