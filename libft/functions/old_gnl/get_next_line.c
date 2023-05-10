/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:38:29 by jduval            #+#    #+#             */
/*   Updated: 2023/04/01 12:21:27 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	ft_flag(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (-1);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

void	ft_move(char **buffer, int len)
{
	int	i;

	i = 0;
	while ((*buffer)[len + i])
	{
		(*buffer)[i] = (*buffer)[len + i];
		i++;
	}
	(*buffer)[i] = '\0';
}

int	ft_read_for(char **buffer, int fd)
{
	char	*tmp;
	int		output;
	int		index_n;

	tmp = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	output = read(fd, tmp, BUFFER_SIZE);
	if (!*buffer)
		*buffer = ft_calloc(sizeof(char), 1);
	*buffer = ft_strjoin_gnl(*buffer, tmp);
	index_n = ft_flag(*buffer);
	while (index_n < 0 && BUFFER_SIZE == output)
	{
		output = read(fd, tmp, BUFFER_SIZE);
		tmp[output] = '\0';
		if (output <= 0)
		{
			free (tmp);
			return (-1);
		}
		*buffer = ft_strjoin_gnl(*buffer, tmp);
		index_n = ft_flag(*buffer);
	}
	free (tmp);
	return (index_n);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024] = {NULL};
	char		*str;
	int			index_n;
	int			output;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	output = ft_read_for(&buffer[fd], fd);
	if (output == -1 && ft_strlen(buffer[fd]) == 0)
	{
		free (buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	index_n = ft_flag(buffer[fd]);
	str = ft_substr(buffer[fd], 0, index_n);
	if (ft_flag(buffer[fd]) == -1)
	{
		free (buffer[fd]);
		buffer[fd] = NULL;
	}
	else
		ft_move(&buffer[fd], index_n);
	return (str);
}
