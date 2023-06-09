/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:44:26 by vviovi            #+#    #+#             */
/*   Updated: 2023/06/09 17:14:36 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_texture_line(t_data *data, int *line_texture, int x, int y, int legth)
{
	int	i;
	int32_t	color;

	i = 0;
	x -= 500;
	while (i < legth)
	{
		color = color_pixel(line_texture[i], line_texture[i + 1],
				line_texture[i + 2], line_texture[i + 3]);
		mlx_put_pixel(data->img[WALL], x, y, color);
		y++;
		i += 4;
	}
}

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
#include <stdio.h>
void	resize_texture(int *line_texture, int size, int scale_size)
{
	int	*resized_line;
	int	i;

	resized_line = malloc(sizeof(int) * scale_size);
	if (resized_line == NULL)
		return ;
	i = 0;
	printf("size: %d\n", size);
	printf("scale_size: %d\n", scale_size);
	while (i < scale_size)
	{
		resized_line[i] = line_texture[i * scale_size / size];
		i++;
	}
	i = 0;
	while (i < scale_size)
		i++;
	printf("i: %d\n", i);
	free(line_texture);
	line_texture = resized_line;
	i = 0;
	while (i < scale_size)
		i++;
	printf("i: %d\n", i);
}

float	scale_calculate(float dist, float size_texture)
{
	float	scale;

	scale = size_texture / dist;
	//if (scale > size_texture)
	//	scale = size_texture;
	return (scale);
}
