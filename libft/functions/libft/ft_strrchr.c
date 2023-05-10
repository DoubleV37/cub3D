/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:16:47 by jduval            #+#    #+#             */
/*   Updated: 2023/04/01 12:10:18 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	size_t		lengh;
	char		*p;

	lengh = ft_strlen(s);
	i = lengh;
	p = (char *)s;
	while (i > 0)
	{
		if (s[i] == (char)c)
			return (p + i);
		i--;
	}
	if (i == 0 && s[i] == (char)c)
		return (p);
	return (NULL);
}
