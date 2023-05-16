/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:57:22 by vviovi            #+#    #+#             */
/*   Updated: 2023/05/16 15:13:08 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	valid_extension(char *path, char *extension)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(path);
	len2 = ft_strlen(extension);
	if (len1 > len2 && ft_strncmp(&path[len1 - len2], extension, len2) == 0)
		return (1);
	return (0);
}

int	valid_color(char **rgb_val)
{
	return (0);
}

int	valid_texture(char *path_texture)
{
	int	fd;

	if (!valid_extension(path_texture, ".png"))
	{
		print_error_map(1);
		return (0);
	}
	fd = open(path_texture, O_RDONLY);
	if (fd < 2)
	{
		print_error_map(1);
		return (0);
	}
	close(fd);
	return (1);
}
