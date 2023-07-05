/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:55:29 by jduval            #+#    #+#             */
/*   Updated: 2023/07/05 10:38:13 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d_bonus.h"

void	draw_player(mlx_image_t *img, t_player *player, int unit, int flag)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	// x2 = player->pos[X] + unit / 10;
	// y1 = player->pos[Y] - unit / 10;
	// y2 = player->pos[Y] + unit / 10;
	(void) player;
	(void) unit;
	x2 = 168;
	y1 = 162;
	y2 = 168;
	while (y1 < y2)
	{
		//x1 = player->pos[X] - unit / 10;
		x1 = 162;
		while (x1 < x2)
		{
			if (flag == 1)
				mlx_put_pixel(img, x1, y1, color_pixel(0, 0, 0, 255));
			else
				mlx_put_pixel(img, x1, y1, color_pixel(0, 0, 0, 0));
			x1++;
		}
		y1++;
	}
}
