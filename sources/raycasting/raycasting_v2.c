/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:37:15 by jduval            #+#    #+#             */
/*   Updated: 2023/06/15 22:41:26 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

static void	send_ray(t_data *data, t_ray *ray, float alpha);

static void	reset_map(mlx_image_t *img)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			mlx_put_pixel(img, j, i, color_pixel(0, 0, 0, 0));
	}
}

static float	make_alpha(float alpha)
{
	float	value;

	value = alpha;
	if (alpha < 0.0f)
		value = 360.0f + alpha;
	else if (alpha > 360.0f)
		value = alpha - 360.0f;
	return (value);

}

void	raycasting(t_data *data, t_player *player)
{
	t_ray	ray;
	float	i;
	float	alpha;

	reset_map(data->img[PLAYER]);
	i = 0.0f;
	alpha  = player->angle - (FOV / 2);
	//printf("alpha = %f\n", alpha);
	//while (i < WIDTH)
	//{
		alpha = make_alpha(alpha);
		send_ray(data, &ray, 45.0f);
		//draw_wall(data, &ray, i);
		//draw_line(data->img[PLAYER], draw, color_pixel(255, 255, 255, 255));
		alpha += data->tools.delta_angle; 
		i += 1.0f;
	//}
	//printf("alpha = %f\n", alpha);
	draw_pov(data, player, 1);
}

static void	send_ray(t_data *data, t_ray *ray, float alpha)
{
	float	u_vector[2];	//vecteur unitaire de direction du rayon
	float	dist[2];	//distances du rayon parcouru pour chaque intersection vertical et horizontal
	float	n_dist[2];	//distance d'incrementation du rayon pour un step en x ou un step en y (step = 1 case)
	float	e_coord[2];
	int		step[2];	//increment de case sur map de char ** en fonction de la dir du rayon
	int		x = data->player.pos[X] / data->tools.unit;
	int		y = data->player.pos[Y] / data->tools.unit;
	int		side = 0;
	int		hit = 0;

	process_uvector(alpha, u_vector);
	printf("-------------------------\n");
	//printf("alpha = %f\nuvec x = %f\ty = %f\n", alpha, u_vector[X], u_vector[Y]);
	process_ndist(n_dist, u_vector, data->tools.unit);
	//printf("alpha = %f\npos x = %f\ty = %f\n", alpha, data->player.pos[X], data->player.pos[Y]);
	printf("ndist v = %f\th = %f\n", n_dist[V], n_dist[H]);
	first_intersection(dist, n_dist, data->player.pos, u_vector, data->tools.unit, alpha);
	printf("dist V = %f\tH = %f\n", dist[V], dist[H]);
	define_step(u_vector, step);
	while (hit == 0)
	{
		if (dist[H] < dist[V])
		{
			y += step[Y];
			dist[H] += n_dist[H];
			side = 1;
		}
		else
		{
			x += step[X];
			dist[V] += n_dist[V];
			side = 0;
		}
		if (data->map[y][x] != '0')
			hit = 1;
	}
	printf("side %i\nindex x = %i\ty = %i\n", side, x, y);
	if (side == 0)
		end_coordinate(data->player.pos, dist[V], alpha, e_coord);
	else
		end_coordinate(data->player.pos, dist[H], alpha, e_coord);
	float	draw[4] = {data->player.pos[X], data->player.pos[Y], e_coord[X], e_coord[Y]};
	draw_line(data->img[PLAYER], draw, color_pixel(255, 255, 255, 255));
	return ;
}
