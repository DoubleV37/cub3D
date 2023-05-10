/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:40:41 by jduval            #+#    #+#             */
/*   Updated: 2023/05/10 14:27:19 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	size_t		lengh;
	char		*p;

	lengh = ft_strlen(s);
	i = 0;
	p = (char *)s;
	while (i <= lengh)
	{
		if (s[i] == (char)c)
			return (p + i);
		i++;
	}
	return (NULL);
}
