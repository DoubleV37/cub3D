/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:44:26 by vviovi            #+#    #+#             */
/*   Updated: 2023/06/01 10:50:59 by vviovi           ###   ########.fr       */
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

int	scale_calculate(int dist, int size_texture)
{
	int	scale;

	scale = size_texture / (dist / 10); //temporaire à voir qd on aura la 3d
	if (scale > size_texture)
		scale = size_texture;
	return (scale);
}
