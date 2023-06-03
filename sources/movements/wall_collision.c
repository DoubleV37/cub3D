/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:18:47 by jduval            #+#    #+#             */
/*   Updated: 2023/06/03 16:35:04 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "type.h"

bool	check_collide(t_data *data, float x, float y)
{
	int	x2;
	int	y2;

	x2 = x / data->tools.unit;
	y2 = y / data->tools.unit;
	if (data->map[y2][x2] != '0')
		return (true);
	return (false);
}
