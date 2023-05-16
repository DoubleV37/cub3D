/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:30:26 by jduval            #+#    #+#             */
/*   Updated: 2023/05/15 16:31:06 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "type.h"

void	set_focal(float *focal, t_player *player)
{
	float	len;

	len = 1 / tanf(M_PI_4);
	if (start_view == NO)
	{
		focal[X] = player->pos[X];
		focal[Y] = player->pos[Y] - len;
	}
	else if (start_view == SO)
	{
		focal[X] = player->pos[X];
		focal[Y] = player->pos[Y] + len;
	}
	else if (start_view == EA)
	{
		focal[X] = player->pos[X] + len;
		focal[Y] = player->pos[Y];
	}
	else
	{
		focal[X] = player->pos[X] - len;
		focal[Y] = player->pos[Y];	
	}
}

void	set_player_coordinate(t_player *player)
{
	player->pos[X] = ((float)player->indexs[X] * 10) + 5;
	player->pos[Y] = ((float)player->indexs[Y] * 10) + 5;
}

void	make_setup(t_player *player)
{
	set_player_coordinate(player);
	set_focal(player);
}
