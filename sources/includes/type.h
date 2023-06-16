/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:43:28 by jduval            #+#    #+#             */
/*   Updated: 2023/06/16 17:34:08 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

//------DEFINE------//

# define WIDTH 1920
# define HEIGHT 1080

# include "MLX42.h"

# define RAD_CONV 0.01745
# define FOV 60

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
	MAP,
	PLAYER,
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
}	t_ray;

typedef struct s_rot
{
	float	angle;
	float	cos_ang;
	float	sin_ang;
	float	cos_inv;
	float	sin_inv;
}	t_rot;

typedef struct s_tool
{
	float	unit;
	float	dir[2];
	float	dist;
	float	delta_angle;
	t_rot	rotate;
}	t_tool;

typedef struct s_player
{
	float	pos[2];
	int		indexs[2];
	float	angle;
	float	speed;
	float	height;
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
	t_tool		tools;
	t_texture	textures;
}	t_data;

#endif
