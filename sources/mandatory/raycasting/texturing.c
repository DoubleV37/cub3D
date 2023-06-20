/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:48 by jduval            #+#    #+#             */
/*   Updated: 2023/06/20 14:26:42 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdlib.h>

static int	wall_calculate(t_data *data, t_ray *ray)
{
	float	scale;
	int		pos_tex;
	float	width_tex;
	int		*line_texture;

	line_texture = malloc(sizeof(int) * ray->texture_size);
	if (line_texture == NULL)
		return (1);
	ray->texture_size = data->textures.texture[ray->texture]->width;
	if (ray->texture == EA || ray->texture == WE)
		scale = ray->pos[Y] / data->unit;
	else
		scale = ray->pos[X] / data->unit;
	scale = modff(scale, &width_tex);
	width_tex = data->textures.texture[ray->texture]->width;
	pos_tex = roundf(width_tex * scale);
	if (ray->texture == 'H' || ray->texture == 'V')
		pos_tex = width_tex - pos_tex - 1;
	scale = scale_calculate(data->dist, ray->dist_perp, width_tex);
	get_line_texture(pos_tex, *(data->textures.texture[ray->texture]),
		line_texture);
	draw_texture_line(data, line_texture, ray, scale);
	free(line_texture);
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
