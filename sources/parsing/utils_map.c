/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:32:35 by vviovi            #+#    #+#             */
/*   Updated: 2023/05/16 09:38:23 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_skip_void(int	fd_file)
{
	char	*line;
	size_t	len;
	int		i;

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
		line = ft_gnl(fd_file);
	}
	return (line);
}

int	get_texture_info(int file_fd, char *card, t_data *data)
{
	char	*line;
	char	**dataline;

	line = gnl_skip_void(file_fd);
	if (!line)
		return (0);
	dataline = ft_split(line, ' ');
	if (ft_strncmp(dataline[0], card, ft_strlen(dataline[0])) == 0
		&& ft_strlen(dataline[0]) == ft_strlen(card))
	{
		//verif chemin fichier et extension et mettre l'erreur si besoin
		data->textures.texture[card] = unefonction;
		return (1);
	}
	return (0);
}

int	get_color_info(int file_fd, char *place, t_data *data)
{
	char	*line;
	char	**dataline;

	line = gnl_skip_void(file_fd);
	if (!line)
		return (0);
	dataline = ft_split(line, ' ');
	if (ft_strncmp(dataline[0], place, ft_strlen(dataline[0])) == 0
		&& ft_strlen(dataline[0]) == ft_strlen(place))
	{
		//verif color (bien en 255)et mettre l'erreur si besoin
		//sauv ds data
		return (1);
	}
	return (0);
}

void	print_error_map(int	type_error)
{
	if (type_error == 404)
		ft_putstr_fd("Error\nNo map found\n", 2);
	else if (type_error == 0)
		ft_putstr_fd("Error\nWrong file extension\n", 2);
	else if (type_error == 1)
		ft_putstr_fd("Error\nWrong texture file\n", 2);
	else if (type_error == 2)
		ft_putstr_fd("Error\nWrong color\n", 2);
	else if (type_error == 3)
		ft_putstr_fd("Error\nMap incorrect\n", 2);
}
