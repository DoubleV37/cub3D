/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:18:47 by jduval            #+#    #+#             */
/*   Updated: 2023/05/19 17:25:20 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdbool.h>
#include <stdio.h>

bool check_collide(t_player *player, float *inc, int unit, char **map)
{
	int	index[2];

	index[X] = (player->pos[X] + inc[X]) / unit;
	index[Y] = (player->pos[Y] + inc[Y]) / unit;
	if (map[index[Y]][index[X]] != '0')
		return (true);
	return (false);
}
