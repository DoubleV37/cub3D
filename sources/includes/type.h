/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:43:28 by jduval            #+#    #+#             */
/*   Updated: 2023/05/18 11:31:42 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

//------DEFINE------//

# define WIDTH 1920
# define HEIGHT 1080

# include "MLX42.h"
# define CAM 1
# define FOV 90

//------ENUM------//

typedef enum e_coord
{
	X,
	Y,
}	t_coord;

typedef enum e_card
{
	NO,
	SO,
	WE,
	EA
}	t_card;

typedef enum e_rgb
{
	R,
	G,
	B
}	t_rgb;

typedef enum e_img
{
	BACKSCREEN,
	WALL,
	MAP,
	PLAYER
}	t_img;

typedef enum e_dir
{
	FORWARD,
	BACKWARD,
	LEFTWARD,
	RIGHTWARD
}	t_dir;

//------STRUCT------//

typedef struct s_setup
{
	float	focal[2];
	float	len_focal;
	float	cam[2];
	float	nbr_of_ray;
	float	step;
	float	delta_angle;
	float	cos_x;
	float	cos_y;
	int		unit;
	int		pace;
}	t_setup;

typedef struct s_player
{
	float	pos[2];
	int		indexs[2];
	t_card	start_view;
	t_setup	setup;
}	t_player;

typedef struct s_texture
{
	mlx_texture_t	*texture[4];
	int				color_floor[3];
	int				color_ceil[3];
}	t_texture;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img[4];
	char		**map;
	t_player	player;
	t_texture	textures;
}	t_data;

#endif
