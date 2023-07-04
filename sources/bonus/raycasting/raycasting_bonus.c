/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:37:15 by jduval            #+#    #+#             */
/*   Updated: 2023/07/04 17:33:19 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <math.h>

void	raycasting(t_data *data, t_player *player)
{
	t_ray	ray;
	float	i;
	float	alpha;
	bool	door_in_animation;

	reset_map(data);
	i = 0.0f;
	alpha = player->angle - (FOV / 2);
	door_in_animation = false;
	while (i < WIDTH)
	{
		alpha = get_right_angle(alpha);
		if (door_in_animation == false)
		{
			door_in_animation = ray_wall(data, &ray, alpha, i);
			draw_texture(data, &ray, i);
		}
		else
		{
			door_in_animation = ray_door(data, &ray, alpha, i);
			draw_texture(data, &ray, i);
		}
		if (door_in_animation == true)
			continue ;
		alpha += player->delta_angle;
		i += 1.0f;
	}
}

float	get_right_angle(float alpha)
{
	float	value;

	value = alpha;
	if (alpha < 0.0f)
		value = 360.0f + alpha;
	else if (alpha > 360.0f)
		value = alpha - 360.0f;
	return (value);
}
