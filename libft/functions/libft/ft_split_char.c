/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:36:30 by jduval            #+#    #+#             */
/*   Updated: 2023/05/10 14:30:30 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_len_y(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (s[i] == '\0' && c == '\0')
		return (len);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			len++;
		}
		if (s[i])
			i++;
	}
	if (i > 0 && s[i - 1] != c)
		len += 1;
	return (len);
}

static size_t	ft_len_x(char const *s, char c, size_t start)
{
	size_t	i;
	size_t	len;

	i = start ;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (len);
		len++;
		i++;
	}
	return (len);
}

static int	ft_null(char **srcs_tab, size_t index)
{
	if (srcs_tab[index] == NULL)
		return (1);
	return (0);
}

static int	ft_fill(char **srcs_tab, size_t len_y, char c, const char *s)
{
	size_t	y;
	size_t	start;
	size_t	len_x;
	int		is_null;

	y = 0;
	start = 0;
	len_x = 0;
	while (y < len_y)
	{
		start += len_x;
		while (s[start] == c && s[start])
			start++;
		len_x = ft_len_x(s, c, start);
		srcs_tab[y] = ft_substr(s, start, len_x);
		is_null = ft_null(srcs_tab, y);
		if (is_null == 1)
			return (1);
		y++;
	}
	srcs_tab[y] = NULL;
	return (0);
}

char	**ft_split_char(char *s, char c)
{
	char	**srcs_tab;
	size_t	len_y;
	size_t	i;
	int		error;

	i = 0;
	if (!s || s[0] == '\0')
		return (NULL);
	len_y = ft_len_y(s, c);
	srcs_tab = malloc((len_y + 1) * sizeof(char *));
	if (srcs_tab == NULL)
		return (NULL);
	error = ft_fill(srcs_tab, len_y, c, s);
	if (error == 1)
	{
		while (srcs_tab[i])
		{
			free (srcs_tab[i]);
			i++;
		}
		free (srcs_tab);
		return (NULL);
	}
	return (srcs_tab);
}
