/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_wall_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:13:10 by jduval            #+#    #+#             */
/*   Updated: 2023/07/07 09:10:04 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	send_ray(t_data *data, t_raytool *rtool);
static void	which_incrementation(t_raytool *rtool);

bool	ray_wall(t_data *data, t_ray *ray, float alpha)
{
	t_raytool	rtool;
	bool		door;

	init_rtool(&rtool, data, alpha, ray->num_ray);
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
		which_incrementation(rtool);
	}
	return (door);
}

static void	which_incrementation(t_raytool *rtool)
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
