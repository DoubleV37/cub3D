/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:37:15 by jduval            #+#    #+#             */
/*   Updated: 2023/06/23 13:07:05 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void		reset_map(mlx_image_t *img);
static void		init_rtool(t_raytool *rtool, t_data *data,
					float alpha, float id);
static void		send_ray(t_data *data, t_ray *ray, float alpha, float id);
static float	make_alpha(float alpha);

int	raycasting(t_data *data, t_player *player)
{
	t_ray	ray;
	float	i;
	float	alpha;

	reset_map(data->img[WALL]);
	i = 0.0f;
	alpha = player->angle - (FOV / 2);
	while (i < WIDTH)
	{
		alpha = make_alpha(alpha);
		send_ray(data, &ray, alpha, i);
		ray.num_ray = i;
		if (draw_wall(data, &ray) == 1)
			return (1);
		alpha += player->delta_angle;
		i += 1.0f;
	}
	return (0);
}

static float	make_alpha(float alpha)
{
	float	value;

	value = alpha;
	if (alpha < 0.0f)
		value = 360.0f + alpha;
	else if (alpha > 360.0f)
		value = alpha - 360.0f;
	return (value);
}

static void	send_ray(t_data *data, t_ray *ray, float alpha, float id)
{
	t_raytool	rtool;

	init_rtool(&rtool, data, alpha, id);
	while (data->map[rtool.ind[Y]][rtool.ind[X]] == '0')
	{
		if (rtool.dist[H] < rtool.dist[V])
		{
			rtool.ind[Y] += rtool.step[Y];
			rtool.dist[H] += rtool.ndist[H];
			rtool.side = H;
		}
		else
		{
			rtool.ind[X] += rtool.step[X];
			rtool.dist[V] += rtool.ndist[V];
			rtool.side = V;
		}
	}
	set_texture(ray, rtool.side, rtool.u_vector);
	ray->dist_perp = set_perpdist(data, &rtool);
	set_coord(ray, &rtool, data->player.pos, alpha);
	return ;
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

static void	reset_map(mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_put_pixel(img, j, i, color_pixel(0, 0, 0, 0));
			j++;
		}
		i++;
	}
}
