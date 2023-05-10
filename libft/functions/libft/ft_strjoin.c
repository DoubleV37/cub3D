/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:47:46 by jduval            #+#    #+#             */
/*   Updated: 2023/04/01 12:13:26 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_alloc;
	char	*new_s;
	size_t	size_srcs;

	if (!s1 || !s2)
		return (NULL);
	size_alloc = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_s = malloc(size_alloc * sizeof(char));
	if (!new_s)
		return (NULL);
	size_alloc = ft_strlen(s1) + 1;
	ft_strlcpy(new_s, s1, size_alloc);
	size_alloc = ft_strlen(new_s);
	size_srcs = ft_strlen(s1) + ft_strlen(s2) + 1;
	ft_strlcpy(&new_s[size_alloc], s2, size_srcs);
	return (new_s);
}
