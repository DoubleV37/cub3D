/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:44:26 by vviovi            #+#    #+#             */
/*   Updated: 2023/06/16 17:31:33 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

void	draw_texture_line(t_data *data, int *line_texture, int x, int length)
{
	int		i;
	int		y;
	int32_t	color;

	i = length / 2 * 4;
	y = HEIGHT / 2;
	while (i != 0 && y != 0)
	{
		color = color_pixel(line_texture[i], line_texture[i + 1],
				line_texture[i + 2], line_texture[i + 3]);
		mlx_put_pixel(data->img[WALL], x, y, color);
		i -= 4;
		y--;
	}
	i = length / 2 * 4;
	y = HEIGHT / 2;
	while (i < length * 4 && y < HEIGHT)
	{
		color = color_pixel(line_texture[i], line_texture[i + 1],
				line_texture[i + 2], line_texture[i + 3]);
		mlx_put_pixel(data->img[WALL], x, y, color);
		y++;
		i += 4;
	}
	free(line_texture);
	line_texture = NULL;
}

static int	*resize_texture(int *line_texture, float size, float scale_size)
{
	int	i;
	int	ratio;
	int	*new_line;

	new_line = malloc(sizeof(int) * ((int)ceilf(scale_size) * 4));
	if (new_line == NULL)
		return (NULL);
	ratio = (int)ceilf(scale_size / size);
	i = 0;
	while (i < (int)ceilf(scale_size))
	{
		new_line[i * 4] = line_texture[(i / ratio) * 4];
		new_line[i * 4 + 1] = line_texture[(i / ratio) * 4 + 1];
		new_line[i * 4 + 2] = line_texture[(i / ratio) * 4 + 2];
		new_line[i * 4 + 3] = line_texture[(i / ratio) * 4 + 3];
		i++;
	}
	return (new_line);
}

int	*get_line_texture(int pos, mlx_texture_t texture, float scale_size)
{
	int				*line;
	int				*reline;
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
	reline = resize_texture(line, texture.width, scale_size);
	free(line);
	return (reline);
}

float	scale_calculate(float dist_foc, float dist, float size_texture)
{
	float	scale;

	scale = size_texture / dist * dist_foc;
	return (scale);
}
