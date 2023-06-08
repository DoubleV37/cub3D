/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_collide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:23:45 by jduval            #+#    #+#             */
/*   Updated: 2023/06/08 09:50:44 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdbool.h>

static bool	ray_is_up(t_data *data, t_ray *ray, float alpha);
static bool	ray_is_down(t_data *data, t_ray *ray, float alpha);

bool	ray_in_angle(t_ray *ray, t_data *data, float alpha)
{
	if (alpha > 0.0f && alpha < 180.0f)
	{
		if (ray_is_up(data, ray, alpha) == true)
			return (true);
		else
			return (false);
	}
	else
	{
		if (ray_is_down(data, ray, alpha) == true)
			return (true);
		else
			return (false);

	}
}

static bool	ray_is_up(t_data *data, t_ray *ray, float alpha)
{
	int	x;
	int	y;

	x = ray->e_coord[X] / data->tools.unit;
	y = ray->e_coord[Y] / data->tools.unit;
	if (is_in_screen(x, y, data->map, ray) == false)
		return (false);
	if (alpha > 0.0f && alpha < 90.0f)
	{
		if (data->map[y][x] == '0' && data->map[y][x - 1] == '1'
			&& data->map[y + 1][x] == '1')
			return (true);
	}
	else
	{
		if (data->map[y][x] == '0' && data->map[y][x + 1] == '1'
			&& data->map[y + 1][x] == '1')
			return (true);
	}
	return (false);
}

static bool	ray_is_down(t_data *data, t_ray *ray, float alpha)
{
	int	x;
	int	y;

	x = ray->e_coord[X] / data->tools.unit;
	y = ray->e_coord[Y] / data->tools.unit;
	if (is_in_screen(x, y, data->map, ray) == false)
		return (false);
	if (alpha > 180.0f && alpha < 270.0f)
	{
		if (data->map[y][x] == '0' && data->map[y - 1][x] == '1'
			&& data->map[y][x + 1] == '1')
			return (true);
	}
	else
	{
		if (data->map[y][x] == '0' && data->map[y - 1][x] == '1'
			&& data->map[y][x - 1] == '1')
			return (true);
	}
	return (false);
}
