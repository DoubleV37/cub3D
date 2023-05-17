/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:05:05 by jduval            #+#    #+#             */
/*   Updated: 2023/05/17 18:02:36 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "includes/type.h"
#include <stddef.h>

static int32_t	color_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static void	fill_space(mlx_image_t *img, int i, int j, int unit)
{
	int x;
	int y;
	int limit;

	y = i * unit;
	i = y + unit;
	limit = j * unit + unit;
	while (y < i)
	{
		x = limit - unit;
		while (x < limit)
		{
			mlx_put_pixel(img, x, y, color_pixel(128, 128, 128, 255));
			x++;
		}
		y++;
	}
}

static void	fill_wall(mlx_image_t *img, int i, int j, int unit)
{
	int x;
	int y;
	int limit;

	y = i * unit;
	i = y + unit;
	limit = j * unit + unit;
	while (y < i)
	{
		x = limit - unit;
		while (x < limit)
		{
			mlx_put_pixel(img, x, y, color_pixel(0, 0, 0, 255));
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data, t_player *player)
{
	int x;
	int y;
	int limit;

	y = player->indexs[Y] * player->setup.unit + player->setup.unit / 3;
	i = y + (player->setup.unit / 3);
	limit = player->index[X] * player->setup.unit + 2 * (player->setup.unit / 3);
	while (y < i)
	{
		x = limit - (unit / 3);
		while (x < limit)
		{
			mlx_put_pixel(img, x, y, color_pixel(0, 0, 250, 255));
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
				fill_space(data->img, i, j, data->player.setup.unit);
			else if (data->map[i][j] && data->map[i][j] == '1')
				fill_wall(data->img, i, j, data->player.setup.unit);
			j++;
		}
		i++;
	}
}
