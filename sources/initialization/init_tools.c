/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:25:24 by jduval            #+#    #+#             */
/*   Updated: 2023/05/24 15:48:42 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void	init_tools(t_tool *tools)
{
	tools->rotate.angle = 4.0f;
	tools->rotate.cos_ang = cosf(tools->rotate.angle * RAD_CONV);
	tools->rotate.sin_ang = sinf(tools->rotate.angle * RAD_CONV);
	tools->rotate.cos_inv = cosf(tools->rotate.angle * RAD_CONV * (-1.0f));
	tools->rotate.sin_inv = sinf(tools->rotate.angle * RAD_CONV * (-1.0f));
	set_vplane(tools);
	tools->step = 1.0f / (WIDTH / 2.0f);
}

void	set_vplane(t_tool *tools)
{
	if (tools->dir[X] == 0.0f && tools->dir[Y] == -FOV)
	{
		tools->plane[X] = -FOV;
		tools->plane[Y] = 0.0f;
	}
	else if (tools->dir[X] == 0.0f && tools->dir[Y] == FOV)
	{
		tools->plane[X] = FOV;
		tools->plane[Y] = 0.0f;
	}
	else if (tools->dir[X] == FOV && tools->dir[Y] == 0.0f)
	{
		tools->plane[X] = 0.0f;
		tools->plane[Y] = -FOV;
	}
	else
	{
		tools->plane[X] = 0.0f;
		tools->plane[Y] = FOV;
	}
}
