/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_incr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:15:54 by jduval            #+#    #+#             */
/*   Updated: 2023/05/19 17:20:59 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <math.h>

float	calculate_incr_x(t_player *player)
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

float	calculate_incr_y(t_player *player)
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
