/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:18:47 by jduval            #+#    #+#             */
/*   Updated: 2023/05/22 17:04:12 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdbool.h>

bool check_collide(float *pos, int unit, char **map)
{
	int	index[2];

	index[X] = pos[X] / unit;
	index[Y] = pos[Y] / unit;
	if (map[index[Y]][index[X]] != '0')
		return (true);
	return (false);
}
