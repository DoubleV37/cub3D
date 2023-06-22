/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:32:35 by vviovi            #+#    #+#             */
/*   Updated: 2023/06/22 12:46:30 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>

char	*gnl_skip_void(int fd_file)
{
	char	*line;
	size_t	len;
	size_t	i;

	line = ft_gnl(fd_file);
	while (line)
	{
		i = 0;
		len = ft_strlen(line);
		while (i < len)
		{
			if (!ft_isspace(line[i]))
				return (line);
			i++;
		}
		free(line);
		line = ft_gnl(fd_file);
	}
	return (line);
}

int	len_dbl_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

int	len_string(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	clean_texture_nb(t_texture *textures, int nb_textures)
{
	int	i;

	i = 0;
	while (i < nb_textures)
	{
		if (textures->texture[i])
			mlx_delete_texture(textures->texture[i]);
		i++;
	}
}

int	print_error_map(int type_error)
{
	if (type_error == 404)
		ft_putstr_fd(2, "Error\nNo map found\n");
	else if (type_error == 0)
		ft_putstr_fd(2, "Error\nWrong file extension\n");
	else if (type_error == 1)
		ft_putstr_fd(2, "Error\nWrong map parameters\n");
	else if (type_error == 2)
		ft_putstr_fd(2, "Error\nWrong color\n");
	else if (type_error == 3)
		ft_putstr_fd(2, "Error\nMap incorrect\n");
	else if (type_error == 4)
		ft_putstr_fd(2, "Error\nMissing player in map\n");
	return (0);
}
