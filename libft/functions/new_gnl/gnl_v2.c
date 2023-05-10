/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_v2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:41:07 by jduval            #+#    #+#             */
/*   Updated: 2023/04/01 12:22:50 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
#endif

#ifndef OPEN_MAX
# define OPEN_MAX 1024
#endif

static char	*ft_gnl_rec(int fd, int len, char *save);

char	*ft_gnl(int fd)
{
	static char	save[OPEN_MAX][BUFFER_SIZE + 1] = {0};
	char		head[BUFFER_SIZE + 1];
	int			len;
	char		*line;

	ft_strlcpy(head, save[fd], BUFFER_SIZE + 1);
	len = ft_strcspn(head, "\n");
	if (head[len] == '\n')
	{
		line = ft_substr(head, 0, len + 1);
		if (line == NULL)
			return (NULL);
		ft_strlcpy(save[fd], head + len + 1, BUFFER_SIZE + 1);
		return (line);
	}
	line = ft_gnl_rec(fd, len, save[fd]);
	if (line == NULL)
		return (NULL);
	ft_memcpy(line, head, len);
	return (line);
}

static char	*ft_gnl_rec(int fd, int len, char *save)
{
	char	buf[BUFFER_SIZE + 1];
	char	*line;
	int		rlen;

	rlen = read(fd, buf, BUFFER_SIZE);
	if (rlen == -1)
		return (NULL);
	buf[rlen] = '\0';
	if (rlen == 0 && len == 0)
		return (NULL);
	rlen = ft_strcspn(buf, "\n");
	rlen += (buf[rlen] == '\n');
	if (rlen != BUFFER_SIZE || buf[rlen - 1] == '\n')
	{
		line = ft_calloc(len + rlen + 1, sizeof(char));
		ft_strlcpy(save, buf + rlen, BUFFER_SIZE + 1);
	}
	else
		line = ft_gnl_rec(fd, len + BUFFER_SIZE, save);
	if (line == NULL)
		return (NULL);
	ft_memcpy(line + len, buf, rlen);
	return (line);
}
