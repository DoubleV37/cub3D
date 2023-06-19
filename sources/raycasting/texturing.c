/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:48 by jduval            #+#    #+#             */
/*   Updated: 2023/06/19 09:23:33 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

#include <stdio.h>

static void	wall_calculate(t_data *data, t_ray *ray, int n_ray, char side)
{
	float	scale;
	int		pos_tex;
	float	width_tex;
	int		*line_texture;
	float	nothing;

	scale = ray->pos[X] / data->tools.unit;
	if (side == 'V')
		scale = ray->pos[Y] / data->tools.unit;
	scale = modff(scale, &nothing);
	width_tex = data->textures.texture[ray->texture]->width;
	pos_tex = roundf(width_tex * scale);
	if (data->player.pos[Y] < ray->pos[Y] && side == 'H')
		pos_tex = width_tex - pos_tex;
	if (data->player.pos[X] > ray->pos[X] && side == 'V')
		pos_tex = width_tex - pos_tex;
	scale = scale_calculate(data->tools.dist, ray->dist_perp, width_tex);
	line_texture = get_line_texture(pos_tex,
			*(data->textures.texture[ray->texture]));
	draw_texture_line(data, line_texture, n_ray, scale);
}

void	draw_wall(t_data *data, t_ray *ray, int n_ray)
{
	int	x;

	x = 1919 - n_ray;
	if (ray->texture == NO || ray->texture == SO)
		wall_calculate(data, ray, x, 'H');
	else
		wall_calculate(data, ray, x, 'V');
}
