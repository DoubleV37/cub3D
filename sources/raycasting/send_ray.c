/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:12:16 by jduval            #+#    #+#             */
/*   Updated: 2023/05/16 17:07:28 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

void	send_ray(t_data *data, t_player *player, t_setup *setup)
{
	float	ref[5];
	float	angle;
	float	i;

	i = 0;
	angle = -FOV / 2;
	while (i < nbr_of_ray)
	{
		find_collide(ref, angle, i, player);
		angle += setup->delta_angle;
		i++;
	}
}

void	find_collide(float *ref, float angle, float i, t_player *player)
{
	
}
