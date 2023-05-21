/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:57:22 by vviovi            #+#    #+#             */
/*   Updated: 2023/05/21 10:44:09 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			if (map[i][j] != ' ' && map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'E' && map[i][j] != 'W')
				return (print_error_map(3));
			if ((i == 0 || i == ft_array_len(map) - 1
					|| j == 0 || j == len_string(map[i]) - 1)
				&& (map[i][j] != '1' && map[i][j] != ' '))
				return (print_error_map(3));
			if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E') && is_player == 0)
				is_player = 1;
			else if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E') && is_player != 0)
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
				if (len_string(map[i - 1]) < (j + 1)
					|| len_string(map[i + 1]) < (j + 1))
					return (print_error_map(3));
				if ((j - 1 > -1 && map[i - 1][j - 1] == ' ')
					|| (j + 1 < len_string(map[i - 1])
					&& map[i - 1][j + 1] == ' ') || (map[i - 1][j] == ' '))
					return (print_error_map(3));
				if ((j - 1 > -1 && map[i + 1][j - 1] == ' ')
					|| (j + 1 < len_string(map[i + 1])
					&& map[i + 1][j + 1] == ' ')
					|| (map[i + 1][j] == ' '))
					return (print_error_map(3));
			}
			j++;
		}
		i++;
	}
	return (1);
}
