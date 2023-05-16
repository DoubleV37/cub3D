/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:02:26 by vviovi            #+#    #+#             */
/*   Updated: 2023/05/16 17:01:04 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type.h"

int	get_texture_info(int file_fd, char *card, t_data *data, int index_tab)
{
	char	*line;
	char	**dataline;

	line = gnl_skip_void(file_fd);
	if (!line)
		return (print_error_map(1));
	dataline = ft_split(line, ' ');
	if (dataline && ft_strncmp(dataline[0], card, ft_strlen(dataline[0])) == 0
		&& ft_strlen(dataline[0]) == ft_strlen(card))
	{
		if (valid_texture(dataline[1]))
		{
			data->textures.texture[index_tab] = mlx_load_png(dataline[1]);
			if (data->textures.texture[index_tab] == NULL)
			ft_free_array(dataline);
			return (1);
		}
	}
	if (dataline)
		ft_free_array(dataline);
	return (print_error_map(1));
}

static void	save_color_data(char **data_color, t_data *data)
{
	int	len_color;


}

int	get_color_info(int file_fd, char *place, t_data *data)
{
	char	*line;
	char	**dataline;

	line = gnl_skip_void(file_fd);
	if (!line)
		return (0);
	dataline = ft_split(line, ',');
	if (dataline && ft_strncmp(dataline[0], place, ft_strlen(dataline[0])) == 0
		&& ft_strlen(dataline[0]) == ft_strlen(place))
	{
		if (valid_color(dataline))
		{
			save_color_data(dataline, data);
			ft_free_array(dataline);
			return (1);
		}
	}
	if (dataline)
		ft_free_array(dataline);
	return (0);
}
