/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:34:11 by jduval            #+#    #+#             */
/*   Updated: 2023/05/22 17:27:11 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

static void	display_infos(t_data *data, bool yes);

static void	key_input(void *param)
{
	t_data	*data = param;

	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	else if (movement_key(data) == 0)
		return ;
	return ;
}

static int	init_image(t_data *data)
{
	data->img[BACKSCREEN] = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img[BACKSCREEN] == NULL)
		return (printf("%s", mlx_strerror(mlx_errno)));
	data->img[WALL] = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img[WALL] == NULL)
		return (printf("%s", mlx_strerror(mlx_errno)));
	data->img[MAP] = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img[MAP] == NULL)
		return (printf("%s", mlx_strerror(mlx_errno)));
	data->img[PLAYER] = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img[PLAYER] == NULL)
		return (printf("%s", mlx_strerror(mlx_errno)));
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
	{
		print_error_map(404);
		return (1);
	}
	if (!load_file(argv, &data))
		return (1);
	data.mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (data.mlx == NULL)
	{
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	if (init_image(&data) != 0)
	{
		mlx_terminate(data.mlx);
		return (1);
	}
	init_player(&data.player, &data);
	display_infos(&data, false);
	draw_map(&data);
	draw_background_ceiling(&data);
	draw_background_floor(&data);
	if (mlx_image_to_window(data.mlx, data.img[BACKSCREEN], 0, 0) == -1)
	{
		mlx_close_window(data.mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	if (mlx_image_to_window(data.mlx, data.img[MAP], 0, 0) == -1)
	{
		mlx_close_window(data.mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	if (mlx_image_to_window(data.mlx, data.img[PLAYER], 0, 0) == -1)
	{
		mlx_close_window(data.mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	mlx_loop_hook(data.mlx, key_input, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	clean_texture_nb(&data.textures, 4);
	ft_free_array(data.map);
}

static void	display_infos(t_data *data, bool yes)
{
	if (yes == false)
		return ;
	printf("map : \n");
	for (int i = 0; data->map[i]; i++)
		printf("%s\n", data->map[i]);
	printf("player : \n");
	printf("pos[X] = %f\tpos[Y] = %f\n", data->player.pos[X], data->player.pos[Y]);
	printf("index[X] = %i\tindex[Y] = %i\n", data->player.indexs[X], data->player.indexs[Y]);
	printf("Setup : \n");
	printf("focal[X] = %f\tfocal[Y] = %f\t len_focal = %f\n", data->setup.focal[X], data->setup.focal[Y], data->setup.len_focal);
	printf("cam[X] = %f\tcam[Y] = %f\n", data->setup.cam[X], data->setup.cam[Y]);
	printf("nbr_of_ray = %f\n", data->setup.nbr_of_ray);
	printf("step = %f\n", data->setup.step);
	printf("delta_angle = %f\n", data->setup.delta_angle);
	//printf("cos_x = %f\n", data->setup.cos_x);
	//printf("cos_y = %f\n", data->setup.cos_y);
	printf("unit = %f\n", data->setup.unit);
}
