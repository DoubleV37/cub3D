/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:20:15 by jduval            #+#    #+#             */
/*   Updated: 2023/05/22 15:31:43 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	incr_angle(t_player *player, t_dir dir);
static void	calc_rotation(float *view, t_rot *rot, int flag);

int	rotate_player(t_data *data, t_player *player, t_dir dir)
{
	draw_pov(data->img[PLAYER], player, 0);
	if (dir == LEFTWARD)
		calc_rotation(player->vector, &player->rotate, 0);
	else
		calc_rotation(player->vector, &player->rotate, 1);
	incr_angle(player, dir);
	draw_pov(data->img[PLAYER], player, 1);
	return (0);
}

static void	incr_angle(t_player *player, t_dir dir)
{
	if (dir == LEFTWARD)
	{
		if (player->angle + player->rotate.angle > 360.0f)
			player->angle += player->rotate.angle - 360.0f;
		else
			player->angle += player->rotate.angle;
	}
	else
	{
		if (player->angle - player->rotate.angle < 0.0f)
			player->angle = 360.0f - player->rotate.angle - player->angle;
		else
			player->angle -= player->rotate.angle;
	}
}

void	calc_rotation(float *vector, t_rot *rot, int flag)
{
	if (flag == 1)
	{
		vector[X] = vector[X] * rot->cos_ang - vector[Y] * rot->sin_ang;
		vector[Y] = vector[X] * rot->sin_ang + vector[Y] * rot->cos_ang;
	}
	else
	{
		vector[X] = vector[X] * rot->cos_inv - vector[Y] * rot->sin_inv;
		vector[Y] = vector[X] * rot->sin_inv + vector[Y] * rot->cos_inv;
	}
	return ;
}
