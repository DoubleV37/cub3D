/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:30:26 by jduval            #+#    #+#             */
/*   Updated: 2023/05/16 17:07:30 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "type.h"

void	set_focal_start(t_setup *setup, t_player *player);
void	set_cam_start(t_setup *setup, player);

void	make_setup(t_player *player)
{
	player->setup.nbr_of_ray = WIDTH;
	player->pos[X] = ((float)player->indexs[X] * UNIT) + (UNIT / 2);
	player->pos[Y] = ((float)player->indexs[Y] * UNIT) + (UNIT / 2);
	set_focal_start(player->setup, player);
	set_cam_start(player->setup, player);
	player->setup.step = CAM / player->setup.nbr_of_ray;
	player->setup.delta_angle = atanf(player->setup.step / player->setup.focal);
}

void	set_focal_start(t_setup *setup, t_player *player)
{
	float	len;

	setup->len_focal = 1 / tanf(((FOV / 2) * M_PI) / 180);
	if (player->start_view == NO)
	{
		setup->focal[X] = player->pos[X];
		setup->focal[Y] = player->pos[Y] - setup->len_focal;
	}
	else if (player->start_view == SO)
	{
		setup->focal[X] = player->pos[X];
		setup->focal[Y] = player->pos[Y] + setup->len_focal;
	}
	else if (player->start_view == EA)
	{
		setup->focal[X] = player->pos[X] + setup->len_focal;
		setup->focal[Y] = player->pos[Y];
	}
	else
	{
		setup->focal[X] = player->pos[X] - setup->len_focal;
		setup->focal[Y] = player->pos[Y];
	}
}

void	set_cam_start(t_setup *setup, player)
{
	if (start_view == NO)
	{
		setup->cam[X] = player->pos[X] - (CAM / 2);
		setup->cam[Y] = player->pos[Y];
	}
	else if (start_view == SO)
	{
		setup->cam[X] = player->pos[X] + (CAM / 2);
		setup->cam[Y] = player->pos[Y];
	}
	else if (start_view == EA)
	{
		setup->cam[X] = player->pos[X];
		setup->cam[Y] = player->pos[Y] - (CAM / 2);
	}
	else
	{
		setup->cam[X] = player->pos[X];
		setup->cam[Y] = player->pos[Y] + (CAM / 2);	
	}
}
