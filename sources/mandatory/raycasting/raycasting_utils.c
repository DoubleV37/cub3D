/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:17:04 by jduval            #+#    #+#             */
/*   Updated: 2023/06/20 11:29:21 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	end_coordinate(float *pos, float dist, float alpha, float *coord)
{
	float	x;
	float	y;

	x = dist * cosf(alpha * RAD_CONV);
	y = dist * sinf(alpha * RAD_CONV);
	if (alpha > 90.0f && alpha < 270.0f && x > 0.0f)
		x *= (-1.0f);
	else if (((alpha > 0.0f && alpha < 90.0f)
			|| (alpha > 270.0f && alpha < 360.0f)) && x < 0.0f)
		x *= (-1.0f);
	if (alpha > 0.0f && alpha < 180.0f && y > 0.0f)
		y *= (-1.0f);
	else if (alpha > 180.0f && alpha < 360.0f && y < 0.0f)
		y *= (-1.0f);
	coord[X] = floorf(pos[X] + x);
	coord[Y] = floorf(pos[Y] + y);
	return ;
}

void	process_ndist(float *n_dist, float *u_vector, float unit)
{
	if (u_vector[X] == 0.0f)
		n_dist[V] = 1e30;
	if (u_vector[Y] == 0.0f)
		n_dist[H] = 1e30;
	if (u_vector[X] != 0.0f)
	{
		n_dist[V] = sqrtf(1.0f + powf(u_vector[Y], 2.0f)
				/ powf(u_vector[X], 2.0f)) * unit;
	}
	if (u_vector[Y] != 0.0f)
	{
		n_dist[H] = sqrtf(1.0f + powf(u_vector[X], 2.0f)
				/ powf(u_vector[Y], 2.0f)) * unit;
	}
}

void	first_dist(t_raytool *rtool, float *pos, float unit, float alpha)
{
	if (rtool->u_vector[X] < 0.0f)
	{
		rtool->dist[V] = pos[X] - (floorf(pos[X] / unit) * unit);
		rtool->dist[V] = fabs(rtool->dist[V] / cosf(alpha * RAD_CONV));
	}
	else
	{
		rtool->dist[V] = (floorf(pos[X] / unit) + 1.0f) * unit - pos[X];
		rtool->dist[V] = fabs(rtool->dist[V] / cosf(alpha * RAD_CONV));
	}
	if (rtool->u_vector[Y] < 0.0f)
	{
		rtool->dist[H] = pos[Y] - (floorf(pos[Y] / unit) * unit);
		rtool->dist[H] = fabs(rtool->dist[H] / sinf(alpha * RAD_CONV));
	}
	else
	{
		rtool->dist[H] = (floorf(pos[Y] / unit) + 1.0f) * unit - pos[Y];
		rtool->dist[H] = fabs(rtool->dist[H] / sinf(alpha * RAD_CONV));
	}
}

void	process_uvector(float alpha, float *u_vector)
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

bool	special_angle_uvector(float alpha, float *u_vector)
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
