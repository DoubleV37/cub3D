/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:21:03 by jduval            #+#    #+#             */
/*   Updated: 2023/06/06 20:34:39 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

static void	reset_map(t_data *data);
static void	send_ray(t_ray *ray, float alpha, t_data *data);

void	raycasting(t_data *data, t_player *player)
{
	float	draw[4];
	t_ray	ray;

	reset_map(data);
	ray.s_coord[X] = player->pos[X];
	ray.s_coord[Y] = player->pos[Y];
	send_ray(&ray, player->angle, data);
	draw[X] = ray.s_coord[X];
	draw[Y] = ray.s_coord[Y];
	draw[X + 2] = ray.e_coord[X];
	draw[Y + 2] = ray.e_coord[Y];
	draw_line(data->img[PLAYER], draw, color_pixel(255, 255, 255, 255));
	draw_pov(data, player, 1);
}

static void	init_both_ray(t_ray *ray, t_ray *ray_v, t_ray *ray_h, float angle)
{
	float	alpha;

	alpha = tanf(angle * RAD_CONV);
	ray_v->s_coord[X] = ray->s_coord[X];
	ray_v->s_coord[Y] = ray->s_coord[Y];
	ray_h->s_coord[X] = ray->s_coord[X];
	ray_h->s_coord[Y] = ray->s_coord[Y];
	ray_h->e_coord[X] = ray->s_coord[X];
	ray_h->e_coord[Y] = ray->s_coord[Y];
	ray_v->tan_alpha = alpha; 
	ray_h->tan_alpha = alpha; 
}

static void	send_ray(t_ray *ray, float alpha, t_data *data)
{
	t_ray	ray_v;
	t_ray	ray_h;

	init_both_ray(ray, &ray_v, &ray_h, alpha);
	find_h_wall(data, &ray_h, alpha);
	find_v_wall(data, &ray_v, alpha);
	//printf("3h = %f\tv = %f\n", ray_h.dist, ray_v.dist);
	if (ray_v.dist > ray_h.dist)
	{
		ray->e_coord[X] = ray_h.e_coord[X];
		ray->e_coord[Y] = ray_h.e_coord[Y];
	}
	else
	{
		ray->e_coord[X] = ray_v.e_coord[X];
		ray->e_coord[Y] = ray_v.e_coord[Y];
	}
	//ray->e_coord[X] = ray_h.e_coord[X];
	//ray->e_coord[Y] = ray_h.e_coord[Y];
	return ;
}

static void	reset_map(t_data *data)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			mlx_put_pixel(data->img[PLAYER], j, i, color_pixel(0, 0, 0, 0));
	}
}
