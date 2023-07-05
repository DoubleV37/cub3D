/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:56:21 by jduval            #+#    #+#             */
/*   Updated: 2023/07/05 12:04:38 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "type_bonus.h"

int32_t	color_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	if (a >= 255)
		a = 254;
	return (r << 24 | g << 16 | b << 8 | a);
}

void	reset_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_put_pixel(data->img[WALL], j, i, color_pixel(0, 0, 0, 0));
			mlx_put_pixel(data->img[DOOR], j, i, color_pixel(0, 0, 0, 0));
			if (j < 300 && i < 300)
			{
				mlx_put_pixel(data->img[PLAYER], j, i, color_pixel(0, 0, 0, 0));
				mlx_put_pixel(data->img[MAP], j, i, color_pixel(0, 0, 0, 0));
			}
			j++;
		}
		i++;
	}
}
