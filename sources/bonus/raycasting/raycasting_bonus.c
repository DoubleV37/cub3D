/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:37:15 by jduval            #+#    #+#             */
/*   Updated: 2023/07/03 18:38:08 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <math.h>

static void		init_rtool(t_raytool *rtool, t_data *data,
					float alpha, float id);
static bool		send_ray(char **map, t_raytool *rtool, char target);
static bool		create_ray(t_data *data, t_ray *ray, float alpha, float id);

int	raycasting(t_data *data, t_player *player)
{
	t_ray	ray;
	float	i;
	float	alpha;

	reset_map(data->img[WALL]);
	i = 0.0f;
	alpha = player->angle - (FOV / 2);
	ray.door = false;
	while (i < WIDTH)
	{
		alpha = get_right_angle(alpha);
		if (create_ray(data, &ray, alpha, i) == true)
			ray.door = true;
		ray.num_ray = i;
		draw_texture(data, &ray);
		if (ray.door == true)
			continue ;
		alpha += player->delta_angle;
		i += 1.0f;
	}
	return (0);
}

float	get_right_angle(float alpha)
{
	float	value;

	value = alpha;
	if (alpha < 0.0f)
		value = 360.0f + alpha;
	else if (alpha > 360.0f)
		value = alpha - 360.0f;
	return (value);
}

static bool	create_ray(t_data *data, t_ray *ray, float alpha, float id)
{
	t_raytool	rtool;
	bool		door;

	init_rtool(&rtool, data, alpha, id);
	door = false;
	if (ray->door == true)
		(void)send_ray(data->map, &rtool, 'D');
	else
		door = send_ray(data->map, &rtool, '1');
	set_texture(data, ray, &rtool);
	ray->dist_perp = set_perpdist(data, &rtool);
	set_coord(ray, &rtool, data->player.pos, alpha);
	ray->door = false;
	return (door);
}

static bool	send_ray(char **map, t_raytool *rtool, char target)
{
	bool	door;

	door = false;
	while (map[rtool->ind[Y]][rtool->ind[X]] != target)
	{
		if (map[rtool->ind[Y]][rtool->ind[X]] == 'D')
			door = true;
		if (rtool->dist[H] < rtool->dist[V])
		{
			rtool->ind[Y] += rtool->step[Y];
			rtool->dist[H] += rtool->ndist[H];
			rtool->side = H;
		}
		else
		{
			rtool->ind[X] += rtool->step[X];
			rtool->dist[V] += rtool->ndist[V];
			rtool->side = V;
		}
	}
	return (door);
}

static void	init_rtool(t_raytool *rtool, t_data *data, float alpha, float id)
{
	rtool->id = id;
	process_uvector(alpha, rtool->u_vector);
	process_ndist(rtool->ndist, rtool->u_vector, data->unit);
	first_dist(rtool, data->player.pos, data->unit, alpha);
	rtool->ind[X] = data->player.pos[X] / data->unit;
	rtool->ind[Y] = data->player.pos[Y] / data->unit;
	rtool->step[X] = 1;
	rtool->step[Y] = 1;
	if (rtool->u_vector[X] < 0.0f)
		rtool->step[X] = -1;
	if (rtool->u_vector[Y] < 0.0f)
		rtool->step[Y] = -1;
}
