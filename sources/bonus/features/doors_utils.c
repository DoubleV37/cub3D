/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:45:13 by jduval            #+#    #+#             */
/*   Updated: 2023/06/29 17:19:49 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

static int	get_right_index(int var, t_card face);

t_card	door_around_player(char **map, int *index)
{
	int	x;
	int	y;

	x = index[X];
	y = index[Y];
	if (map[y][x - 1] == 'D')
		return (WE);
	else if (map[y][x + 1] == 'D')
		return (EA);
	else if (map[y + 1][x] == 'D')
		return (SO);
	else if (map[y - 1][x] == 'D')
		return (NO);
	else
		return (-1);
}

t_door	*wich_door(t_door **head, int *indexs, t_card face)
{
	t_door	*door;
	int		x;
	int		y;

	x = indexs[X];
	y = indexs[Y];
	if (face == WE || face == EA)
		x = get_right_index(indexs[X], face);
	else
		y = get_right_index(indexs[Y], face);
	door = (*head);
	while (door != NULL)
	{
		if (face != door->oriented[0] && face != door->oriented[1])
		{
			door = door->next;
			continue ;
		}
		if (x == door->index[X] && y == door->index[Y] /*&& face == door->oriented*/)
			return (door);
		door = door->next;
	}
	return (NULL);
}

bool	door_in_fov(t_door *door, float angle, t_card face)
{
	float	plus_fov;
	float	minus_fov;

	plus_fov = get_right_angle(angle, FOV / 2);
	minus_fov = get_right_angle(angle, -FOV / 2);
	if (face == SO)
	{
		if (plus_fov >= )
	}
}

static int	get_right_index(int var, t_card face)
{
	int	add;

	add = -1;
	if (face == SO || face == EA)
		add = 1;
	if (axe == X)
		var += add;
}
