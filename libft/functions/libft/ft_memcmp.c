/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:35:10 by jduval            #+#    #+#             */
/*   Updated: 2023/04/01 12:05:37 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*new_s1;
	unsigned char	*new_s2;
	size_t			i;

	new_s1 = (unsigned char *) s1;
	new_s2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (new_s1[i] < new_s2[i])
			return (new_s1[i] - new_s2[i]);
		else if (new_s1[i] > new_s2[i])
			return (new_s1[i] - new_s2[i]);
		i++;
	}
	return (new_s1[i] - new_s2[i]);
}
