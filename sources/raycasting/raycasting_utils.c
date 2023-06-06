/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:51:47 by jduval            #+#    #+#             */
/*   Updated: 2023/06/06 20:34:37 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

static bool	is_in_screen(int x, int y, char **map, t_ray *ray)
{
	int	len_y;
	int	len_x;

	len_y = ft_array_len(map);
	if (y <= 0 || y > len_y)
	{
		ray->dist = 1e30;
		return (false);
	}
	len_x = (int)ft_strlen(map[y]);
	if (x <= 0 || x > len_x)
	{
		ray->dist = 1e30;
		return (false);
	}
	return (true);
}

static void	angle_spe(int type, t_ray *ray, float alpha)
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

static void	first_horizontal(t_ray *ray, float alpha, float *step, float unit)
{
	float	y;
	float	x;

	if (alpha > 0.0f && alpha < 180.0f)
	{
		y = (floorf(ray->s_coord[Y] / unit) * unit - 1.0f);
		step[Y] = -unit;
	}
	else
	{
		y = floorf(ray->s_coord[Y] / unit) * unit + unit;
		step[Y] = unit;
	}
	ray->e_coord[Y] = y;
	if (alpha >= 180.0f && alpha <= 360.0f)
		x = (y - ray->s_coord[Y]) / (ray->tan_alpha * (-1.0f));
	else
		x = (ray->s_coord[Y] - y) / ray->tan_alpha;
	//ray->dist = sqrtf(powf(x, 2.0f) + powf(y, 2.0f));
	printf("1.1dist_h = %f\n", ray->dist);
	ray->e_coord[X] = ray->s_coord[X] + x;
	step[X] = unit / ray->tan_alpha;
	if ((alpha >= 180.0f && alpha <= 270.0f && step[X] > 0.0f)
		|| (alpha >= 270.0f && alpha <= 360.0f && step[X] < 0.0f))
		step[X] *= -1.0f;
	return ;
}

static void	first_vertical(t_ray *ray, float alpha, float *step, float unit)
{
	float	y;
	float	x;

	if (alpha >= 90.0f && alpha < 270.0f)
	{
		ray->e_coord[X] = (floorf(ray->s_coord[X] / unit) * unit - 1);
		step[X] = -unit;
	}
	else
	{
		ray->e_coord[X] = floorf(ray->s_coord[X] / unit) * unit + unit;
		step[X] = unit;
	}
	x = ray->s_coord[X] - ray->e_coord[X];
	y = x * ray->tan_alpha;
	//ray->dist = sqrtf(powf(x, 2.0f) + powf(y, 2.0f));
	printf("2.1dist_v = %f\n", ray->dist);
	ray->e_coord[Y] = ray->s_coord[Y] + y;
	step[Y] = unit * ray->tan_alpha;
	if ((alpha >= 270.0f && alpha <= 360.0f && step[Y] < 0.0f)
		|| (alpha >= 0.0f && alpha <= 90.0f && step[Y] > 0.0f))
		step[Y] *= -1.0f;
}

static void	incr_coord(t_ray *ray, float *step, t_data *data)
{
	float	tmp[2];
	int		grid[2];

	tmp[X] = ray->e_coord[X] + step[X];
	tmp[Y] = ray->e_coord[Y] + step[Y];
	grid[X] = ray->e_coord[X] / data->tools.unit; 
	grid[Y] = ray->e_coord[Y] / data->tools.unit; 
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
	if (grid[X] < 0)
	{
		tmp[X] = 0.0f;
		grid[X] = 0;
	}
	else if (grid[X] > (int)ft_strlen(data->map[grid[Y]]))
	{
		tmp[X] = ((float)ft_strlen(data->map[grid[Y]]) + 1.0f) * data->tools.unit;
		grid[X] = tmp[X] / data->tools.unit;
	}
	ray->e_coord[X] = tmp[X];
	ray->e_coord[Y] = tmp[Y];
}

void	find_h_wall(t_data *data, t_ray *ray, float alpha)
{
	float	step[2];
	int		x;
	int		y;

	if (alpha == 0.0f || alpha == 360.0f || alpha == 180.0f)
	{
		angle_spe(1, ray, alpha);
		return ;
	}
	first_horizontal(ray, alpha, step, data->tools.unit);
	x = ray->e_coord[X] / data->tools.unit;
	y = ray->e_coord[Y] / data->tools.unit;
	while (data->map[y][x] == '0')
	{
		incr_coord(ray, step, data);
		//ray->e_coord[X] += step[X];
		//ray->e_coord[Y] += step[Y];
		//ray->dist += hypotenuse;
		x = ray->e_coord[X] / data->tools.unit;
		y = ray->e_coord[Y] / data->tools.unit;
	}
	ray->dist = sqrtf(powf(ray->e_coord[X] - ray->s_coord[X], 2.0f) + powf(ray->e_coord[Y] - ray->s_coord[Y], 2.0f));
	return ;
}

void	find_v_wall(t_data *data, t_ray *ray, float alpha)
{
	//float	hypotenuse;
	float	step[2];
	int		x;
	int		y;

	if (alpha == 90.0f || alpha == 270.0f)
	{
		angle_spe(0, ray, alpha);
		return ;
	}
	first_vertical(ray, alpha, step, data->tools.unit);
	//hypotenuse = sqrtf(powf(step[X], 2.0f) + powf(step[Y], 2.0f));
//	printf("2hyp_v = %f\n", hypotenuse);
	x = ray->e_coord[X] / data->tools.unit;
	y = ray->e_coord[Y] / data->tools.unit;
	while (is_in_screen(x, y, data->map, ray) == true && data->map[y][x] == '0')
	{
		incr_coord(ray, step, data);
		//ray->e_coord[X] += step[X];
		//ray->e_coord[Y] += step[Y];
		//ray->dist += hypotenuse;
		x = ray->e_coord[X] / data->tools.unit;
		y = ray->e_coord[Y] / data->tools.unit;
	}
	ray->dist = sqrtf(powf(ray->e_coord[X] - ray->s_coord[X], 2.0f) + powf(ray->e_coord[Y] - ray->s_coord[Y], 2.0f));
}
