/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:30:26 by jduval            #+#    #+#             */
/*   Updated: 2023/05/18 18:22:11 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"
#include "libft.h"

static void	set_focal_start(t_setup *setup, t_player *player);
static void	set_cam_start(t_setup *setup, t_player *player);
static int	find_unit(char **map);
static void	find_player_pos(t_player *player, char **map);

void	init_player(t_player *player, t_data *data)
{
	int	unit;

	unit = find_unit(data->map);
	find_player_pos(player, data->map);
	data->setup.nbr_of_ray = WIDTH;
	player->pos[X] = (player->indexs[X] * unit + unit / 3);
	player->pos[Y] = (player->indexs[Y] * unit + unit / 3);
	set_focal_start(&data->setup, player);
	set_cam_start(&data->setup, player);
	data->setup.step = CAM / data->setup.nbr_of_ray;
	data->setup.delta_angle = atanf(data->setup.step / data->setup.len_focal);
	data->setup.unit = unit;
	player->pace = 3;
}

static void	set_focal_start(t_setup *setup, t_player *player)
{
	setup->len_focal = 1 / tanf(((FOV / 2) * M_PI) / 180);
	if (player->start_view == NO)
	{
		setup->focal[X] = player->pos[X];
		setup->focal[Y] = player->pos[Y] - setup->len_focal;
	}
	else if (player->start_view == SO)
	{
		setup->focal[X] = player->pos[X];
		setup->focal[Y] = player->pos[Y] + setup->len_focal;
	}
	else if (player->start_view == EA)
	{
		setup->focal[X] = player->pos[X] + setup->len_focal;
		setup->focal[Y] = player->pos[Y];
	}
	else
	{
		setup->focal[X] = player->pos[X] - setup->len_focal;
		setup->focal[Y] = player->pos[Y];
	}
}

static void	set_cam_start(t_setup *setup, t_player *player)
{
	if (player->start_view == NO)
	{
		setup->cam[X] = player->pos[X] - (CAM / 2);
		setup->cam[Y] = player->pos[Y];
	}
	else if (player->start_view == SO)
	{
		setup->cam[X] = player->pos[X] + (CAM / 2);
		setup->cam[Y] = player->pos[Y];
	}
	else if (player->start_view == EA)
	{
		setup->cam[X] = player->pos[X];
		setup->cam[Y] = player->pos[Y] - (CAM / 2);
	}
	else
	{
		setup->cam[X] = player->pos[X];
		setup->cam[Y] = player->pos[Y] + (CAM / 2);	
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


static void	find_player_pos(t_player *player, char **map)
{
	int	i;
	int	find;
	int	len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		find = ft_strcspn(map[i], "NSEW");
		if (find < len)
			break ;
		i++;
	}
	if ( map[i] && map[i][find] == 'N')
		player->start_view = NO;
	else if (map[i] && map[i][find] == 'S')
		player->start_view = SO;
	else if (map[i] && map[i][find] == 'E')
		player->start_view = EA;
	else
		player->start_view = WE;
	player->indexs[X] = find;
	player->indexs[Y] = i;
	map[i][find] = '0';
}
