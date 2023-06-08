/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:48 by jduval            #+#    #+#             */
/*   Updated: 2023/06/08 19:41:51 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_wall(t_data *data, t_ray *ray, int n_ray)
{
	if (ray->texture == NO || ray->texture == SO)
		horizontal_wall(data, ray, n_ray);
	else
		vertical_wall(data, ray, n_ray);
}

void	horizontal_wall(t_data *data, t_ray *ray, int n_ray)
{
	float	scale;	//devient notre increment pour poser un pixel (a chaque fois qu'il passe a l'unité supérieur)
	int		pos_tex; //position dans la texture
	float	width_tex; //largeur de la texture

	scale = ray->e_coord[X] / data->tools.unit;
	scale = modff(scale, NULL); //pourcentage de la ou on est dans la texture
	width_tex = data->textures.texture[ray->texture].width;
	pos_tex = roundf(width_tex * scale); //position dans la texture
	scale = scale_calculate(ray->dist, width_tex); //increment de boucle (pixel pos)
	draw_wall(data, ) //fonction qui boucle et put pixel du mur
	// pose du pixel de 1919 jusqua 0. 
}
