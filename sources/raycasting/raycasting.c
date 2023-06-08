/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:21:03 by jduval            #+#    #+#             */
/*   Updated: 2023/06/08 12:09:21 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

static void		reset_map(t_data *data);
static void		send_ray(t_ray *ray, float alpha, t_data *data, float n_ray);
static float	make_alpha(float p_angle, float delta, float ray);

void	raycasting(t_data *data, t_player *player)
{
	float	draw[4];
	t_ray	ray;
	float	i;
	float	alpha;

	reset_map(data);
	ray.s_coord[X] = player->pos[X];
	ray.s_coord[Y] = player->pos[Y];
	draw[X] = ray.s_coord[X];
	draw[Y] = ray.s_coord[Y];
	i = 0.0f;
	while (i < WIDTH)
	{
		alpha = make_alpha(player->angle, data->tools.delta_angle, i);
		send_ray(&ray, alpha, data, i);
		//send_ray(&ray, player->angle, data);
		draw[X + 2] = ray.e_coord[X];
		draw[Y + 2] = ray.e_coord[Y];
		draw_line(data->img[PLAYER], draw, color_pixel(255, 255, 255, 255));
		draw_pov(data, player, 1);
		printf("i = %f\tdist = %f\n", i, ray.dist);
		i += 1.0f;
	}
}

static float	make_alpha(float p_angle, float delta, float ray)
{
	float	alpha;

	alpha  = (p_angle - (FOV / 2)) + (delta * ray);
	if (alpha < 0.0f)
		alpha = 360.0f + alpha;
	else if (alpha > 360.0f)
		alpha = alpha - 360.0f;
	return (alpha);
	
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

static int	put_info_ray(t_ray *ray_v, t_ray *ray_h, t_ray *ray, float alpha)
{
	if (ray_v->dist > ray_h->dist)
	{
		ray->e_coord[X] = ray_h->e_coord[X];
		ray->e_coord[Y] = ray_h->e_coord[Y];
		ray->dist = ray_h->dist;
		if (alpha >= 0.0f && alpha <= 180.0f)
			return (NO);
		else
			return (SO);
	}
	else
	{
		ray->e_coord[X] = ray_v->e_coord[X];
		ray->e_coord[Y] = ray_v->e_coord[Y];
		ray->dist = ray_v->dist;
		if ((alpha > 0.0f && alpha < 90.0f)
			|| (alpha > 270.0f && alpha < 360.0f))
			return (EA);
		else
			return (WE);
	}
}

static float	calc_dist(t_ray *ray, float n_ray, float d_angle)
{
	float	dist;
	float	angle;

	if (n_ray < WIDTH / 2)
		angle = (FOV / 2) - (n_ray * d_angle);
	else
		angle = n_ray * d_angle - (FOV / 2);
	//printf("dist = %f\tn = %f\tangle = %f\n", ray->dist, n_ray, angle);
	dist = floorf(ray->dist * cosf(angle * RAD_CONV));
	return (dist);
}

static void	send_ray(t_ray *ray, float alpha, t_data *data, float n_ray)
{
	t_ray	ray_v;
	t_ray	ray_h;

	init_both_ray(ray, &ray_v, &ray_h, alpha);
	find_h_wall(data, &ray_h, alpha);
	find_v_wall(data, &ray_v, alpha);
	ray_v.dist = sqrtf(powf(ray_v.e_coord[X] - ray_v.s_coord[X], 2.0f)
			+ powf(ray_v.e_coord[Y] - ray_v.s_coord[Y], 2.0f));
	ray_h.dist = sqrtf(powf(ray_h.e_coord[X] - ray_h.s_coord[X], 2.0f)
			+ powf(ray_h.e_coord[Y] - ray_h.s_coord[Y], 2.0f));
	ray->texture = put_info_ray(&ray_v, &ray_h, ray, alpha);
	ray->dist = calc_dist(ray, n_ray, data->tools.delta_angle);
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
