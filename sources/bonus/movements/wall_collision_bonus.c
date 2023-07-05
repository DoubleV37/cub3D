/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:18:47 by jduval            #+#    #+#             */
/*   Updated: 2023/07/05 11:30:39 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdbool.h>
#include <stdlib.h>
#include "cub3d_bonus.h"

static bool	door_is_open(t_door **head, int x, int y);

bool	check_collide(t_data *data, float x, float y)
{
	int	x2;
	int	y2;

	x2 = x / SIZE;
	y2 = y / SIZE;
	if (data->map[y2][x2] == 'D')
	{
		if (door_is_open(&data->doors, x2, y2) == true)
			return (false);
		else
			return (true);
	}
	if (data->map[y2][x2] == '1')
		return (true);
	return (false);
}

static bool	door_is_open(t_door **head, int x, int y)
{
	t_door	*door;

	door = find_door(head, x, y);
	if (door == NULL)
		return (true);
	if (door->status == OPEN)
		return (true);
	else
		return (false);
}
