/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:17:14 by jduval            #+#    #+#             */
/*   Updated: 2023/05/19 14:15:05 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void	calc_rotation(float *view, t_rot *rot, int flag)
{
	float	xtemp;
	float	ytemp;

	xtemp = view[X + 2] - view[X];
	ytemp = view[Y + 2] - view[Y];
	if (flag == 1)
	{
		view[X + 2] = xtemp * rot->cos_ang - ytemp * rot->sin_ang + view[X];
		view[Y + 2] = xtemp * rot->sin_ang + ytemp * rot->cos_ang + view[Y];
	}
	else
	{
		view[X + 2] = xtemp * rot->cos_inv - ytemp * rot->sin_inv + view[X];
		view[Y + 2] = xtemp * rot->sin_inv + ytemp * rot->cos_inv + view[Y];
	}
	return ;
}
