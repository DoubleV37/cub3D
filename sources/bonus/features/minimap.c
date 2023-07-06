/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:07:24 by jduval            #+#    #+#             */
/*   Updated: 2023/07/06 15:37:03 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include <stddef.h>
#include <math.h>
#include <stdio.h>

static uint32_t	which_area(t_data *data, float x, float y);

void	put_minimap(t_data *data, t_map *minimap)
{
	float		player[2];
	float		start[2];
	int			draw[2];
	uint32_t	color;

	player[X] = (data->player.pos[X] / SIZE) * minimap->unit;
	player[Y] = (data->player.pos[Y] / SIZE) * minimap->unit;
	start[X] = player[X] - minimap->space;
	start[Y] = player[Y] - minimap->space;
	draw[Y] = 0;
	while (draw[Y] < minimap->height)
	{
		draw[X] = 0;
		start[X] = player[X] - minimap->space;
		while (draw[X] < minimap->width)
		{
			color = which_area(data, start[X], start[Y]);
			mlx_put_pixel(data->img[MAP], draw[X], draw[Y], color);
			draw[X] += 1;
			start[X] = start[X] + 1.0f;
		}
		draw[Y] += 1;
		start[Y] = start[Y] + 1.0f;
	}
	draw[X] = minimap->width / 2 - minimap->unit / 4;
	draw[Y] = minimap->height / 2 - minimap->unit / 4;
	int	endx = draw[X] + minimap->unit / 2;
	int	endy = draw[Y] + minimap->unit / 2;
	while (draw[Y] < endy)
	{
		draw[X] = minimap->width / 2 - minimap->unit / 4;
		while (draw[X] < endx)
		{
			color = color_pixel(20, 20, 220, 254);
			mlx_put_pixel(data->img[MAP], draw[X], draw[Y], color);
			draw[X] += 1;
		}
		draw[Y] += 1;
	}
}

static uint32_t	which_area(t_data *data, float x1, float y1)
{
	int			len;
	uint32_t	color;
	t_door		*door;
	int			x = floorf(x1 / data->minimap.unit);
	int			y = floorf(y1 / data->minimap.unit);

	door = NULL;
	len = ft_array_len(data->map);
	if (y < 0 || y > len - 1)
		color = color_pixel(0, 0, 0, 254);
	else if (x < 0 || x > (int)ft_strlen(data->map[y]) - 1)
		color = color_pixel(0, 0, 0, 254);
	else if (data->map[y][x] == '1')
		color = color_pixel(190, 110, 0, 254);
	else if (data->map[y][x] == '0')
		color = color_pixel(255, 255, 255, 254);
	else if (data->map[y][x] == 'D')
	{
		door = find_door(&data->doors, x, y);
		if (door->status == OPEN)
			color = color_pixel(0, 200, 15, 254);
		else if (door->status == CLOSE)
			color = color_pixel(200, 0, 0, 254);
		else
			color = color_pixel(255, 0, 160, 254);
	}
	else
		color = color_pixel(0, 0, 0, 254);
	return (color);
}
