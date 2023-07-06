/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:05:05 by jduval            #+#    #+#             */
/*   Updated: 2023/07/06 10:07:09 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d_bonus.h"
#include "libft.h"
#include <stdlib.h>

static void	fill_floor(mlx_image_t *img, int start[2], int end[2])
{
	int	i;
	int	j;

	i = start[X];
	j = start[Y];
	while (j < end[Y])
	{
		i = start[X];
		while (i < end[X])
		{
			mlx_put_pixel(img, i, j, color_pixel(128, 128, 128, 255));
			i++;
		}
		j++;
	}
}

static void	fill_wall(mlx_image_t *img, int start[2], int end[2])
{
	int	i;
	int	j;

	i = start[X];
	j = start[Y];
	while (j < end[Y])
	{
		i = start[X];
		while (i < end[X])
		{
			mlx_put_pixel(img, i, j, color_pixel(0, 0, 255, 255));
			i++;
		}
		j++;
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

static void	fill_door(mlx_image_t *img, int start[2], int end[2])
{
	int	i;
	int	j;

	i = start[X];
	j = start[Y];
	while (j < end[Y])
	{
		i = start[X];
		while (i < end[X])
		{
			mlx_put_pixel(img, i, j, color_pixel(255, 0, 0, 255));
			i++;
		}
		j++;
	}
}

static void	launch_draw(t_data *data, int start[2], int end[2], int index[2])
{
	if (start[X] > 300)
		start[X] = 300;
	if (start[Y] > 300)
		start[Y] = 300;
	if (end[X] > 300)
		end[X] = 300;
	if (end[Y] > 300)
		end[Y] = 300;
	if (data->map[index[0]][index[1]]
		&& data->map[index[0]][index[1]] == '0')
		fill_floor(data->img[MAP], start, end);
	else if (data->map[index[0]][index[1]]
		&& data->map[index[0]][index[1]] == '1')
		fill_wall(data->img[MAP], start, end);
	else if (data->map[index[0]][index[1]]
		&& data->map[index[0]][index[1]] == 'D')
		fill_door(data->img[MAP], start, end);
}

void	draw_map(t_data *data)
{
	int	start[2];
	int	end[2];
	int	index[2];

	index[0] = (int)((data->player.pos[Y] - 5*SIZE) / SIZE);
	start[Y] = 0;
	ft_printf("EE start[Y] = %d | i : %d\n", start[Y], index[0]);
	if (index[0] < 0)
	{
		start[Y] = (index[0] * -1) * 30;
		index[0] = 0;
	}
	ft_printf("start[Y] = %d | i : %d\n", start[Y], index[0]);
	end[Y] = start[Y] + 30 - ((int)(data->player.pos[Y]) % SIZE * 30 / SIZE);
	start[Y] -= 30 - end[Y] % 30;
	while (index[0] <= (int)(data->player.pos[Y] / SIZE + 5) && data->map[index[0]] != NULL)
	{
		index[1] = (int)(data->player.pos[X]) / SIZE - 5;
		start[X] = 0;
		if (index[1] < 0)
		{
			start[X] = (index[1] * -1) * 30;
			index[1] = 0;
		}
		end[X] = start[X] + 30 - ((int)(data->player.pos[X]) % SIZE * 30 / SIZE);
		while (data->map[index[0]][index[1]] != '\0' && index[1] <= (int)(data->player.pos[X] / SIZE + 5))
		{
			launch_draw(data, start, end, index);
			index[1]++;
			start[X] = end[X];
			end[X] += 30;
		}
		start[Y] = end[Y];
		end[Y] += 30;
		index[0]++;
	}
	fill_border(data->img[MAP], 30);
}
