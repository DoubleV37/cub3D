/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:39:49 by vviovi            #+#    #+#             */
/*   Updated: 2023/07/04 17:49:28 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	verify_init(int *verify)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		verify[i] = 0;
		i++;
	}
}

void	delete_textures(t_data *data, int *verify)
{
	int	i;

	i = 0;
	while (i < 4 + verify[6])
	{
		if (i < 4 && verify[i] == 1)
			mlx_delete_texture(data->textures.texture[i]);
		else if (i >= 4)
			mlx_delete_texture(data->textures.texture[i]);
		i++;
	}
}

int	verif_verify(t_data *data, int *verify)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (verify[i] != 1)
		{
			delete_textures(data, verify);
			return (0);
		}
		i++;
	}
	data->door_frames = verify[6];
	return (1);
}
