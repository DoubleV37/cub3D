/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:02:26 by vviovi            #+#    #+#             */
/*   Updated: 2023/05/17 16:20:14 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_texture_info(int file_fd, char *card, t_data *data, int index_tab)
{
	char	*line;
	char	**dataline;

	line = gnl_skip_void(file_fd);
	if (!line)
		return (print_error_map(1));
	dataline = ft_split_char(line, ' ');
	free(line);
	if (dataline && ft_strncmp(dataline[0], card, ft_strlen(dataline[0])) == 0
		&& ft_strlen(dataline[0]) == ft_strlen(card))
	{
		if (valid_texture(dataline[1]))
		{
			data->textures.texture[index_tab] = mlx_load_png(dataline[1]);
			if (data->textures.texture[index_tab] == NULL)
				return (print_error_map(1));
			ft_free_array(dataline);
			return (1);
		}
	}
	if (dataline)
		ft_free_array(dataline);
	return (print_error_map(1));
}

static int	save_color_data(char **data_color, t_data *data, char place)
{
	if (len_dbl_tab(data_color) != 3)
		return (0);
	if (place == 'C')
	{
		data->textures.color_ceil[0] = ft_atoi(data_color[0]);
		data->textures.color_ceil[1] = ft_atoi(data_color[1]);
		data->textures.color_ceil[2] = ft_atoi(data_color[2]);
		return (valid_color(data->textures.color_ceil[0],
			data->textures.color_ceil[1], data->textures.color_ceil[2]));
	}
	data->textures.color_floor[0] = ft_atoi(data_color[0]);
	data->textures.color_floor[1] = ft_atoi(data_color[1]);
	data->textures.color_floor[2] = ft_atoi(data_color[2]);
	return (valid_color(data->textures.color_floor[0],
			data->textures.color_floor[1], data->textures.color_floor[2]));
}

static int	verif_place_and_separe(char place, char *place_and_color)
{
	char	placedata;
	int		i;

	i = 0;
	while (place_and_color[i] && place_and_color[i] != place)
		i++;
	placedata = place_and_color[i];
	if (placedata != place)
		return (0);
	place_and_color[i] = ' ';
	return (1);
}

int	get_color_info(int file_fd, char place, t_data *data)
{
	char	*line;
	char	**dataline;

	line = gnl_skip_void(file_fd);
	if (!line)
		return (0);
	dataline = ft_split_char(line, ',');
	free(line);
	if (!dataline || !verif_place_and_separe(place, dataline[0]))
	{
		if (dataline)
			ft_free_array(dataline);
		return (print_error_map(2));
	}
	if (save_color_data(dataline, data, place))
	{
		ft_free_array(dataline);
		return (1);
	}
	ft_free_array(dataline);
	return (print_error_map(2));
}
