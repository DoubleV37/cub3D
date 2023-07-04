/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_animation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:52:56 by jduval            #+#    #+#             */
/*   Updated: 2023/07/04 17:21:18 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <stdio.h>
#include <unistd.h>

void	closing_door(t_door *door)
{
	door->frame--;
	if (door->frame == 4)
		door->status = CLOSE;
	return ;
}

void	opening_door(t_door *door, int nbr_frames)
{
	door->frame++;
	if (door->frame == 3 + nbr_frames)
		door->status = OPEN;
	return ;
}
