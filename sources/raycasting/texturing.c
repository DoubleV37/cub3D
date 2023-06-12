/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:48 by jduval            #+#    #+#             */
/*   Updated: 2023/06/12 14:18:53 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

#include <stdio.h>

static void	wall_calculate(t_data *data, t_ray *ray, int n_ray, char side)
{
	float	scale;	//devient notre increment pour poser un pixel (a chaque fois qu'il passe a l'unité supérieur)
	int		pos_tex; //position dans la texture
	float	width_tex; //largeur de la texture
	int		*line_texture; //ligne de la texture
	float	nothing;

	scale = ray->e_coord[X] / data->tools.unit;
	if (side == 'V')
		scale = ray->e_coord[Y] / data->tools.unit;
	scale = modff(scale, &nothing); //pourcentage de la ou on est dans la texture
	width_tex = data->textures.texture[ray->texture]->width;
	pos_tex = roundf(width_tex * scale); //position dans la texture
	scale = scale_calculate(data->tools.dist, ray->dist, width_tex); //increment de boucle (pixel pos)
	line_texture = get_line_texture(pos_tex, *(data->textures.texture[ray->texture])); //recupere la ligne de la texture
	//resize_texture(line_texture, width_tex, scale); //resize la texture
	draw_texture_line(data, line_texture, n_ray, scale, ray->texture); //fonction qui boucle et put pixel du mur
}

void	draw_wall(t_data *data, t_ray *ray, int n_ray)
{
	int	x;

	x = 1919 - n_ray;
	if (ray->texture == NO || ray->texture == SO)
		wall_calculate(data, ray, x, 'H');
	else
		wall_calculate(data, ray, x, 'V');
}
