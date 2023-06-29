/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:17:00 by jduval            #+#    #+#             */
/*   Updated: 2023/06/29 17:19:52 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	door_control(t_data *data)
{
	t_door	*door;
	t_card	face;

	face = door_around_player(data->map, data->player.indexs)
	if (face == -1)
		return ;
	door = wich_door(data->map, data->player.indexs, face);
	if (door_in_fov(door, data->player.angle) == false)
		return ;
	if (door->open == true)
		closing_door(data, door);
	else
		opening_door(data, door)
	door->open ^= true;
}
