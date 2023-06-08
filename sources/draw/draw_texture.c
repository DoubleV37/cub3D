/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:44:26 by vviovi            #+#    #+#             */
/*   Updated: 2023/06/08 19:37:25 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*get_line_texture(int pos, mlx_texture_t texture)
{
	int				*line;
	unsigned int	i;
	unsigned int	j;

	line = malloc(sizeof(int) * texture.width * texture.bytes_per_pixel);
	if (line == NULL)
		return (NULL);
	i = 0;
	pos = pos * texture.bytes_per_pixel;
	while (i < texture.width * texture.bytes_per_pixel)
	{
		j = 0;
		while (j < texture.bytes_per_pixel)
		{
			line[i + j] = texture.pixels[pos + j];
			j++;
		}
		i += texture.bytes_per_pixel;
		pos += texture.width * texture.bytes_per_pixel;
	}
	return (line);
}

void	resize_texture(int *line_texture, int size, int scale_size)
{
	int	*resized_line;
	int	i;

	resized_line = malloc(sizeof(int) * scale_size);
	if (resized_line == NULL)
		return ;
	i = 0;
	while (i < scale_size)
	{
		resized_line[i] = line_texture[i * size / scale_size];
		i++;
	}
	free(line_texture);
	line_texture = resized_line;
}

float	scale_calculate(float dist, float size_texture)
{
	float	scale;

	scale = size_texture / dist;
	if (scale > size_texture)
		scale = size_texture;
	return (scale);
}
