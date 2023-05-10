/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:17:27 by jduval            #+#    #+#             */
/*   Updated: 2023/04/01 12:14:23 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lengh;

	lengh = 0;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[lengh] && lengh < size)
		lengh++;
	if (dst[lengh] == '\0')
	{
		while (lengh < size - 1 && src[i] != '\0')
		{
			dst[lengh] = src[i];
			lengh++;
			i++;
		}
		dst[lengh] = '\0';
	}
	lengh = lengh - i + ft_strlen(src);
	return (lengh);
}
