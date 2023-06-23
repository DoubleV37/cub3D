/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:48 by jduval            #+#    #+#             */
/*   Updated: 2023/06/23 17:37:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static void	draw_texture(t_data *data, uint32_t *text, float posx, float lengh, int x);

static int	wall_calculate(t_data *data, t_ray *ray)
{
	float	lengh;
	float	pos_tex;
	float	width_tex;
	float	dfoc;
	//int		*line_texture;

	//line_texture = malloc(sizeof(int) * ray->texture_size);
	//if (line_texture == NULL)
	//	return (1);
	//ray->texture_size = data->textures.texture[ray->texture]->width;
	if (ray->texture == EA || ray->texture == WE)
		pos_tex = ray->pos[Y] / data->unit;
	else
		pos_tex = ray->pos[X] / data->unit;
	//printf("1pos_tex = %f\n", pos_tex);
	pos_tex = modff(pos_tex, &width_tex);
	//printf("2pos_tex = %f\n", pos_tex);
	width_tex = SIZE;
	pos_tex = roundf(width_tex * pos_tex);
	//(void)modff(pos_tex * width_tex, &pos_tex);
	if (ray->texture == SO || ray->texture == WE)
		pos_tex = width_tex - pos_tex - 1;
	//pos_tex *= data->textures.texture[ray->texture]->bytes_per_pixel;
	//printf("3pos_tex = %f\n", pos_tex);
	//scale = scale_calculate(data->dist, ray->dist_perp, width_tex);
	if (ray->dist_perp <= 0.0f)
		ray->dist_perp = 1.0f;
	//lengh = WIDTH / (ray->dist_perp / data->unit);
	dfoc = (WIDTH / 2.0f) / (tanf(FOV / 2.0f * RAD_CONV));
	lengh = (data->unit / ray->dist_perp) * dfoc;
	//printf("perpdist = %f\n", ray->dist_perp);
	//printf("lengh = %f\n", lengh);
	draw_texture(data, data->text[ray->texture], pos_tex, lengh, ray->num_ray);
	//get_line_texture(pos_tex, *(data->textures.texture[ray->texture]),
	//	line_texture);
	//draw_texture_line(data, line_texture, ray, scale);
	//free(line_texture);
	return (0);
}

int	draw_wall(t_data *data, t_ray *ray)
{
	ray->texture_size = (data->textures.texture[ray->texture]->width + 1)
		* data->textures.texture[ray->texture]->bytes_per_pixel;
	ray->num_ray = 1919 - ray->num_ray;
	if (wall_calculate(data, ray) == 1)
		return (1);
	return (0);
}

static int32_t	get_pixel(mlx_texture_t *tex, float x, float y);
static int32_t	get_pixel2(int32_t *text, float x, float y);

static void	draw_texture(t_data *data, uint32_t *text, float posx, float lengh, int x)
{
	int		y;
	int		end;
	float	step;
	float	posy;
	int32_t	color;

	posy = 0.0f;
	step = SIZE / lengh;
	y = HEIGHT / 2 - lengh / 2;
	if (y < 0)
	{
		posy = step * abs(y);
		y = 0;
	}
	end = HEIGHT / 2 + lengh;
	if (end > HEIGHT)
		end = HEIGHT - 1;
	while (y <= end && y < HEIGHT - 1)
	{
		color = get_pixel2(text, posx, posy);
		if (color != -1)
			mlx_put_pixel(data->img[WALL], x, y, color);
		posy += step;
		y++;
	}
	return ;
}

static int32_t	get_pixel2(int32_t *text, float x, float y)
{
	int index;

	index = (int)x + (int)y * SIZE;
	if (index >= SIZE * SIZE)
		return (-1);
	return (text[index]);
	
}

static int32_t	get_pixel(mlx_texture_t *tex, float x, float y)
{
	int		index;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	index = (int)x + (int)y * tex->width * tex->bytes_per_pixel;
	//if (index != 0)
	//	printf("index = %i\n", index);
	if (index != 0 && index > tex->width * tex->bytes_per_pixel * tex->height - tex->bytes_per_pixel)
		return (-1);
	r = tex->pixels[index];
	g = tex->pixels[index + 1];
	b = tex->pixels[index + 2];
	return (color_pixel(r, g, b, tex->pixels[index + 3]));
}
