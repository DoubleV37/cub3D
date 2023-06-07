/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:51:47 by jduval            #+#    #+#             */
/*   Updated: 2023/06/07 11:52:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	incr_y(t_data *data, int *grid, float *tmp);
static void	incr_x(t_data *data, int *grid, float *tmp);

bool	is_in_screen(int x, int y, char **map, t_ray *ray)
{
	int	len_y;
	int	len_x;

	len_y = ft_array_len(map);
	if (y < 0 || y >= len_y)
	{
		ray->dist = 1e30;
		return (false);
	}
	len_x = (int)ft_strlen(map[y]);
	if (x < 0 || x >= len_x)
	{
		ray->dist = 1e30;
		return (false);
	}
	return (true);
}

void	infinite_dist(int type, t_ray *ray, float alpha)
{
	ray->dist = 1e30;
	if (type == 0)
	{
		if (alpha == 90.0f)
			ray->e_coord[Y] = -1e30;
		else
			ray->e_coord[Y] = 1e30;
	}
	else
	{
		if (alpha == 180.0f)
			ray->e_coord[X] = -1e30;
		else
			ray->e_coord[X] = 1e30;
	}
}

void	increment_coord(t_ray *ray, float *step, t_data *data)
{
	float	tmp[2];
	int		grid[2];

	tmp[X] = ray->e_coord[X] + step[X];
	tmp[Y] = ray->e_coord[Y] + step[Y];
	grid[X] = ray->e_coord[X] / data->tools.unit;
	grid[Y] = ray->e_coord[Y] / data->tools.unit;
	incr_y(data, grid, tmp);
	incr_x(data, grid, tmp);
	ray->e_coord[X] = tmp[X];
	ray->e_coord[Y] = tmp[Y];
}

static void	incr_y(t_data *data, int *grid, float *tmp)
{
	if (grid[Y] < 0)
	{
		tmp[Y] = 0.0f;
		grid[Y] = 0;
	}
	else if (grid[Y] > ft_array_len(data->map))
	{
		tmp[Y] = ft_array_len(data->map) + data->tools.unit - 1.0f;
		grid[X] = tmp[Y] / data->tools.unit;
	}
}

static void	incr_x(t_data *data, int *grid, float *tmp)
{
	if (grid[X] < 0)
	{
		tmp[X] = 0.0f;
		grid[X] = 0;
	}
	else if (grid[X] > (int)ft_strlen(data->map[grid[Y]]))
	{
		tmp[X] = ((float)ft_strlen(data->map[grid[Y]]) + 1.0f)
			* data->tools.unit;
		grid[X] = tmp[X] / data->tools.unit;
	}
}
