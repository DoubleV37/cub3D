/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:05:05 by jduval            #+#    #+#             */
/*   Updated: 2023/05/18 17:25:43 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d.h"

static void	fill_square(mlx_image_t *img, int x, int y, int unit, int flag)
{
	int x2;
	int y2;

	y *= unit;
	x *= unit;
	x2 = x + unit;
	y2 = y + unit;
	while (y < y2)
	{
		x = x2 - unit;
		while (x < x2)
		{
			if (flag == 1)
				mlx_put_pixel(img, x, y, color_pixel(0, 0, 0, 255));
			else
				mlx_put_pixel(img, x, y, color_pixel(128, 128, 128, 255));
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
				fill_square(data->img[MAP], j, i, data->setup.unit, 0);
			else if (data->map[i][j] && data->map[i][j] == '1')
				fill_square(data->img[MAP], j, i, data->setup.unit, 1);
			j++;
		}
		i++;
	}
}
