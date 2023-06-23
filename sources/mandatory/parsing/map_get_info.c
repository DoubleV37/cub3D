/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:02:26 by vviovi            #+#    #+#             */
/*   Updated: 2023/06/23 13:46:32 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>

int	get_map(int file_fd, t_data *data)
{
	char	*line;
	char	*map_one_line;

	map_one_line = gnl_skip_void(file_fd);
	if (!map_one_line)
		return (print_error_map(3));
	line = ft_gnl(file_fd);
	while (line)
	{
		map_one_line = ft_strjoin_free(map_one_line, line);
		free(line);
		line = ft_gnl(file_fd);
	}
	data->map = ft_split_char(map_one_line, '\n');
	free(map_one_line);
	return (1);
}

int	get_texture_info(char **dataline, char *card, t_data *data, int index_tab)
{
	if (dataline && ft_strncmp(dataline[0], card, ft_strlen(dataline[0])) == 0
		&& ft_strlen(dataline[0]) == ft_strlen(card))
	{
		if (valid_texture(dataline[1]))
		{
			data->textures.texture[index_tab] = mlx_load_png(dataline[1]);
			ft_free_array(dataline);
			dataline = NULL;
			if (data->textures.texture[index_tab] == NULL)
				return (0);
			return (1);
		}
	}
	if (dataline)
	{
		ft_free_array(dataline);
		dataline = NULL;
	}
	return (0);
}

static int	save_color_data(char **colors, t_data *data, char place)
{
	if (place == 'C')
	{
		data->textures.color_ceil[0] = ft_atoi(colors[0]);
		data->textures.color_ceil[1] = ft_atoi(colors[1]);
		data->textures.color_ceil[2] = ft_atoi(colors[2]);
		return (valid_color(data->textures.color_ceil[0],
				data->textures.color_ceil[1], data->textures.color_ceil[2]));
	}
	data->textures.color_floor[0] = ft_atoi(colors[0]);
	data->textures.color_floor[1] = ft_atoi(colors[1]);
	data->textures.color_floor[2] = ft_atoi(colors[2]);
	return (valid_color(data->textures.color_floor[0],
			data->textures.color_floor[1], data->textures.color_floor[2]));
}

static int	color_separe(char **dataline, char ***colors)
{
	int	i;

	i = 0;
	while (dataline[1][i])
	{
		if (dataline[1][i] == ',')
			dataline[1][i] = ' ';
		i++;
	}
	*colors = ft_split_char(dataline[1], ' ');
	if (dataline)
		ft_free_array(dataline);
	dataline = NULL;
	if (!*colors || len_dbl_tab(*colors) != 3)
	{
		ft_free_array(*colors);
		return (0);
	}
	return (1);
}

int	get_color_info(char **dataline, char place, t_data *data)
{
	char	**colors;

	if (!dataline || !ft_strlen(dataline[0]) || dataline[0][0] != place
		|| len_dbl_tab(dataline) != 2)
	{
		if (dataline)
			ft_free_array(dataline);
		dataline = NULL;
		return (0);
	}
	colors = NULL;
	if (color_separe(dataline, &colors) && save_color_data(colors, data, place))
	{
		ft_free_array(colors);
		return (1);
	}
	return (0);
}
