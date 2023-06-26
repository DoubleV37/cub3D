/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:48 by jduval            #+#    #+#             */
/*   Updated: 2023/06/26 08:23:37 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static void		draw_texture(t_data *data, int32_t *text, float posx, float lengh, int x);
static int32_t	get_pixel(int32_t *text, float x, float y);

static int	wall_calculate(t_data *data, t_ray *ray)
{
	float	lengh;
	float	pos_tex;
	float	width_tex;
	float	dfoc;

	if (ray->texture == EA || ray->texture == WE)
		pos_tex = ray->pos[Y] / data->unit;
	else
		pos_tex = ray->pos[X] / data->unit;
	pos_tex = modff(pos_tex, &width_tex);
	width_tex = SIZE;
	pos_tex = roundf(width_tex * pos_tex);
	if (ray->texture == SO || ray->texture == WE)
		pos_tex = width_tex - pos_tex - 1;
	if (ray->dist_perp <= 0.0f)
		ray->dist_perp = 1.0f;
	dfoc = (WIDTH / 2.0f) / (tanf(FOV / 2.0f * RAD_CONV));
	lengh = (data->unit / ray->dist_perp) * dfoc;
	draw_texture(data, data->text[ray->texture], pos_tex, lengh, ray->num_ray);
	return (0);
}

int	draw_wall(t_data *data, t_ray *ray)
{
	ray->texture_size = (data->textures.texture[ray->texture]->width + 1)
		* data->textures.texture[ray->texture]->bytes_per_pixel;
	ray->num_ray = 1919 - ray->num_ray;
	if (wall_calculate(data, ray) == 1)
		return (1);
	return (0);
}

static int32_t	get_pixel(int32_t *text, float x, float y);

static void	draw_texture(t_data *data, int32_t *text, float posx, float lengh, int x)
{
	int		y;
	int		end;
	float	step;
	float	posy;
	int32_t	color;

	posy = 0.0f;
	step = SIZE / lengh;
	y = HEIGHT / 2 - lengh / 2;
	if (y < 0)
	{
		posy = step * abs(y);
		y = 0;
	}
	end = HEIGHT / 2 + lengh;
	if (end > HEIGHT)
		end = HEIGHT - 1;
	while (y <= end && y < HEIGHT - 1)
	{
		color = get_pixel(text, posx, posy);
		if (color != -1)
			mlx_put_pixel(data->img[WALL], x, y, color);
		posy += step;
		y++;
	}
	return ;
}

static int32_t	get_pixel(int32_t *text, float x, float y)
{
	int index;

	index = (int)x + (int)y * SIZE;
	if (index >= SIZE * SIZE)
		return (-1);
	return (text[index]);
	
}
