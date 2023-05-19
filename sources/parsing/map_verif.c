/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:57:22 by vviovi            #+#    #+#             */
/*   Updated: 2023/05/19 13:32:34 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	simple_verify_map(char **map)
{
	int	i;
	int	j;
	int	is_player;

	i = 0;
	is_player = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || i == ft_array_len(map) - 1
				|| j == 0 || j == ft_strlen(map[i]) - 1) && map[i][j] != '1')
				return (print_error_map(3));
			if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E') && is_player == 0)
				is_player = 1;
			else
				return (print_error_map(3));
			j++;
		}
		i++;
	}
	return (1);
}

int	is_wall_surround(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i > 0 && i < (ft_array_len(map) - 1) && map[i][j] == '0')
			{
				if (ft_strlen(map[i - 1]) < (j + 1)
					|| ft_strlen(map[i + 1]) < (j + 1))
					return (0);
				if ((j - 1 > -1 && map[i - 1][j - 1] == ' ')
					|| (j + 1 < ft_strlen(map[i - 1])
					&& map[i - 1][j + 1] == ' ') || (map[i - 1][j] == ' '))
					return (0);
				if ((j - 1 > -1 && map[i + 1][j - 1] == ' ')
					|| (j + 1 < ft_strlen(map[i + 1]) && map[i + 1][j + 1] == ' ')
					|| (map[i + 1][j] == ' '))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
