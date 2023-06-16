/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:37:15 by jduval            #+#    #+#             */
/*   Updated: 2023/06/16 17:26:04 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

static void		reset_map(mlx_image_t *img);
static void		init_rtool(t_raytool *rtool, t_data *data,
					float alpha, float id);
static void		send_ray(t_data *data, t_ray *ray, float alpha, float id);
static float	make_alpha(float alpha);

void	raycasting(t_data *data, t_player *player)
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
		draw_wall(data, &ray, i);
		alpha += data->tools.delta_angle;
		i += 1.0f;
	}
	//draw_pov(data, player, 1);
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
	float		e_coord[2];

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
	/*if (rtool.side == V)
		end_coordinate(data->player.pos, rtool.dist[V] - rtool.ndist[V], alpha, e_coord);
	else
		end_coordinate(data->player.pos, rtool.dist[H] - rtool.ndist[H], alpha, e_coord);
	float	draw[4] = {data->player.pos[X], data->player.pos[Y], e_coord[X], e_coord[Y]};
	draw_line(data->img[PLAYER], draw, color_pixel(255, 255, 255, 255));*/
	return ;
}

static void	init_rtool(t_raytool *rtool, t_data *data, float alpha, float id)
{
	rtool->id = id;
	process_uvector(alpha, rtool->u_vector);
	process_ndist(rtool->ndist, rtool->u_vector, data->tools.unit);
	first_dist(rtool, data->player.pos, data->tools.unit, alpha);
	rtool->ind[X] = data->player.pos[X] / data->tools.unit;
	rtool->ind[Y] = data->player.pos[Y] / data->tools.unit;
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
