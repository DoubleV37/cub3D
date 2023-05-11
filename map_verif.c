/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:57:22 by vviovi            #+#    #+#             */
/*   Updated: 2023/05/11 16:54:59 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	valid_extension(char *path, char *extension)
{
	if (ft_strlen(path) <= ft_strlen(extension))
		return (0);
	if (ft_strncmp(&path[ft_strlen(path) - ft_strlen(extension)],
			extension, ft_strlen(extension)) == 0)
		return (1);
	return (0);
}
