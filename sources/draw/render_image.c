/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:07:22 by jduval            #+#    #+#             */
/*   Updated: 2023/05/24 11:21:00 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d.h"
#include <stdio.h>

int	render_start(t_data *data)
{
	if (render_background(data) == 1)
		return (1);
	if (render_map(data) == 1)
		return (1);
	if (render_player(data) == 1)
		return (1);
	return (0);
}

int	render_player(t_data *data)
{
	if (mlx_image_to_window(data->mlx, data->img[PLAYER], 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	return (0);
}

int	render_background(t_data *data)
{
	if (mlx_image_to_window(data->mlx, data->img[BACKGROUND], 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	return (0);
}

int	render_map(t_data *data)
{
	if (mlx_image_to_window(data->mlx, data->img[MAP], 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	return (0);
}