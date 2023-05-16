/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:43:28 by jduval            #+#    #+#             */
/*   Updated: 2023/05/15 16:31:11 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# define WIDTH 1920
# define HEIGHT 1080
//------ENUM------//

typedef enum e_coord
{
	X,
	Y
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

//------STRUCT------//

typedef struct s_setup
{
	float	focal[2];
	float	cam1[2];
	float	cam2[2];
	float	step;
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
	mlx_texture_t	texture[4];
	int				unit[2];
	int				color_floor[3];
	int				color_ceil[3];
}	t_texture;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*images;
	char		**map;
	t_player	player;
	t_texture	textures;
}	t_data;

#endif
