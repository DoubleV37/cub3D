/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:44:26 by vviovi            #+#    #+#             */
/*   Updated: 2023/05/29 10:48:23 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*get_line_texture(int x, int y, mlx_texture_t texture, int dist)
{
	ft_printf("x: %d, y: %d\n", x, y);
	ft_printf("texture.width: %d, texture.height: %d\n", texture.width, texture.height);
	ft_printf("dist: %d\n", dist);
	ft_printf("byte per pixel %d", texture.bytes_per_pixel);
	return (NULL);
}
