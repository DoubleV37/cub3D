/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:43:28 by jduval            #+#    #+#             */
/*   Updated: 2023/05/12 10:24:56 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

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
	EA,
	WE
}	t_card;

typedef enum e_rgb
{
	R,
	G,
	B
}	t_rgb;

//------STRUCT------//

typedef struct s_player
{
	int	*pos[2];
	int	*focal[2];
	int	fov[2];
}	t_player;

typedef struct s_texture
{
	mlx_texture_t	texture[4];
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
