/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:55:29 by jduval            #+#    #+#             */
/*   Updated: 2023/05/18 11:48:39 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d.h"

void	draw_player(mlx_image_t *img, int *pos, int unit, int flag)
{
	int x;
	int y;
	int end_x;
	int	end_y;

	y = pos[Y] * unit + unit / 3;
	end_y = y + (unit / 3);
	end_x = pos[X] * unit + 2 * (unit / 3);
	while (y < end_y)
	{
		x = end_x - (unit / 3);
		while (x < end_x)
		{
			if (flag == 1)
				mlx_put_pixel(img, x, y, color_pixel(0, 0, 250, 255));
			else
				mlx_put_pixel(img, x, y, color_pixel(0, 0, 0, 0));
			x++;
		}
		y++;
	}
}
