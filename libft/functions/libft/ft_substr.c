/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:28:52 by jduval            #+#    #+#             */
/*   Updated: 2023/04/01 12:16:32 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		new_s = ft_calloc(1, 1);
		return (new_s);
	}
	s_len -= start;
	if (s_len > len)
		s_len = len;
	new_s = malloc(sizeof(char) * (s_len + 1));
	if (new_s == NULL)
		return (NULL);
	ft_strlcpy(new_s, &s[start], s_len + 1);
	return (new_s);
}
