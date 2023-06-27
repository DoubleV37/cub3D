/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:20:15 by jduval            #+#    #+#             */
/*   Updated: 2023/06/27 11:44:15 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <math.h>

static void	incr_angle(t_player *player, float rotate, t_dir dir);
static void	calc_rotation(float *dir, float angle);
static void	control_value(float *vector, float angle, int axe);

void	rotate_player(t_player *player, t_dir dir)
{
	float	norm;

	incr_angle(player, player->rotate, dir);
	calc_rotation(player->dir, player->angle);
	norm = sqrtf(powf(player->dir[X], 2.0f) + powf(player->dir[Y], 2.0f));
	player->dir[X] = player->dir[X] / norm;
	player->dir[Y] = player->dir[Y] / norm;
	return ;
}

static void	control_value(float *vector, float angle, int axe)
{
	if (axe == X)
	{
		if (angle > 90.0f && angle < 270.0f && vector[X] > 0.0f)
			vector[X] *= (-1.0f);
		else if (((angle > 0.0f && angle < 90.0f) || angle > 270.0f)
			&& vector[X] < 0.0f)
			vector[X] *= (-1.0f);
	}
	else
	{
		if (angle > 0.0f && angle < 180.0f && vector[Y] > 0.0f)
			vector[Y] *= (-1.0f);
		else if (angle > 180.0f && angle < 360.0f && vector[Y] < 0.0f)
			vector[Y] *= (-1.0f);
	}
}

static void	calc_rotation(float *dir, float angle)
{
	dir[X] = cosf(angle * RAD_CONV);
	dir[Y] = sinf(angle * RAD_CONV);
	control_value(dir, angle, X);
	control_value(dir, angle, Y);
	return ;
}

static void	incr_angle(t_player *player, float rotate, t_dir dir)
{
	float	angle2;

	if (dir == LEFTWARD)
	{
		angle2 = player->angle + rotate;
		if (angle2 > 360.0f)
			player->angle = angle2 - 360.0f;
		else
			player->angle = angle2;
	}
	else
	{
		angle2 = player->angle - rotate;
		if (angle2 < 0.0f)
			player->angle = 360.0f + angle2;
		else
			player->angle = angle2;
	}
}
