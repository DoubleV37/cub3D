/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:50:20 by vviovi            #+#    #+#             */
/*   Updated: 2023/05/19 18:20:46 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "type.h"
# include "libft.h"

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

//map_get_info	-PARSING
int		get_texture_info(int file_fd, char *card, t_data *data, int index_tab);
int		get_color_info(int file_fd, char place, t_data *data);
int		get_map(int file_fd, t_data *data);

//content_verif	-PARSING
int		valid_extension(char *path, char *extension);
int		valid_color(int red, int green, int blue);
int		valid_texture(char *path_texture);

//map_verif	-PARSING
int		simple_verify_map(char **map);
int		is_wall_surround(char **map);

//utils_map	-PARSING
void	clean_texture_nb(t_texture *textures, int nb_textures);
char	*gnl_skip_void(int fd_file);
int		len_dbl_tab(char **tab);
int		len_string(char *str);
int		print_error_map(int type_error);

//load_map	-PARSING
int		load_file(char **argv, t_data *data);

//init_setup	-RAYCASTING
void	init_player(t_player *player, t_data *data);

//calculate_rotation	-RAYCASTING
void	calc_rotation(float *view, t_rot *rot, int flag);

//calculate_incr	-RAYCASTING
float	calculate_incr_x(t_player *player);
float	calculate_incr_y(t_player *player);

//draw_map		-DRAW
void	draw_map(t_data *data);

//draw_player	-DRAW
void	draw_player(mlx_image_t *img, t_player *player, int unit, int flag);

//draw_line	-DRAW
void	draw_line(mlx_image_t *img, float *pos, int32_t color);

//draw_utils	-DRAW
int32_t	color_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

//move_player	-MOVEMENTS
int		move_backward_forward(t_data *data, t_player *player, t_dir dir);

bool	check_collide(t_player *player, float *inc, int unit, char **map);

//rotate_player	-MOVEMENTS
int		rotate_player(t_data *data, t_player *player, t_dir dir);

//key_functions	-INPUT
int		movement_key(t_data *data);

#endif
