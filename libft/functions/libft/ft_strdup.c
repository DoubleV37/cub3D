/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:08:26 by jduval            #+#    #+#             */
/*   Updated: 2023/04/01 12:12:24 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*new_s;
	size_t	size_s;

	size_s = ft_strlen(s) + 1;
	new_s = (char *) ft_calloc(size_s, sizeof(char));
	if (new_s == NULL)
		return (NULL);
	ft_strlcpy(new_s, s, size_s);
	return (new_s);
}
