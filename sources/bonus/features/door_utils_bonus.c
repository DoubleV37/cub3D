/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:45:13 by jduval            #+#    #+#             */
/*   Updated: 2023/07/07 09:14:02 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <stdlib.h>

static int	get_right_index(int var, t_card face);

t_card	door_around_player(char **map, int *index)
{
	int	x;
	int	y;

	x = index[X];
	y = index[Y];
	if (map[y][x - 1] == 'D')
		return (true);
	else if (map[y][x + 1] == 'D')
		return (true);
	else if (map[y + 1][x] == 'D')
		return (true);
	else if (map[y - 1][x] == 'D')
		return (true);
	else
		return (false);
}

t_door	*is_looking_a_door(t_door **head, char **map, t_card view, int *indexs)
{
	t_door	*door;
	int		x;
	int		y;

	x = indexs[X];
	y = indexs[Y];
	if (view == WE || view == EA)
		x = get_right_index(indexs[X], view);
	else
		y = get_right_index(indexs[Y], view);
	if (map[y][x] != 'D')
		return (NULL);
	door = find_door(head, x, y);
	return (door);
}

t_card	view_of_player(float angle)
{
	if (angle <= 45.0f || angle >= 315.0f)
		return (EA);
	else if (angle > 45.0f && angle <= 135.0f)
		return (NO);
	else if (angle > 135.0f && angle <= 225.0f)
		return (WE);
	else
		return (SO);
}

static int	get_right_index(int var, t_card face)
{
	int	add;

	add = -1;
	if (face == SO || face == EA)
		add = 1;
	var += add;
	return (var);
}
