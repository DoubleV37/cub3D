/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:10:32 by jduval            #+#    #+#             */
/*   Updated: 2023/06/20 11:08:02 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d.h"
#include <math.h>

static void	trace_line(mlx_image_t *img, int32_t color, float *pos, float steps)
{
	float	x0;
	float	y0;
	float	xinc;
	float	yinc;

	x0 = pos[X];
	y0 = pos[Y];
	xinc = (pos[X + 2] - pos[X]) / steps;
	yinc = (pos[Y + 2] - pos[Y]) / steps;
	while (steps >= 0)
	{
		if (x0 < 0 || x0 > WIDTH - 1 || y0 < 0 || y0 > HEIGHT - 1)
			break ;
		mlx_put_pixel(img, ceilf(x0), ceilf(y0), color);
		x0 += xinc;
		y0 += yinc;
		steps--;
	}
}

void	draw_line(mlx_image_t *img, float *pos, int32_t color)
{
	float	steps;
	float	dx;
	float	dy;

	dx = pos[X + 2] - pos[X];
	dy = pos[Y + 2] - pos[Y];
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	trace_line(img, color, pos, steps);
}

void	draw_pov(t_data *data, t_player *player, int flag)
{
	float	coord[4];

	coord[X] = player->pos[X];
	coord[Y] = player->pos[Y];
	coord[X + 2] = (player->dir[X] * 10.0f) + player->pos[X];
	coord[Y + 2] = (player->dir[Y] * 10.0f) + player->pos[Y];
	if (flag == 1)
		draw_line(data->img[PLAYER], coord, color_pixel(0, 0, 0, 255));
	else
		draw_line(data->img[PLAYER], coord, color_pixel(255, 255, 255, 0));
	return ;
}
