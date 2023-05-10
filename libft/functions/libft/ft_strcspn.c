/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:20:33 by jduval            #+#    #+#             */
/*   Updated: 2023/05/10 14:27:37 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcspn(char const *str, char const *reject)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(reject, str[i]) != NULL)
			return (i);
		i++;
	}
	return (i);
}
