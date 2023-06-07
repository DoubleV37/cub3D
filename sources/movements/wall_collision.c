/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:18:47 by jduval            #+#    #+#             */
/*   Updated: 2023/06/07 15:53:42 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "type.h"

bool	check_collide(t_data *data, float pos[2], float x, float y)
{
	int	x2;
	int	y2;
	int	posx;
	int	posy;

	x2 = x / data->tools.unit;
	y2 = y / data->tools.unit;
	posx = pos[0] / data->tools.unit;
	posy = pos[1] / data->tools.unit;
	if (data->map[y2][x2] != '0')
		return (true);
	if (data->map[posy][x2] != '0' && data->map[y2][posx] != '0')
		return (true);
	return (false);
}
