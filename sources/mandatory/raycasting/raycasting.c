/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:37:15 by jduval            #+#    #+#             */
/*   Updated: 2023/07/07 09:11:56 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		reset_map(mlx_image_t *img);
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
		draw_texture(data, &ray);
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
