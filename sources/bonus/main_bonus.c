/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:34:11 by jduval            #+#    #+#             */
/*   Updated: 2023/06/27 11:43:52 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	init_start(t_data *data, char **argv);

int	main(int argc, char **argv)
{
	t_data	data;
	int		flag;

	if (argc != 2)
		return (print_error_map(404));
	flag = init_start(&data, argv);
	if (flag == 2)
		ft_free_array(data.map);
	if (flag > 0)
		return (1);
	mlx_set_cursor_mode(data.mlx, 0x00034002);
	mlx_loop_hook(data.mlx, user_inputs, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	ft_free_array(data.map);
	free_textures(data.text);
	return (0);
}

static int	init_start(t_data *data, char **argv)
{
	if (!load_file(argv, data))
		return (1);
	data->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (data->mlx == NULL)
	{
		printf("%s", mlx_strerror(mlx_errno));
		return (2);
	}
	if (init_images(data) != 0)
	{
		mlx_terminate(data->mlx);
		return (2);
	}
	init_player(&data->player, data);
	draw_background_ceiling(data);
	draw_background_floor(data);
	if (render_start(data) == 1 || resize_texture(data) == 1)
	{
		mlx_terminate(data->mlx);
		return (2);
	}
	return (0);
}
