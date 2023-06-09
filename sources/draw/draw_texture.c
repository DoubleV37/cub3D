/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:44:26 by vviovi            #+#    #+#             */
/*   Updated: 2023/06/09 11:06:13 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_data *data, int *line_texture, int x, int y)
{
	int	i;

	while (line_texture[i] != '\0')
	{
		mlx_put_pixel(data->img[WALL], x, y, line_texture[i]);
		x++;
		i++;
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
