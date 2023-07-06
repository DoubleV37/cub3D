/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:34:11 by jduval            #+#    #+#             */
/*   Updated: 2023/07/06 16:53:36 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	init_start(t_data *data, char **argv);
static int	init_parsing_mlx(t_data *data, char **argv);

int	main(int argc, char **argv)
{
	t_data	data;
	int		flag;

	if (argc != 2)
		return (print_error_map(404));
	data.doors = NULL;
	flag = init_start(&data, argv);
	if (flag == 2)
	{
		clean_texture_nb(&data.textures, 4, data.door_frames);
		free_door_list(&data.doors);
		ft_free_array(data.map);
	}
	if (flag > 0)
		return (1);
	mlx_key_hook(data.mlx, modifier_inputs, &data);
	mlx_loop_hook(data.mlx, user_inputs, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	ft_free_array(data.map);
	free_door_list(&data.doors);
	free_textures(data.text);
	return (0);
}

static int	init_start(t_data *data, char **argv)
{
	int	flag;

	flag = init_parsing_mlx(data, argv);
	if (flag > 0)
		return (flag);
	init_parameters(&data->player, data);
	if (data->there_is_door == true && data->door_frames <= 1)
	{
		printf("Need at least 2 frames of door\n");
		return (2);
	}
	if (init_images(data) != 0 || render_start(data) == 1
		|| resize_texture(data) == 1)
	{
		mlx_terminate(data->mlx);
		return (2);
	}
	draw_background_ceiling(data);
	draw_background_floor(data);
	return (0);
}

static int	init_parsing_mlx(t_data *data, char **argv)
{
	if (!load_file(argv, data))
		return (1);
	data->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (data->mlx == NULL)
	{
		printf("%s", mlx_strerror(mlx_errno));
		return (2);
	}
	if (create_door_list(data) != 0)
	{
		mlx_terminate(data->mlx);
		return (2);
	}
	return (0);
}
