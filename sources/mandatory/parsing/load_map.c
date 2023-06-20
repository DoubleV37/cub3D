/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:15:52 by vviovi            #+#    #+#             */
/*   Updated: 2023/06/20 14:21:04 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

static int	load_textures_info(int file_fd, t_data *data)
{
	if (!get_texture_info(file_fd, "NO", data, 0))
		return (0);
	if (!get_texture_info(file_fd, "SO", data, 1))
	{
		clean_texture_nb(&data->textures, 1);
		return (0);
	}
	if (!get_texture_info(file_fd, "WE", data, 2))
	{
		clean_texture_nb(&data->textures, 2);
		return (0);
	}
	if (!get_texture_info(file_fd, "EA", data, 3))
	{
		clean_texture_nb(&data->textures, 3);
		return (0);
	}
	return (1);
}

static int	load_colors(int file_fd, t_data *data)
{
	if (get_color_info(file_fd, 'F', data)
		&& get_color_info(file_fd, 'C', data))
		return (1);
	clean_texture_nb(&data->textures, 4);
	return (0);
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
	if (!load_textures_info(fd, data)
		|| !load_colors(fd, data)
		|| !load_map(fd, data))
	{
		close(fd);
		return (0);
	}
	return (1);
}
