/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_door.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:42:20 by jduval            #+#    #+#             */
/*   Updated: 2023/07/04 13:52:31 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	send_ray(char **map, t_raytool *rtool);
static void	init_rtool(t_raytool *rtool, t_data *data, float alpha, float id);

bool	ray_door(t_data *data, t_ray *ray, float alpha, float id)
{
	t_raytool	rtool;

	init_rtool(&rtool, data, alpha, id);
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
