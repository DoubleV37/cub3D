/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:20:15 by jduval            #+#    #+#             */
/*   Updated: 2023/06/19 18:36:21 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	incr_angle(t_player *player, t_rot *rotate, t_dir dir);
static int	particular_dir(float *vector, t_player *player);
static void	calc_rotation(float *dir, t_rot *rot, t_dir flag);

void	rotate_player(t_data *data, t_player *player, t_dir dir)
{
	t_tool	*tmp;
	float	norm;

	tmp = &data->tools;
	incr_angle(player, &data->tools.rotate, dir);
	if (player->angle == 0.0f || player->angle == 360.0f
		|| player->angle == 90.0f || player->angle == 180.0f
		|| player->angle == 270.0f)
	{
		particular_dir(tmp->dir, player);
		return ;
	}
	calc_rotation(tmp->dir, &data->tools.rotate, dir);
	norm = sqrtf(powf(tmp->dir[X], 2.0f) + powf(tmp->dir[Y], 2.0f));
	tmp->dir[X] = tmp->dir[X] / norm;
	tmp->dir[Y] = tmp->dir[Y] / norm;
	return ;
}

static void	calc_rotation(float *dir, t_rot *rot, t_dir flag)
{
	if (flag == RIGHTWARD)
	{
		dir[X] = dir[X] * cosf(rot->angle * RAD_CONV) - dir[Y] * sinf(rot->angle * RAD_CONV);
		dir[Y] = dir[X] * sinf(rot->angle * RAD_CONV) + dir[Y] * cosf(rot->angle * RAD_CONV);
	}
	else
	{
		dir[X] = dir[X] * cosf(-rot->angle * RAD_CONV) - dir[Y] * sinf(-rot->angle * RAD_CONV);
		dir[Y] = dir[X] * sinf(-rot->angle * RAD_CONV) + dir[Y] * cosf(-rot->angle * RAD_CONV);
	}
	return ;
}

static void	incr_angle(t_player *player, t_rot *rotate, t_dir dir)
{
	float	angle;

	if (dir == LEFTWARD)
	{
		angle = player->angle + rotate->angle;
		if (angle > 360.0f)
			player->angle = angle - 360.0f;
		else
			player->angle = angle;
	}
	else
	{
		angle = player->angle - rotate->angle;
		if (angle < 0.0f)
			player->angle = 360.0f + angle;
		else
			player->angle = angle;
	}
}

static int	particular_dir(float *vector, t_player *player)
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
