/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:21:03 by jduval            #+#    #+#             */
/*   Updated: 2023/06/04 16:30:07 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

static void	reset_map(t_data *data);
static void	send_ray(t_ray *ray, float alpha, t_data *data, t_player *player);

void	raycasting(t_data *data, t_player *player)
{
	float	ray_angle;
	int		i;
	t_ray	ray;

	reset_map(data);
	ray_angle = player->angle;
	i = 0;
	ray.s_coord[X] = player->pos[X];
	ray.s_coord[Y] = player->pos[Y];
	while (i < WIDTH)
	{
		send_ray(&ray, ray_angle, data, player);
		ray_angle += data->tools.delta-angle;
		i++;
	}
}

static void	send_ray(t_ray *ray, float alpha, t_data *data, t_player *player)
{
	ray->norm[X] = first_vertical(ray, alpha);
	ray->norm[Y] = first_horizontal(ray, alpha);
	
}

static void	reset_map(t_data *data)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			mlx_put_pixel(data->img[RAY], i, j , color_pixel(0, 0, 0, 0));
	}
}
