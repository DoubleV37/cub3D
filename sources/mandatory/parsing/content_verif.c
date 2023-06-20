/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:57:22 by vviovi            #+#    #+#             */
/*   Updated: 2023/06/20 14:24:05 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

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

int	valid_color(int red, int green, int blue)
{
	return (red < 256 && green < 256 && blue < 256);
}

int	valid_texture(char *path_texture)
{
	int	fd;

	path_texture[ft_strlen(path_texture) - 1] = '\0';
	if (!valid_extension(path_texture, ".png"))
		return (0);
	fd = open(path_texture, O_RDONLY);
	if (fd < 2)
		return (0);
	close(fd);
	return (1);
}
