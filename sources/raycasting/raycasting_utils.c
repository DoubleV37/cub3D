/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:30:43 by jduval            #+#    #+#             */
/*   Updated: 2023/06/15 18:25:35 by jduval           ###   ########.fr       */
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
	else if (((alpha > 0.0f && alpha < 90.0f) || (alpha > 270.0f && alpha < 360.0f)) && x < 0.0f)
		x *= (-1.0f);
	if (alpha > 0.0f && alpha < 180.0f && y > 0.0f)
		y *= (-1.0f);
	else if (alpha > 180.0f && alpha < 360.0f && y < 0.0f)
		y *= (-1.0f);
	coord[X] = roundf(pos[X] + x);
	coord[Y]= roundf(pos[Y] + y);
	return ;
}

void	define_step(float *u_vector, int *step)
{
	if (u_vector[X] < 0.0f)
		step[X] = -1;
	else
		step[X] = 1;
	if (u_vector[Y] < 0.0f)
		step[Y] = -1;
	else
		step[Y] = 1;
}

void	process_ndist(float *n_dist, float *u_vector)
{
	if (u_vector[X] == 0.0f)
		n_dist[V] = 1e30;
	if (u_vector[Y] == 0.0f)
		n_dist[H] = 1e30;
	if (u_vector[X] != 0.0f)
		n_dist[V] = sqrtf(1.0f + powf(u_vector[Y], 2.0f) / powf(u_vector[X], 2.0f));
	if (u_vector[Y] != 0.0f)
		n_dist[H] = sqrtf(1.0f + powf(u_vector[X], 2.0f) / powf(u_vector[Y], 2.0f));
}

void	first_intersection(float *dist, float *n_dist, float *pos, float *u_vector, float unit)
{
	if (u_vector[X] < 0.0f)
		dist[V] = (pos[X] - (floorf(pos[X] / unit) * unit)) * n_dist[V];
	else
		dist[V] = (ceilf(pos[X] / unit) * unit - pos[X]) * n_dist[V];
	if (u_vector[Y] < 0.0f)
		dist[H] = (pos[Y] - (floorf(pos[Y] / unit) * unit)) * n_dist[H];
	else
		dist[H] = (ceilf(pos[Y] / unit) * unit - pos[Y]) * n_dist[H];
}

void	process_uvector(float alpha, float *u_vector) //find unitary vector of the ray
{
	float	norm;
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
		u_vector[Y] = 0.0f;
		return (true);
	}
	else if (alpha == 180.0f)
	{
		u_vector[X] = -1.0f;
		u_vector[Y] = 0.0f;
		return (true);
	}
	else if (alpha == 90.0f)
	{
		u_vector[X] = 0.0f;
		u_vector[Y] = -1.0f;
		return (true);
	}
	else if (alpha == 270.0f)
	{
		u_vector[X] = 0.0f;
		u_vector[Y] = 1.0f;
		return (true);
	}
	else
		return (false);
}
