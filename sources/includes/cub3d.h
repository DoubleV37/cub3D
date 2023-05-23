/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:50:20 by vviovi            #+#    #+#             */
/*   Updated: 2023/05/23 17:46:57 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "type.h"
# include "libft.h"

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

//-------------PARSING---------------//
//map_get_info
int		get_texture_info(int file_fd, char *card, t_data *data, int index_tab);
int		get_color_info(int file_fd, char place, t_data *data);
int		get_map(int file_fd, t_data *data);
//file : content_verif.c
int		valid_extension(char *path, char *extension);
int		valid_color(int red, int green, int blue);
int		valid_texture(char *path_texture);
//file : map_verif.c
int		simple_verify_map(char **map);
int		is_wall_surround(char **map);
//file : utils_map.c
void	clean_texture_nb(t_texture *textures, int nb_textures);
char	*gnl_skip_void(int fd_file);
int		len_dbl_tab(char **tab);
int		len_string(char *str);
int		print_error_map(int type_error);
//file : load_map.c
int		load_file(char **argv, t_data *data);

//-------------INITIALIZATION---------------//
//file : init_player.c
void	init_player(t_player *player, t_data *data);
//file : init_images.c
int		init_images(t_data *data);

//-------------DRAW---------------//
//file : draw_map.c
void	draw_map(t_data *data);
//file : draw_player.c
void	draw_player(mlx_image_t *img, t_player *player, int unit, int flag);
//file : draw_line.c
void	draw_line(mlx_image_t *img, float *pos, int32_t color);
void	draw_pov(t_data *data, t_player *player, int flag);
//file : draw_utils.c
int32_t	color_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
//file : draw_background.c
void	draw_background_ceiling(t_data *data);
void	draw_background_floor(t_data *data);

//-------------MOVEMENTS---------------//
//file : move_player.c
int		move_backward_forward(t_data *data, t_player *player, t_dir dir);
//file : shift_player.c
int		move_left_right(t_data *data, t_player *player, t_dir dir);
//file : wall_collision.c
bool	check_collide(float *pos, int unit, char **map);
//file : rotate_player.c
int		rotate_player(t_data *data, t_player *player, t_dir dir);

//-------------INPUT---------------//
//file : key_functions.c
int		movement_key(t_data *data);

#endif
