/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:07:24 by jduval            #+#    #+#             */
/*   Updated: 2023/07/07 09:15:31 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include <stddef.h>
#include <math.h>

static uint32_t	which_area(t_data *data, int x, int y);
static void		draw_player_on_map(t_data *data, t_map *minimap);
static uint32_t	door_status(t_door *head, int x, int y);

void	put_minimap(t_data *data, t_map *minimap)
{
	float		player[2];
	int			point[2];
	int			draw[2];
	uint32_t	color;

	player[X] = (data->player.pos[X] / SIZE) * minimap->unit;
	player[Y] = (data->player.pos[Y] / SIZE) * minimap->unit;
	point[X] = player[X] - minimap->space;
	point[Y] = player[Y] - minimap->space;
	draw[Y] = -1;
	while (++draw[Y] < minimap->height)
	{
		draw[X] = -1;
		point[X] = player[X] - minimap->space;
		while (++draw[X] < minimap->width)
		{
			color = which_area(data, floor(point[X] / minimap->unit),
					floor(point[Y] / minimap->unit));
			mlx_put_pixel(data->img[MAP], draw[X], draw[Y], color);
			point[X] += 1;
		}
		point[Y] += 1;
	}
	draw_player_on_map(data, minimap);
}

static void	draw_player_on_map(t_data *data, t_map *minimap)
{
	int			point[2];
	int			end[2];
	uint32_t	color;

	point[X] = minimap->width / 2 - minimap->unit / 4;
	point[Y] = minimap->height / 2 - minimap->unit / 4;
	end[X] = point[X] + minimap->unit / 2;
	end[Y] = point[Y] + minimap->unit / 2;
	while (point[Y] < end[Y])
	{
		point[X] = minimap->width / 2 - minimap->unit / 4;
		while (point[X] < end[X])
		{
			color = color_pixel(20, 20, 220, 254);
			mlx_put_pixel(data->img[MAP], point[X], point[Y], color);
			point[X] += 1;
		}
		point[Y] += 1;
	}
}

static uint32_t	which_area(t_data *data, int x, int y)
{
	int			len;
	uint32_t	color;

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
		color = door_status(data->doors, x, y);
	else
		color = color_pixel(0, 0, 0, 254);
	return (color);
}

static uint32_t	door_status(t_door *head, int x, int y)
{
	uint32_t	color;
	t_door		*door;

	door = find_door(&head, x, y);
	if (door->status == OPEN)
		color = color_pixel(0, 200, 15, 254);
	else if (door->status == CLOSE)
		color = color_pixel(200, 0, 0, 254);
	else
		color = color_pixel(255, 0, 160, 254);
	return (color);
}
