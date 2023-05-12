/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:15:52 by vviovi            #+#    #+#             */
/*   Updated: 2023/05/12 14:19:34 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/type.h"
#include "map_verif.c"
#include "utils_map.c"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	load_textures_info(int file_fd, t_data *data);

int	load_colors(int file_fd, t_data *data);

int	load_map(int file_fd, t_data *data);

int	load_file(char **argv, t_data *data)
{
	int		fd;

	if (!valid_extension(argv[1], ".cub"))
		return (0);
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
