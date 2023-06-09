/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:57:22 by vviovi            #+#    #+#             */
/*   Updated: 2023/07/07 12:49:26 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static int	is_wall_simple_verif(int i, int j, char **map)
{
	if ((i == 0 || i == ft_array_len(map) - 1
			|| j == 0 || j == (int)ft_strlen(map[i]) - 1)
		&& (map[i][j] != '1' && map[i][j] != ' '))
		return (print_error_map(3));
	return (1);
}

static int	verif_player(int i, int j, char **map, int *player_fnd)
{
	if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
		|| map[i][j] == 'E') && *player_fnd == 0)
		*player_fnd = 1;
	else if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
		|| map[i][j] == 'E') && *player_fnd != 0)
		return (print_error_map(3));
	return (1);
}

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
			if (!is_wall_simple_verif(i, j, map)
				|| !verif_player(i, j, map, &is_player))
				return (0);
			j++;
		}
		i++;
	}
	if (is_player == 0)
		return (print_error_map(4));
	return (1);
}

static int	verif_hole_map(int i, int j, char **map)
{
	if ((int)ft_strlen(map[i - 1]) < (j + 2)
		|| (int)ft_strlen(map[i + 1]) < (j + 2))
		return (print_error_map(3));
	if ((j - 1 > -1 && map[i - 1][j - 1] == ' ')
		|| (j + 1 < (int)ft_strlen(map[i - 1])
		&& map[i - 1][j + 1] == ' ') || (map[i - 1][j] == ' '))
		return (print_error_map(3));
	if ((j - 1 > -1 && map[i + 1][j - 1] == ' ')
		|| (j + 1 < (int)ft_strlen(map[i + 1])
		&& map[i + 1][j + 1] == ' ')
		|| (map[i + 1][j] == ' '))
		return (print_error_map(3));
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
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if (verif_hole_map(i, j, map) == 0)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
