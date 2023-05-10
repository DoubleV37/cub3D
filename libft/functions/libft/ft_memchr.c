/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:10:00 by jduval            #+#    #+#             */
/*   Updated: 2023/04/01 12:05:13 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new_s;
	unsigned char	new_c;
	size_t			i;

	new_c = (unsigned char) c;
	new_s = (unsigned char *) s;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (new_s[i] == new_c)
			return (new_s + i);
		i++;
	}
	return (NULL);
}
