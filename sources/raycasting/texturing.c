/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:48 by jduval            #+#    #+#             */
/*   Updated: 2023/06/17 21:03:39 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

#include <stdio.h>

static int	pos_in_texture(t_ray *ray, t_data *data)
{
	float	percent;
	float	pos;
	int		coord;
	int		i = ray->texture;

	if (ray->texture == NO || ray->texture == SO)
		pos = ray->pos[X];
	else
		pos = ray->pos[Y];
	percent = modff(pos / data->tools.unit, &pos);
	coord = roundf(data->textures.texture[i]->width * percent);
	return (coord);
}

void	draw_wall(t_data *data, t_ray *ray, int n_ray)
{
	int		x;
	int		pos_text;
	float	height;
	float	scalefactor;
	int		start;
	int32_t	color;	

	x = (WIDTH - 1) - n_ray;
	pos_text = pos_in_texture(ray, data);
	scalefactor = (data->textures.texture[ray->texture]->height * data->tools.unit) / HEIGHT;
	height = ray->dist_perp * scalefactor;
	start = (HEIGHT / 2) - (ray->dist_perp / 2);
	x = start;
	while (start < x + ray->dist_perp)
	{
		if (ray->texture == NO)
			color = color_pixel(255, 0, 0, 255);
		else if (ray->texture == SO)
			color = color_pixel(0, 255, 0, 255);
		else if (ray->texture == EA)
			color = color_pixel(0, 0, 255, 255);
		else 
			color = color_pixel(20, 150, 150, 255);
		if (start >= 0 && start < HEIGHT)
			mlx_put_pixel(data->img[WALL], WIDTH - 1 - n_ray, start, color);
		start++;
	}
}
