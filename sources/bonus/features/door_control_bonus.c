/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_control_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:17:00 by jduval            #+#    #+#             */
/*   Updated: 2023/06/30 17:55:35 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <stdlib.h>
#include <stdio.h>

static void	fill_door(mlx_image_t *img, int x, int y, int unit, int type);

void	door_control(t_data *data)
{
	t_door	*door;
	t_card	view;

	if (door_around_player(data->map, data->player.indexs) == false)
		return ;
	view = view_of_player(data->player.angle);
	door = is_looking_a_door(&data->doors, data->map, view, data->player.indexs);
	if (door == NULL)
		return ;
	if (door->open == true)
		fill_door(data->img[MAP], door->index[X], door->index[Y], SIZE, 0);
	else
		fill_door(data->img[MAP], door->index[X], door->index[Y], SIZE, 1);
	//if (door->open == true)
	//	closing_door(data, door);
	//else
	//	opening_door(data, door)
	door->open ^= true;
}

static void	fill_door(mlx_image_t *img, int x, int y, int unit, int type)
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
			if (type == 0)
				mlx_put_pixel(img, x, y, color_pixel(255, 0, 0, 255));
			else
				mlx_put_pixel(img, x, y, color_pixel(0, 255, 0, 255));
			x++;
		}
		y++;
	}
}
