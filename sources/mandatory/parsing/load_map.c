/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:15:52 by vviovi            #+#    #+#             */
/*   Updated: 2023/06/22 12:49:36 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int	get_infos(int verify[6], t_data *data, char **dataline)
{
	if (dataline[0][0] == 'N' && verify[0] == 0)
		verify[0] += get_texture_info(dataline, "NO", data, 0);
	else if (dataline[0][0] == 'S' && verify[1] == 0)
		verify[1] += get_texture_info(dataline, "SO", data, 1);
	else if (dataline[0][0] == 'W' && verify[2] == 0)
		verify[2] += get_texture_info(dataline, "WE", data, 2);
	else if (dataline[0][0] == 'E' && verify[3] == 0)
		verify[3] += get_texture_info(dataline, "EA", data, 3);
	else if (dataline[0][0] == 'F' && verify[4] == 0)
		verify[4] += get_color_info(dataline, 'F', data);
	else if (dataline[0][0] == 'C')
		verify[5] += get_color_info(dataline, 'C', data);
	else
	{
		ft_free_array(dataline);
		free_textures(data, verify);
		return (print_error_map(1));
	}
	return (1);
}

static int	load_infos(int file_fd, t_data *data)
{
	char	*line;
	char	**dataline;
	int		verify[6];
	int		i;

	line = gnl_skip_void(file_fd);
	if (!line)
		return (print_error_map(1));
	dataline = ft_split_char(line, ' ');
	free(line);
	verify_init(verify);
	i = 0;
	while (dataline && dataline[0])
	{
		if (!get_infos(verify, data, dataline))
			return (0);
		if (++i == 6)
			break ;
		line = gnl_skip_void(file_fd);
		dataline = ft_split_char(line, ' ');
		free(line);
	}
	if (!verif_verify(data, verify))
		return (print_error_map(1));
	return (1);
}

static int	load_map(int file_fd, t_data *data)
{
	if (!get_map(file_fd, data))
	{
		clean_texture_nb(&data->textures, 4);
		return (0);
	}
	if (!simple_verify_map(data->map) || !is_wall_surround(data->map))
	{
		ft_free_array(data->map);
		clean_texture_nb(&data->textures, 4);
		return (0);
	}
	return (1);
}

int	load_file(char **argv, t_data *data)
{
	int	fd;

	if (!valid_extension(argv[1], ".cub"))
		return (print_error_map(0));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		print_error_map(404);
		return (0);
	}
	if (!load_infos(fd, data)
		|| !load_map(fd, data))
	{
		close(fd);
		return (0);
	}
	return (1);
}
