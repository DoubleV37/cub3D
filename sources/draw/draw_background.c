/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:22:27 by vviovi            #+#    #+#             */
/*   Updated: 2023/06/09 17:21:18 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background_ceiling(t_data *data)
{
	int		h;
	int		w;
	int32_t	color;

	color = color_pixel(data->textures.color_ceil[R],
			data->textures.color_ceil[G], data->textures.color_ceil[B], 255);
	h = 0;
	while (h < HEIGHT / 2)
	{
		w = 0;
		while (w < WIDTH)
		{
			mlx_put_pixel(data->img[WALL], w, h, color);
			w++;
		}
		h++;
	}
}

void	draw_background_floor(t_data *data)
{
	int		h;
	int		w;
	int32_t	color;

	color = color_pixel(data->textures.color_floor[R],
			data->textures.color_floor[G], data->textures.color_floor[B], 255);
	h = HEIGHT / 2;
	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			mlx_put_pixel(data->img[WALL], w, h, color);
			w++;
		}
		h++;
	}
}
