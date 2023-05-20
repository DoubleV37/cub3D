/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:31:35 by jduval            #+#    #+#             */
/*   Updated: 2023/05/20 17:41:23 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static float	calculate_incr_x(t_player *player);
static float	calculate_incr_y(t_player *player);

int	move_right_left(t_data *data, t_player *player, t_dir dir)
{
	
}

static float	calculate_incr_x(t_player *player)
{
	float	result;

	if (player->angle > 0 && player->angle <= 90)
		result = cosf(player->angle * RAD_CONV) * player->pace;
	else if (player->angle > 90 && player->angle <= 180)
		result = (-1) * (cosf((180 - player->angle) * RAD_CONV) * player->pace);
	else if (player->angle > 180 && player->angle <= 270)
		result = (-1) * (cosf((player->angle - 180) * RAD_CONV) * player->pace);
	else
		result = cosf((360 - player->angle) * RAD_CONV) * player->pace;
	result = roundf(result);
	return (result);
}

static float	calculate_incr_y(t_player *player)
{
	float	result;

	if (player->angle > 0 && player->angle <= 90)
		result = (-1) * (sinf(player->angle * RAD_CONV) * player->pace);
	else if (player->angle > 90 && player->angle <= 180)
		result = (-1) * (sinf((180 - player->angle) * RAD_CONV) * player->pace);
	else if (player->angle > 180 && player->angle <= 270)
		result = sinf((player->angle - 180) * RAD_CONV) * player->pace;
	else
		result = sinf((360 - player->angle) * RAD_CONV) * player->pace;
	result = roundf(result);
	return (result);
}
