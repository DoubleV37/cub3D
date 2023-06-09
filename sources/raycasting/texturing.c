/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:48 by jduval            #+#    #+#             */
/*   Updated: 2023/06/09 11:46:17 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	horizontal_wall(t_data *data, t_ray *ray, int n_ray)
{
	float	scale;	//devient notre increment pour poser un pixel (a chaque fois qu'il passe a l'unité supérieur)
	int		pos_tex; //position dans la texture
	float	width_tex; //largeur de la texture
	int		*line_texture; //ligne de la texture

	scale = ray->e_coord[X] / data->tools.unit;
	ft_printf("scale = %f||\n", scale);
	ft_printf("data->tools.unit = %d||\n", data->tools.unit);
	ft_printf("ray->e_coord[X] = %f||\n", ray->e_coord[X]);
	ft_printf("ray->e_coord[Y] = %f||\n", ray->e_coord[Y]);
	scale = modff(scale, NULL); //pourcentage de la ou on est dans la texture
	width_tex = data->textures.texture[ray->texture]->width;
	pos_tex = roundf(width_tex * scale); //position dans la texture
	scale = scale_calculate(ray->dist, width_tex); //increment de boucle (pixel pos)
	line_texture = get_line_texture(pos_tex, *(data->textures.texture[ray->texture])); //recupere la ligne de la texture
	resize_texture(line_texture, width_tex, data->tools.unit); //resize la texture
	draw_wall(data, line_texture, 0, n_ray); //fonction qui boucle et put pixel du mur
	// pose du pixel de 1919 jusqua 0.
}

static void	vertical_wall(t_data *data, t_ray *ray, int n_ray)
{
	return ;
}

void	render_wall(t_data *data, t_ray *ray, int n_ray)
{
	if (ray->texture == NO || ray->texture == SO)
		horizontal_wall(data, ray, n_ray);
	else
		vertical_wall(data, ray, n_ray);
}
