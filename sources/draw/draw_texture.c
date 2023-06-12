/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:44:26 by vviovi            #+#    #+#             */
/*   Updated: 2023/06/12 14:25:11 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_texture_line(t_data *data, int *line_texture, int x, int length, int typ)
{
	int	i;
	int	y;
	int	finish;
	int32_t	color;


	i = 0;
	if (length > HEIGHT)
		length = HEIGHT - 2;
	y = HEIGHT / 2 - length / 2;
	finish = y + length;
	while (y < finish)
	{
		//color = color_pixel(line_texture[i], line_texture[i + 1],
		//		line_texture[i + 2], line_texture[i + 3]);
		if (typ == 0)
			color = color_pixel(30, 30, 120, 255);
		else if (typ == 1)
			color = color_pixel(120, 30, 30, 255);
		else if (typ == 2)
			color = color_pixel(30, 120, 30, 255);
		else
			color = color_pixel(120, 120, 120, 255);
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
		if (i * size / scale_size > size)
			resized_line[i] = line_texture[size - 1];
		else
			resized_line[i] = line_texture[i * scale_size / size];
		i++;
	}
	free(line_texture);
}

float	scale_calculate(float dist_foc, float dist, float size_texture)
{
	float	scale;

	scale = size_texture / dist * dist_foc;
	return (scale);
}
