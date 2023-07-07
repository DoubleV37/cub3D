/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:18:47 by jduval            #+#    #+#             */
/*   Updated: 2023/07/07 08:34:59 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

bool	check_collide(t_data *data, float x, float y)
{
	int	x2;
	int	y2;

	x2 = x / SIZE;
	y2 = y / SIZE;
	if (data->map[y2][x2] != '0')
		return (true);
	return (false);
}
