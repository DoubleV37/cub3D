/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:48 by jduval            #+#    #+#             */
/*   Updated: 2023/06/20 13:19:33 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	wall_calculate(t_data *data, t_ray *ray, char side)
{
	float	scale;
	int		pos_tex;
	float	width_tex;
	int		line_texture[ray->texture_size];

	ray->texture_size = data->textures.texture[ray->texture]->width;
	scale = ray->pos[X] / data->unit;
	if (side == 'V')
		scale = ray->pos[Y] / data->unit;
	scale = modff(scale, &width_tex);
	width_tex = data->textures.texture[ray->texture]->width;
	pos_tex = roundf(width_tex * scale);
	if (data->player.pos[Y] < ray->pos[Y] && side == 'H')
		pos_tex = width_tex - pos_tex - 1;
	if (data->player.pos[X] > ray->pos[X] && side == 'V')
		pos_tex = width_tex - pos_tex - 1;
	scale = scale_calculate(data->dist, ray->dist_perp, width_tex);
	get_line_texture(pos_tex, *(data->textures.texture[ray->texture]),
		line_texture);
	draw_texture_line(data, line_texture, ray, scale);
}

void	draw_wall(t_data *data, t_ray *ray)
{
	ray->texture_size = (data->textures.texture[ray->texture]->width + 1)
		* data->textures.texture[ray->texture]->bytes_per_pixel;
	ray->num_ray = 1919 - ray->num_ray;
	if (ray->texture == NO || ray->texture == SO)
		wall_calculate(data, ray, 'H');
	else
		wall_calculate(data, ray, 'V');
}
