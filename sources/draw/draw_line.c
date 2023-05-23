/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:10:32 by jduval            #+#    #+#             */
/*   Updated: 2023/05/23 17:31:01 by jduval           ###   ########.fr       */
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
	float	coordinate[4];

	coordinate[X] = player->pos[X];
	coordinate[Y] = player->pos[Y];
	coordinate[X + 2] = (data->tools.dir[X] * 20.0f) + player->pos[X];
	coordinate[Y + 2] = (data->tools.dir[Y] * 20.0f) + player->pos[Y];
	if (flag == 1)
		draw_line(data->img[PLAYER], coordinate, color_pixel(255, 255, 255, 255));
	else
		draw_line(data->img[PLAYER], coordinate, color_pixel(255, 255, 255, 0));
	return ;
}
