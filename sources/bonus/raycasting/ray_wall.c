/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:13:10 by jduval            #+#    #+#             */
/*   Updated: 2023/07/04 13:54:05 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	send_ray(t_data *data, t_raytool *rtool);
static void	init_rtool(t_raytool *rtool, t_data *data, float alpha, float id);

bool	ray_wall(t_data *data, t_ray *ray, float alpha, float id)
{
	t_raytool	rtool;
	bool		door;

	init_rtool(&rtool, data, alpha, id);
	door = send_ray(data, &rtool);
	set_texture(data, ray, &rtool);
	ray->img = WALL;
	ray->side = rtool.side;
	ray->dist_perp = set_perpdist(data, &rtool);
	set_coord(ray, &rtool, data->player.pos, alpha);
	return (door);
}

static int	ray_collide(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		return (WALL);
	else if (data->map[y][x] == '0')
		return (-1);
	else
		return (DOOR);
}

static bool	send_ray(t_data *data, t_raytool *rtool)
{
	int		area;
	bool	door;
	t_door	*node;

	door = false;
	while (1)
	{
		area = ray_collide(data, rtool->ind[X], rtool->ind[Y]);
		if (area == WALL)
			return (door);
		else if (area == DOOR)
		{
			node = find_door(&data->doors, rtool->ind[X], rtool->ind[Y]);
			if (node->status != CLOSE)
				door = true;
			else
				return (door);
		}
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
