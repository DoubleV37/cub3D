/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:20:15 by jduval            #+#    #+#             */
/*   Updated: 2023/05/23 11:48:51 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

static void	incr_angle(t_player *player, t_dir dir);
static int	particular_case(float *vector, t_player *player);
static void	calc_rotation(float *view, t_rot *rot, int flag);

int	rotate_player(t_data *data, t_player *player, t_dir dir)
{
	draw_pov(data->img[PLAYER], player, 0);
	incr_angle(player, dir);
	if (particular_case(player->vector, player) == 1)
	{
		if (dir == LEFTWARD)
			calc_rotation(player->vector, &player->rotate, 0);
		else
			calc_rotation(player->vector, &player->rotate, 1);
	}
	draw_pov(data->img[PLAYER], player, 1);
	return (0);
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

static int	particular_case(float *vector, t_player *player)
{
	if (player->angle == 0.0f || player->angle == 360.0f)
	{
		vector[X] = 1.0f;
		vector[Y] = 0.0f;
		return (0);
	}
	else if (player->angle == 90.0f)
	{
		vector[X] = 0.0f;
		vector[Y] = -1.0f;
		return (0);
	}
	else if (player->angle == 270.0f)
	{
		vector[X] = 0.0f;
		vector[Y] = 1.0f;	
		return (0);
	}
	else if (player->angle == 180.0f)
	{
		vector[X] = -1.0f;
		vector[Y] = 0.0f;
		return (0);
	}
	return (1);
}
