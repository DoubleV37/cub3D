/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_animation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:52:56 by jduval            #+#    #+#             */
/*   Updated: 2023/07/05 10:04:19 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	closing_door(t_door *door)
{
	if (door->timelaps == 3)
	{
		door->frame--;
		door->timelaps = 0;
	}
	else
	{
		door->timelaps++;
		return ;
	}
	if (door->frame == 4)
		door->status = CLOSE;
	return ;
}

void	opening_door(t_door *door, int nbr_frames)
{
	if (door->timelaps == 3)
	{
		door->frame++;
		door->timelaps = 0;
	}
	else
	{
		door->timelaps++;
		return ;
	}
	if (door->frame == 3 + nbr_frames)
		door->status = OPEN;
	return ;
}
