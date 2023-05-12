/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:32:35 by vviovi            #+#    #+#             */
/*   Updated: 2023/05/12 11:48:37 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_error_map(int	type_error)
{
	if (type_error == 404)
		ft_putstr_fd("Error\nNo map found\n", 2);
	else if (type_error == 0)
		ft_putstr_fd("Error\nWrong file extension\n", 2);
	else if (type_error == 1)
		ft_putstr_fd("Error\nWrong texture file\n", 2);
	else if (type_error == 2)
		ft_putstr_fd("Error\nWrong color\n", 2);
	else if (type_error == 3)
		ft_putstr_fd("Error\nMap incorrect\n", 2);
}
