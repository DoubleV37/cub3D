/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:59:39 by jduval            #+#    #+#             */
/*   Updated: 2023/06/08 11:12:37 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	first_horizontal(t_ray *ray, float alpha, float *step, float unit);
static void	first_vertical(t_ray *ray, float alpha, float *step, float unit);
void	find_h_wall(t_data *data, t_ray *ray, float alpha)
{
	float	step[2];
	int		x;
	int		y;

	if (alpha == 0.0f || alpha == 360.0f || alpha == 180.0f)
	{
		infinite_dist(1, ray, alpha);
		return ;
	}
	first_horizontal(ray, alpha, step, data->tools.unit);
	x = ray->e_coord[X] / data->tools.unit;
	y = ray->e_coord[Y] / data->tools.unit;
	if (ray_in_angle(ray, data, alpha) == true)
		return ;
	//printf("horizontal x = %i\ty = %i\n", x, y);
	//printf("1horizontal posx = %f\tposy = %f\n", ray->e_coord[X], ray->e_coord[Y]);
	while (is_in_screen(x, y, data->map, ray) == true && data->map[y][x] == '0')
	{
	//	printf("horizontal x = %i\ty = %i\n", x, y);
	//	printf("horizontal posx = %f\tposy = %f\n", ray->e_coord[X], ray->e_coord[Y]);
		increment_coord(ray, step, data);
		x = ray->e_coord[X] / data->tools.unit;
		y = ray->e_coord[Y] / data->tools.unit;
		if (ray_in_angle(ray, data, alpha) == true)
			return ;
	}
	return ;
}

void	find_v_wall(t_data *data, t_ray *ray, float alpha)
{
	float	step[2];
	int		x;
	int		y;

	if (alpha == 90.0f || alpha == 270.0f)
	{
		infinite_dist(0, ray, alpha);
		return ;
	}
	first_vertical(ray, alpha, step, data->tools.unit);
	x = ray->e_coord[X] / data->tools.unit;
	y = ray->e_coord[Y] / data->tools.unit;
	if (ray_in_angle(ray, data, alpha) == true)
		return ;
	//printf("vertical x = %i\ty = %i\n", x, y);
	//printf("1vertical posx = %f\tposy = %f\n", ray->e_coord[X], ray->e_coord[Y]);
	while (is_in_screen(x, y, data->map, ray) == true && data->map[y][x] == '0')
	{
	//	printf("vertical x = %i\ty = %i\n", x, y);
	//	printf("vertical posx = %f\tposy = %f\n", ray->e_coord[X], ray->e_coord[Y]);
		increment_coord(ray, step, data);
		x = ray->e_coord[X] / data->tools.unit;
		y = ray->e_coord[Y] / data->tools.unit;
		if (ray_in_angle(ray, data, alpha) == true)
			return ;
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
//	if (alpha > 180.0f && alpha < 360.0f)
//		x = (y - ray->s_coord[Y]) / (ray->tan_alpha * (-1.0f));
//	else
		x = (ray->s_coord[Y] - y) / ray->tan_alpha;
	ray->e_coord[X] = floorf(ray->s_coord[X] + x);
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

	if (alpha > 90.0f && alpha < 270.0f)
	{
		ray->e_coord[X] = floorf(ray->s_coord[X] / unit) * unit - 1.0f;
		step[X] = -unit;
	}
	else
	{
		ray->e_coord[X] = floorf(ray->s_coord[X] / unit) * unit + unit;
		step[X] = unit;
	}
	x = ray->s_coord[X] - ray->e_coord[X];
	y = x * ray->tan_alpha;
	ray->e_coord[Y] = floorf(ray->s_coord[Y] + y);
	step[Y] = unit * ray->tan_alpha;
	if ((alpha >= 270.0f && alpha <= 360.0f && step[Y] < 0.0f)
		|| (alpha >= 0.0f && alpha <= 90.0f && step[Y] > 0.0f))
		step[Y] *= -1.0f;
}
