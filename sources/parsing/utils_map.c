/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:32:35 by vviovi            #+#    #+#             */
/*   Updated: 2023/05/16 18:11:40 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_skip_void(int fd_file)
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

int	len_dbl_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

int	print_error_map(int type_error)
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
	return (0);
}
