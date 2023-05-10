/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:56:34 by jduval            #+#    #+#             */
/*   Updated: 2023/05/10 14:32:41 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	fill_empty_array(char **array);
static int	fill_array(char **array, int word, char *s, const char *delim);
static int	find_word(const char *str, const char *delim);
static int	count_words(const char *str, const char *delim);

char	**ft_split_str(const char *s, const char *delim)
{
	char	**array;
	int		flag;
	int		len;

	flag = 0;
	if (s[0] != '\0')
		len = count_words(s, delim);
	else
		len = 1;
	array = malloc(sizeof(char *) * (len + 1));
	if (array == NULL)
		return (NULL);
	array[len] = NULL;
	if (s[0] != '\0')
		flag = fill_array(array, len, (char *)s, delim);
	else
		flag = fill_empty_array(array);
	if (flag == 1)
	{
		ft_free_array(array);
		return (NULL);
	}
	return (array);
}

static int	find_word(const char *str, const char *delim)
{
	int	i;

	i = 0;
	while (ft_strchr(delim, str[i]) != NULL)
		i++;
	return (i);
}

static int	count_words(const char *str, const char *delim)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		i += find_word(&str[i], delim);
		if (str[i] != '\0')
			count++;
		while (str[i] && ft_strchr(delim, str[i]) == NULL)
			i++;
		if (str[i] == '\0')
			break ;
	}
	return (count);
}

static int	fill_empty_array(char **array)
{
	array[0] = ft_strdup("");
	if (array[0] == NULL)
		return (1);
	return (0);
}

static int	fill_array(char **array, int word, char *s, const char *delim)
{
	int	i;
	int	start;
	int	len;

	start = 0;
	len = 0;
	i = 0;
	while (i < word)
	{
		start += find_word(&s[start], delim);
		len = ft_strcspn(&s[start], delim);
		array[i] = ft_substr(s, start, len);
		start += len;
		if (array[i] == NULL)
			return (1);
		i++;
	}
	return (0);
}
