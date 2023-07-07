/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:17:04 by jduval            #+#    #+#             */
/*   Updated: 2023/07/07 08:43:25 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_bonus.h"
#include <math.h>

static bool	special_angle_uvector(float alpha, float *u_vector);
static void	process_uvector(float alpha, float *u_vector);
static void	process_ndist(float *n_dist, float *u_vector);
static void	first_dist(t_raytool *rtool, float *pos, float alpha);

void	init_rtool(t_raytool *rtool, t_data *data, float alpha, float id)
{
	rtool->id = id;
	process_uvector(alpha, rtool->u_vector);
	process_ndist(rtool->ndist, rtool->u_vector);
	first_dist(rtool, data->player.pos, alpha);
	rtool->ind[X] = data->player.pos[X] / SIZE;
	rtool->ind[Y] = data->player.pos[Y] / SIZE;
	rtool->step[X] = 1;
	rtool->step[Y] = 1;
	if (rtool->u_vector[X] < 0.0f)
		rtool->step[X] = -1;
	if (rtool->u_vector[Y] < 0.0f)
		rtool->step[Y] = -1;
	if (rtool->dist[V] < rtool->dist[H])
		rtool->side = V;
	else
		rtool->side = H;
}

static void	process_ndist(float *n_dist, float *u_vector)
{
	if (u_vector[X] == 0.0f)
		n_dist[V] = 1e30;
	if (u_vector[Y] == 0.0f)
		n_dist[H] = 1e30;
	if (u_vector[X] != 0.0f)
	{
		n_dist[V] = sqrtf(1.0f + powf(u_vector[Y], 2.0f)
				/ powf(u_vector[X], 2.0f)) * SIZE;
	}
	if (u_vector[Y] != 0.0f)
	{
		n_dist[H] = sqrtf(1.0f + powf(u_vector[X], 2.0f)
				/ powf(u_vector[Y], 2.0f)) * SIZE;
	}
}

static void	first_dist(t_raytool *rtool, float *pos, float alpha)
{
	if (rtool->u_vector[X] < 0.0f)
	{
		rtool->dist[V] = pos[X] - (floorf(pos[X] / SIZE) * SIZE);
		rtool->dist[V] = fabs(rtool->dist[V] / cosf(alpha * RAD_CONV));
	}
	else
	{
		rtool->dist[V] = (floorf(pos[X] / SIZE) + 1.0f) * SIZE - pos[X];
		rtool->dist[V] = fabs(rtool->dist[V] / cosf(alpha * RAD_CONV));
	}
	if (rtool->u_vector[Y] < 0.0f)
	{
		rtool->dist[H] = pos[Y] - (floorf(pos[Y] / SIZE) * SIZE);
		rtool->dist[H] = fabs(rtool->dist[H] / sinf(alpha * RAD_CONV));
	}
	else
	{
		rtool->dist[H] = (floorf(pos[Y] / SIZE) + 1.0f) * SIZE - pos[Y];
		rtool->dist[H] = fabs(rtool->dist[H] / sinf(alpha * RAD_CONV));
	}
}

static void	process_uvector(float alpha, float *u_vector)
{
	float	norm;

	u_vector[X] = 0.0f;
	u_vector[Y] = 0.0f;
	if (special_angle_uvector(alpha, u_vector) == true)
		return ;
	u_vector[X] = cosf(alpha * RAD_CONV);
	u_vector[Y] = sinf(alpha * RAD_CONV);
	norm = sqrtf(powf(u_vector[X], 2.0f) + powf(u_vector[Y], 2.0f));
	u_vector[X] = u_vector[X] / norm;
	u_vector[Y] = u_vector[Y] / norm;
	if (alpha > 90.0f && alpha < 270.0f && u_vector[X] > 0.0f)
		u_vector[X] *= (-1.0f);
	else if (!(alpha > 90.0f && alpha < 270.0f) && u_vector[X] < 0.0f)
		u_vector[X] *= (-1.0f);
	if (alpha > 0.0f && alpha < 180.0f && u_vector[Y] > 0.0f)
		u_vector[Y] *= (-1.0f);
	else if (alpha > 180.0f && alpha < 360.0f && u_vector[Y] < 0.0f)
		u_vector[Y] *= (-1.0f);
	return ;
}

static bool	special_angle_uvector(float alpha, float *u_vector)
{
	if (alpha == 0.0f || alpha == 360.0f)
	{
		u_vector[X] = 1.0f;
		return (true);
	}
	else if (alpha == 180.0f)
	{
		u_vector[X] = -1.0f;
		return (true);
	}
	else if (alpha == 90.0f)
	{
		u_vector[Y] = -1.0f;
		return (true);
	}
	else if (alpha == 270.0f)
	{
		u_vector[Y] = 1.0f;
		return (true);
	}
	return (false);
}
