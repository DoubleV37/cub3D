/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:18:47 by jduval            #+#    #+#             */
/*   Updated: 2023/06/27 11:44:34 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "type_bonus.h"

bool	check_collide(t_data *data, float x, float y)
{
	int	x2;
	int	y2;

	x2 = x / data->unit;
	y2 = y / data->unit;
	if (data->map[y2][x2] != '0')
		return (true);
	return (false);
}
