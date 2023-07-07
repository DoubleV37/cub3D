/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_control_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:17:00 by jduval            #+#    #+#             */
/*   Updated: 2023/07/07 09:16:17 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <stdlib.h>

void	door_control(t_data *data)
{
	t_door	*door;
	t_card	view;

	if (door_around_player(data->map, data->player.indexs) == false)
		return ;
	view = view_of_player(data->player.angle);
	door = is_looking_a_door(&data->doors, data->map, view,
			data->player.indexs);
	if (door == NULL)
		return ;
	if (door->status == OPEN)
		door->status = CLOSING;
	else if (door->status == CLOSE)
		door->status = OPENING;
}

void	door_animation(t_door *doors, int nbr_frames)
{
	while (doors != NULL)
	{
		if (doors->status == CLOSING)
			closing_door(doors);
		else if (doors->status == OPENING)
			opening_door(doors, nbr_frames);
		doors = doors->next;
	}
}
