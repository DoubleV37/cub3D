/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:05:05 by jduval            #+#    #+#             */
/*   Updated: 2023/07/05 10:29:18 by vviovi           ###   ########.fr       */
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

#include <stdio.h>

void	draw_map(t_data *data)
{
	int	start[2];
	int	end[2];
	int	i;
	int	j;

//ne fais pas le print des murs qd vide et mur seulement qd mur et sol
//decalage surement à cause des imprecisions de float
	i = (int)(data->player.pos[Y]) / SIZE - 5;
	start[Y] = 0;
	//ft_printf("EE start[Y] = %d | i : %d\n", start[Y], i);
	if (i < 0)
	{
		start[Y] = (i * -1) * 30;
		i = 0;
	}
	//ft_printf("start[Y] = %d | i : %d\n", start[Y], i);
	//end[Y] = start[Y] + 30;
	//if ((int)(data->player.pos[Y]) % SIZE != 0)
		end[Y] = start[Y] + 30 - ((int)(data->player.pos[Y]) % SIZE * 30 / SIZE);
	//ft_printf("end[Y] = %d\n", end[Y]);
	while (i < (int)(data->player.pos[Y]) / SIZE + 5 && data->map[i] != NULL)
	{
		j = (int)(data->player.pos[X]) / SIZE - 5;
		start[X] = 0;
		if (j < 0)
		{
			start[X] = (j * -1) * 30;
			j = 0;
		}
		//ft_printf("i = %d, j = %d\n", i, j);
		//end[X] = start[X] + 30;
		//ft_printf("pos[X] = %d\n", (int)data->player.pos[X] % SIZE);
		//if ((int)(data->player.pos[X]) % SIZE != 0)
			end[X] = start[X] + 30 - ((int)(data->player.pos[X]) % SIZE * 30 / SIZE);
		while (data->map[i][j] != '\0' && j < (int)(data->player.pos[X]) / SIZE + 5)
		{
			//ft_printf("start[X] = %d, start[Y] = %d, end[X] = %d, end[Y] = %d\n", start[X], start[Y], end[X], end[Y]);
			if (data->map[i][j] && data->map[i][j] == '0')
				fill_floor(data->img[MAP], start, end);
			else if (data->map[i][j] && data->map[i][j] == '1')
				fill_wall(data->img[MAP], start, end);
			else if (data->map[i][j] && data->map[i][j] == 'D')
				fill_door(data->img[MAP], start, end);
			j++;
			start[X] = end[X];
			//if (start[X] % 30 == 0)
			end[X] += 30;
			//else
			//	end[X] += start[X] - start[X] % 30;
		}
		start[Y] = end[Y];
		//if (start[Y] % 30 == 0)
		end[Y] += 30;
		//else
		//	end[Y] += start[Y] - start[Y] % 30;
		i++;
	}
	fill_border(data->img[MAP], 30);
}
