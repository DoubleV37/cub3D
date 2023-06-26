/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:39:49 by vviovi            #+#    #+#             */
/*   Updated: 2023/06/26 08:07:48 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verify_init(int *verify)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		verify[i] = 0;
		i++;
	}
}

void	delete_textures(t_data *data, int *verify)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (verify[i] == 1)
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
	return (1);
}
