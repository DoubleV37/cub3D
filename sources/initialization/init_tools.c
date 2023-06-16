/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:25:24 by jduval            #+#    #+#             */
/*   Updated: 2023/06/16 16:06:23 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "type.h"

void	init_tools(t_tool *tools)
{
	tools->rotate.angle = 4.0f;
	tools->rotate.cos_ang = cosf(tools->rotate.angle * RAD_CONV);
	tools->rotate.sin_ang = sinf(tools->rotate.angle * RAD_CONV);
	tools->rotate.cos_inv = cosf(tools->rotate.angle * RAD_CONV * (-1.0f));
	tools->rotate.sin_inv = sinf(tools->rotate.angle * RAD_CONV * (-1.0f));
	tools->dist = (WIDTH / 2) / (tanf(((float)FOV / 2) * RAD_CONV));
	tools->delta_angle = (float)FOV / WIDTH;
}
