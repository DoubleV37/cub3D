/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_ray_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:51:40 by jduval            #+#    #+#             */
/*   Updated: 2023/07/05 12:03:17 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <math.h>

static void	set_door_texture(t_data *data, t_raytool *rtool, t_ray *ray);

void	set_texture(t_data *data, t_ray *ray, t_raytool *rtool)
{
	if (data->map[rtool->ind[Y]][rtool->ind[X]] == 'D')
	{
		set_door_texture(data, rtool, ray);
		return ;
	}
	if (rtool->side == V)
	{
		if (rtool->u_vector[X] < 0.0f)
			ray->texture = WE;
		else
			ray->texture = EA;
	}
	else
	{
		if (rtool->u_vector[Y] < 0.0f)
			ray->texture = NO;
		else
			ray->texture = SO;
	}
	return ;
}

float	set_perpdist(t_data *data, t_raytool *rtool)
{
	float	dist;
	float	angle;

	if (rtool->side == V)
		dist = rtool->dist[V] - rtool->ndist[V];
	else
		dist = rtool->dist[H] - rtool->ndist[H];
	if (rtool->id < WIDTH / 2)
		angle = (FOV / 2) - (rtool->id * data->player.delta_angle);
	else
		angle = rtool->id * data->player.delta_angle - (FOV / 2);
	dist = floorf(dist * cosf(angle * RAD_CONV));
	return (dist);
}

void	set_coord(t_ray *ray, t_raytool *rtool, float *pos, float alpha)
{
	float	x;
	float	y;
	float	dist;

	if (rtool->side == V)
		dist = rtool->dist[V] - rtool->ndist[V];
	else
		dist = rtool->dist[H] - rtool->ndist[H];
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
	ray->pos[X] = floorf(pos[X] + x);
	ray->pos[Y] = floorf(pos[Y] + y);
	return ;
}

static void	set_door_texture(t_data *data, t_raytool *rtool, t_ray *ray)
{
	t_door	*door;

	door = find_door(&data->doors, rtool->ind[X], rtool->ind[Y]);
	ray->texture = door->frame;
}
