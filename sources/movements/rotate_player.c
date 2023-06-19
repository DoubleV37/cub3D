/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:20:15 by jduval            #+#    #+#             */
/*   Updated: 2023/06/19 15:26:33 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	incr_angle(t_player *player, t_rot *rotate, t_dir dir);
static int	particular_dir(float *vector, t_player *player);
static void	calc_rotation(float *dir, t_rot *rot, t_dir flag);

int	rotate_player(t_data *data, t_player *player, t_dir dir)
{
	t_tool	*tmp;
	float	norm;

	tmp = &data->tools;
	//draw_pov(data, player, 0);
	calc_rotation(tmp->dir, &data->tools.rotate, dir);
	incr_angle(player, &data->tools.rotate, dir);
	norm = sqrtf(powf(tmp->dir[X], 2) + powf(tmp->dir[Y], 2));
	tmp->dir[X] /= norm;
	tmp->dir[Y] /= norm;
	//draw_pov(data, player, 1);
	return (0);
}

static void	calc_rotation(float *dir, t_rot *rot, t_dir flag)
{
	if (flag == RIGHTWARD)
	{
		dir[X] = dir[X] * rot->cos_ang - dir[Y] * rot->sin_ang;
		dir[Y] = dir[X] * rot->sin_ang + dir[Y] * rot->cos_ang;
	}
	else
	{
		dir[X] = dir[X] * rot->cos_inv - dir[Y] * rot->sin_inv;
		dir[Y] = dir[X] * rot->sin_inv + dir[Y] * rot->cos_inv;
	}
	return ;
}

static void	incr_angle(t_player *player, t_rot *rotate, t_dir dir)
{
	if (dir == LEFTWARD)
	{
		if (player->angle + rotate->angle > 360.0f)
			player->angle += rotate->angle - 360.0f;
		else
			player->angle += rotate->angle;
	}
	else
	{
		if (player->angle - rotate->angle < 0.0f)
			player->angle = 360.0f - rotate->angle - player->angle;
		else
			player->angle -= rotate->angle;
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
