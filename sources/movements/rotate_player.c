/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:20:15 by jduval            #+#    #+#             */
/*   Updated: 2023/05/20 17:22:50 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	incr_angle(t_player *player, t_dir dir);
static void	calc_rotation(float *view, t_rot *rot, int flag);

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

void	calc_rotation(float *view, t_rot *rot, int flag)
{
	float	xtemp;
	float	ytemp;

	xtemp = view[X + 2] - view[X];
	ytemp = view[Y + 2] - view[Y];
	if (flag == 1)
	{
		view[X + 2] = xtemp * rot->cos_ang - ytemp * rot->sin_ang + view[X];
		view[Y + 2] = xtemp * rot->sin_ang + ytemp * rot->cos_ang + view[Y];
	}
	else
	{
		view[X + 2] = xtemp * rot->cos_inv - ytemp * rot->sin_inv + view[X];
		view[Y + 2] = xtemp * rot->sin_inv + ytemp * rot->cos_inv + view[Y];
	}
	return ;
}
