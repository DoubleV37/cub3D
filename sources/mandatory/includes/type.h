/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:43:28 by jduval            #+#    #+#             */
/*   Updated: 2023/07/07 08:34:04 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

//------DEFINE------//

# define WIDTH 1920
# define HEIGHT 1080
# define SIZE 64
# define RAD_CONV 0.0174532925
# define FOV 60
# define ROTATE 3

# include "MLX42.h"

//------ENUM------//

typedef enum e_line
{
	H,
	V
}	t_line;

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
	BACKGROUND,
	WALL,
}	t_img;

typedef enum e_dir
{
	FORWARD,
	BACKWARD,
	LEFTWARD,
	RIGHTWARD
}	t_dir;

//------STRUCT------//

typedef struct s_raytool
{
	int		id;
	float	dist[2];
	float	u_vector[2];
	float	ndist[2];
	int		step[2];
	int		ind[2];
	int		side;
}	t_raytool;

typedef struct s_ray
{
	float	pos[2];
	float	dist_perp;
	int		texture;
	int		num_ray;
}	t_ray;

typedef struct s_player
{
	float	pos[2];
	float	dir[2];
	int		indexs[2];
	float	angle;
	float	delta_angle;
	float	speed;
	float	rotate;
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
	mlx_image_t	*img[2];
	char		**map;
	float		dfocal;
	t_player	player;
	t_texture	textures;
	uint32_t	**text;
}	t_data;

#endif
