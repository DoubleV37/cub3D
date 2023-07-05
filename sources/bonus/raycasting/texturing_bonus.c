/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:48 by jduval            #+#    #+#             */
/*   Updated: 2023/07/04 17:35:09 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <math.h>
#include <stdlib.h>

static float	init_start(float step, float length, int *y);
static void		put_texture(t_data *data, t_ray *ray, float posx, float lengh);
static int32_t	get_pixel(uint32_t *text, float x, float y);

void	draw_texture(t_data *data, t_ray *ray, int nbr_ray)
{
	float	length;
	float	pos_tex;
	float	width_tex;

	ray->num_ray = WIDTH - 1 - nbr_ray;
	if (ray->side == V)
		pos_tex = ray->pos[Y] / (float)SIZE;
	else
		pos_tex = ray->pos[X] / (float)SIZE;
	pos_tex = modff(pos_tex, &width_tex);
	width_tex = SIZE;
	pos_tex = roundf(width_tex * pos_tex);
	if (ray->texture == SO || ray->texture == WE)
		pos_tex = width_tex - pos_tex - 1;
	if (ray->dist_perp <= 0.0f)
		ray->dist_perp = 1.0f;
	length = (data->unit / ray->dist_perp) * data->dfocal;
	put_texture(data, ray, pos_tex, length);
	return ;
}

static void	put_texture(t_data *data, t_ray *ray, float posx, float length)
{
	int		y;
	int		end;
	float	step;
	float	posy;
	int32_t	color;

	step = SIZE / length;
	posy = init_start(step, length, &y);
	end = HEIGHT / 2 + length;
	if (end > HEIGHT)
		end = HEIGHT - 1;
	while (y <= end && y < HEIGHT - 1)
	{
		color = get_pixel(data->text[ray->texture], posx, posy);
		if (color != -1)
			mlx_put_pixel(data->img[ray->img], ray->num_ray, y, color);
		posy += step;
		y++;
	}
	return ;
}

static float	init_start(float step, float length, int *y)
{
	float	result;

	result = 0.0f;
	(*y) = HEIGHT / 2 - length / 2;
	if ((*y) < 0)
	{
		result = step * abs((*y));
		(*y) = 0;
	}
	return (result);
}

static int32_t	get_pixel(uint32_t *text, float x, float y)
{
	int	index;

	index = (int)x + (int)y * SIZE;
	if (index >= SIZE * SIZE)
		return (-1);
	return (text[index]);
}
