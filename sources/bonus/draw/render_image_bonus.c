/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:07:22 by jduval            #+#    #+#             */
/*   Updated: 2023/07/07 09:05:58 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_bonus.h"
#include <stdio.h>

static int	render_wall(t_data *data)
{
	if (mlx_image_to_window(data->mlx, data->img[WALL], 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	return (0);
}

static int	render_background(t_data *data)
{
	if (mlx_image_to_window(data->mlx, data->img[BACKGROUND], 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	return (0);
}

static int	render_map(t_data *data)
{
	if (mlx_image_to_window(data->mlx, data->img[MAP], 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	return (0);
}

static int	render_door(t_data *data)
{
	if (mlx_image_to_window(data->mlx, data->img[DOOR], 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	return (0);
}

int	render_start(t_data *data)
{
	if (render_background(data) == 1)
		return (1);
	if (render_wall(data) == 1)
		return (1);
	if (render_door(data) == 1)
		return (1);
	if (render_map(data) == 1)
		return (1);
	return (0);
}
