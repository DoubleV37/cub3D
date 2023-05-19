/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:10:32 by jduval            #+#    #+#             */
/*   Updated: 2023/05/19 12:11:00 by jduval           ###   ########.fr       */
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
