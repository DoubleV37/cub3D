/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_door.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:42:20 by jduval            #+#    #+#             */
/*   Updated: 2023/07/05 12:04:52 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	send_ray(char **map, t_raytool *rtool);

bool	ray_door(t_data *data, t_ray *ray, float alpha)
{
	t_raytool	rtool;

	init_rtool(&rtool, data, alpha, ray->num_ray);
	send_ray(data->map, &rtool);
	set_texture(data, ray, &rtool);
	ray->img = DOOR;
	ray->side = rtool.side;
	ray->dist_perp = set_perpdist(data, &rtool);
	set_coord(ray, &rtool, data->player.pos, alpha);
	return (false);
}

static void	send_ray(char **map, t_raytool *rtool)
{
	while (map[rtool->ind[Y]][rtool->ind[X]] != 'D')
	{
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
}
