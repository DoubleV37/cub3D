/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:05:05 by jduval            #+#    #+#             */
/*   Updated: 2023/06/20 14:26:07 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d.h"
#include <stdlib.h>

static void	fill_floor(mlx_image_t *img, int x, int y, int unit)
{
	int	x2;
	int	y2;

	y *= unit;
	x *= unit;
	x2 = x + unit;
	y2 = y + unit;
	while (y < y2)
	{
		x = x2 - unit;
		while (x < x2)
		{
			mlx_put_pixel(img, x, y, color_pixel(128, 128, 128, 255));
			x++;
		}
		y++;
	}
}

static void	fill_wall(mlx_image_t *img, int x, int y, int unit)
{
	int	x2;
	int	y2;

	y *= unit;
	x *= unit;
	x2 = x + unit;
	y2 = y + unit;
	while (y < y2)
	{
		x = x2 - unit;
		while (x < x2)
		{
			mlx_put_pixel(img, x, y, color_pixel(0, 0, 255, 255));
			x++;
		}
		y++;
	}
}

static void	fill_border(mlx_image_t *img, int unit)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (x % (int)unit == 0)
				mlx_put_pixel(img, x, y, color_pixel(0, 0, 0, 255));
			if (y % (int)unit == 0)
				mlx_put_pixel(img, x, y, color_pixel(0, 0, 0, 255));
			x++;
		}
		y++;
	}
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] && data->map[i][j] == '0')
				fill_floor(data->img[MAP], j, i, data->unit);
			else if (data->map[i][j] && data->map[i][j] == '1')
				fill_wall(data->img[MAP], j, i, data->unit);
			j++;
		}
		i++;
	}
	fill_border(data->img[MAP], data->unit);
}
