/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:34:11 by jduval            #+#    #+#             */
/*   Updated: 2023/05/17 14:34:50 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "includes/type.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	escape_hook(void *param)
{
	mlx_t	*mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	return ;
}

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_data		data;
	char	*txt = "1111111111,1000000001,1000000001,1000000001,1101111001,1101001001,1000001001,1000001001,1111111111";
	(void) argc;
	(void) argv;
	data.map = ft_split_str(txt, ",");
	data.mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (data.mlx == NULL)
	{
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (data.img == NULL)
	{
		mlx_close_window(data.mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	make_setup(&data.player, &data);
	draw_map(&data);
	if (mlx_image_to_window(data.mlx, &data.img, 0, 0) == -1)
	{
		mlx_close_window(data.mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	mlx_loop_hook(mlx, escape_hook, mlx);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	ft_free_array(data.map);
}
