/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:34:11 by jduval            #+#    #+#             */
/*   Updated: 2023/05/19 18:17:44 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
/*
#define WIDTH 500
#define HEIGHT 500

static void	escape_hook(void *param)
{
	mlx_t	*mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	return ;
}

static int32_t	color_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static void	trace_test(void *param)
{
	mlx_image_t	*img = param;
	uint32_t color;

	for (int i = 0; i < img->width; i++)
	{
		for (int y = 0; y < img->height; y++)
		{
			color = color_pixel(0, 100, 255, 255);
			mlx_put_pixel(img, i, y, color);

		}
	}
}*/

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		print_error_map(404);
		return (1);
	}
	if (!load_file(argv, &data))
	{
		clean_texture_nb(&data.textures, 4);
		ft_free_array(data.map);
		return (1);
	}
	clean_texture_nb(&data.textures, 4);
	ft_free_array(data.map);
	return (0);
	/*mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*img2;

	(void) argc;
	(void) argv;
	mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (mlx == NULL)
	{
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img2 = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (mlx == NULL)
	{
		mlx_close_window(mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	if (mlx_image_to_window(mlx, img, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	mlx_image_to_window(mlx, img2, 200, 200);
	trace_test(img);
	trace_test(img2);
	//img->enabled = false;
	img2->enabled = false;
	mlx_loop_hook(mlx, escape_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);*/
}
