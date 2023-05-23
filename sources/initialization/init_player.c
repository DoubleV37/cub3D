/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:30:26 by jduval            #+#    #+#             */
/*   Updated: 2023/05/23 17:45:02 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "cub3d.h"
#include "libft.h"

static int		find_unit(char **map);
static t_card	find_player_pos(t_player *player, char **map);
static void		set_direction(t_player *player, t_tool *tools, t_card view);

void	init_player(t_player *player, t_data *data)
{
	float	unit;
	t_card	start_view;

	unit = find_unit(data->map);
	data->tools.unit = unit;
	start_view = find_player_pos(player, data->map);
	data->map[player->indexs[X]][player->indexs[Y]] = '0';
	printf("--> %i\n", start_view);
	player->pos[X] = (player->indexs[X] * unit + unit / 3.0f);
	player->pos[Y] = (player->indexs[Y] * unit + unit / 3.0f);
	set_direction(player, &data->tools, start_view);
	player->speed = 3.0f;
	data->tools.rotate.angle = 4.0f;
	data->tools.rotate.cos_ang = cosf(data->tools.rotate.angle * RAD_CONV);
	data->tools.rotate.sin_ang = sinf(data->tools.rotate.angle * RAD_CONV);
	data->tools.rotate.cos_inv = cosf(data->tools.rotate.angle * RAD_CONV * (-1.0f));
	data->tools.rotate.sin_inv = sinf(data->tools.rotate.angle * RAD_CONV * (-1.0f));
}

static void	set_direction(t_player *player, t_tool *tools, t_card start)
{
	if (start == NO)
	{
		printf("1\n");
		tools->dir[X] = 0.0f;
		tools->dir[Y] = -FOV;
		player->angle = 90.0f;
	}
	else if (start == SO)
	{
		printf("2\n");
		tools->dir[X] = 0.0f;
		tools->dir[Y] = FOV;
		player->angle = 270;
	}
	else if (start == EA)
	{
		printf("3\n");
		tools->dir[Y] = 0.0f;
		tools->dir[X] = FOV;
		player->angle = 0.0f;
	}
	else
	{
		printf("4\n");
		tools->dir[Y] = 0.0f;
		tools->dir[X] = -FOV;
		player->angle = 180.0f;
	}
}

static int	find_unit(char **map)
{
	int	len_x;
	int	len_y;
	int	i;

	len_y = ft_array_len(map);
	i = -1;
	while (map[++i])
	{
		len_x = (int)ft_strlen(map[i]);
		if (map[i + 1] && len_x < (int)ft_strlen(map[i + 1]))
			len_x = (int)ft_strlen(map[i + 1]);
	}
	if (len_x > len_y)
		i = WIDTH / len_x;
	else
		i = WIDTH / len_y;
	while (1)
	{
		if (i * len_x + i < WIDTH && i * len_y + i < HEIGHT)
			break ;
		else
			i--;
	}
	return (i);
}


static t_card	find_player_pos(t_player *player, char **map)
{
	int	i;
	int	find;
	int	len;

	i = -1;
	while (map[++i])
	{
		len = ft_strlen(map[i]);
		find = ft_strcspn(map[i], "NSEW");
		if (find < len)
			break ;
	}
	player->indexs[X] = find;
	player->indexs[Y] = i;
	if (map[i] && map[i][find] == 'N')
		return (NO);
	else if (map[i] && map[i][find] == 'S')
		return (SO);
	else if (map[i] && map[i][find] == 'E')
		return (EA);
	else
		return (WE);
}
