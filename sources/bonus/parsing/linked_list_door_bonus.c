/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_door_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:38:28 by jduval            #+#    #+#             */
/*   Updated: 2023/07/06 14:11:12 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_bonus.h"
#include <stdlib.h>

t_door	*create_node_door(int x, int y)
{
	t_door	*door;

	door = malloc(sizeof(t_door));
	if (door == NULL)
		return (NULL);
	door->status = CLOSE;
	door->index[X] = x;
	door->index[Y] = y;
	door->timelaps = 0;
	door->frame = 4;
	door->next = NULL;
	return (door);
}

void	addfront_node_door(t_door **head, t_door *node)
{
	if (node == NULL)
		return ;
	if ((*head) == NULL && node != NULL)
	{
		(*head) = node;
		return ;
	}
	node->next = (*head);
	(*head) = node;
}

void	free_door_list(t_door **head)
{
	t_door	*tmp;

	while ((*head) != NULL)
	{
		tmp = (*head);
		(*head) = (*head)->next;
		free(tmp);
	}
	return ;
}

t_door	*find_door(t_door **head, int x, int y)
{
	t_door	*door;

	door = (*head);
	while (door != NULL)
	{
		if (x == door->index[X] && y == door->index[Y])
			return (door);
		door = door->next;
	}
	return (NULL);
}
