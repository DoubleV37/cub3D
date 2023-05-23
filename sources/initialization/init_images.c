/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:05:08 by jduval            #+#    #+#             */
/*   Updated: 2023/05/23 17:23:54 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "type.h"
#include <stdio.h>

int	init_images(t_data *data)
{
	data->img[BACKSCREEN] = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img[BACKSCREEN] == NULL)
		return (printf("%s", mlx_strerror(mlx_errno)));
	data->img[WALL] = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img[WALL] == NULL)
		return (printf("%s", mlx_strerror(mlx_errno)));
	data->img[MAP] = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img[MAP] == NULL)
		return (printf("%s", mlx_strerror(mlx_errno)));
	data->img[PLAYER] = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img[PLAYER] == NULL)
		return (printf("%s", mlx_strerror(mlx_errno)));
	return (0);
}
