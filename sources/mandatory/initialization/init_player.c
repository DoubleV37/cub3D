/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:30:26 by jduval            #+#    #+#             */
/*   Updated: 2023/06/27 09:42:33 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"
#include "libft.h"
#include "MLX42.h"

static t_card	find_player_pos(t_player *player, char **map);
static void		set_vdirection(t_player *player, t_card view);

void	init_player(t_player *player, t_data *data)
{
	t_card	start_view;

	data->unit = SIZE;
	data->dfocal = (WIDTH / 2) / (tanf((FOV / 2) * RAD_CONV));
	start_view = find_player_pos(player, data->map);
	data->map[player->indexs[Y]][player->indexs[X]] = '0';
	player->pos[X] = (player->indexs[X] * data->unit + data->unit / 2.0f);
	player->pos[Y] = (player->indexs[Y] * data->unit + data->unit / 2.0f);
	set_vdirection(player, start_view);
	player->speed = SIZE / 20;
	player->rotate = ROTATE;
	player->delta_angle = (int)FOV / (float)WIDTH;
	mlx_set_mouse_pos(data->mlx, WIDTH / 2, HEIGHT / 2);
}

static void	set_vdirection(t_player *player, t_card start)
{
	if (start == NO)
	{
		player->dir[X] = 0.0f;
		player->dir[Y] = -1.0f;
		player->angle = 90.0f;
	}
	else if (start == SO)
	{
		player->dir[X] = 0.0f;
		player->dir[Y] = 1.0f;
		player->angle = 270;
	}
	else if (start == EA)
	{
		player->dir[Y] = 0.0f;
		player->dir[X] = 1.0f;
		player->angle = 0.0f;
	}
	else
	{
		player->dir[Y] = 0.0f;
		player->dir[X] = -1.0f;
		player->angle = 180.0f;
	}
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
