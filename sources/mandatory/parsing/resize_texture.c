/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:36:04 by jduval            #+#    #+#             */
/*   Updated: 2023/07/07 08:53:44 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

static void		set_scaled_texture(uint32_t *text, mlx_image_t *img);
static uint32_t	**allocate_texture(void);

int	resize_texture(t_data *data)
{
	int			i;
	mlx_image_t	*tmp;

	i = 0;
	data->text = allocate_texture();
	if (data->text == NULL)
		return (1);
	while (i < 4)
	{
		tmp = mlx_texture_to_image(data->mlx, data->textures.texture[i]);
		if (tmp == NULL)
			return (1);
		if (mlx_resize_image(tmp, SIZE, SIZE) != true)
		{
			mlx_delete_image(data->mlx, tmp);
			return (1);
		}
		set_scaled_texture(data->text[i], tmp);
		mlx_delete_image(data->mlx, tmp);
		i++;
	}
	clean_texture_nb(&data->textures, 4);
	return (0);
}

static uint32_t	**allocate_texture(void)
{
	uint32_t	**texture;
	int			i;

	texture = malloc(sizeof(uint32_t *) * (4 + 1));
	if (texture == NULL)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		texture[i] = malloc(sizeof(uint32_t) * (SIZE * SIZE));
		texture[i + 1] = NULL;
		if (texture == NULL)
		{
			free_textures(texture);
			return (NULL);
		}
		i++;
	}
	return (texture);
}

static void	set_scaled_texture(uint32_t *text, mlx_image_t *img)
{
	int	i;
	int	j;
	int	end;

	i = 0;
	j = 0;
	end = img->width * 4 * img->height;
	while (i < end)
	{
		text[j] = color_pixel(img->pixels[i], img->pixels[i + 1],
				img->pixels[i + 2], img->pixels[i + 3]);
		i += 4;
		j++;
	}
	return ;
}

void	free_textures(uint32_t **textures)
{
	int	i;

	i = 0;
	while (textures[i] != NULL)
	{
		free(textures[i]);
		i++;
	}
	free(textures);
}
