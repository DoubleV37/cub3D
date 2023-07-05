/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_door_list_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 07:43:05 by jduval            #+#    #+#             */
/*   Updated: 2023/07/05 15:31:37 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <stdlib.h>

int	create_door_list(t_data *data)
{
	int		i;
	int		j;
	t_door	*tmp;

	i = 0;
	data->doors = NULL;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'D')
			{
				tmp = create_node_door(j, i);
				if (tmp == NULL)
					return (1);
				addfront_node_door(&data->doors, tmp);
			}
			j++;
		}
		i++;
	}
	return (0);
}
