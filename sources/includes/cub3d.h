/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:50:20 by vviovi            #+#    #+#             */
/*   Updated: 2023/06/15 17:18:54 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
//file : init_tools.c
void	init_tools(t_tool *tools);
void	set_vplane(t_tool *tools);
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
//file : render_image.c
int		render_start(t_data *data);
//file : draw_texture.c
int		*get_line_texture(int pos, mlx_texture_t texture, float scale_size);
void	draw_texture_line(t_data *data, int *line_texture, int x, int length);
float	scale_calculate(float dist_foc, float dist, float size_texture);

//-------------RAYCASTING---------------//
//file : raycasting.c
void	raycasting(t_data *data, t_player *player);
//file : find_wall.c
void	find_h_wall(t_data *data, t_ray *ray, float alpha);
void	find_v_wall(t_data *data, t_ray *ray, float alpha);
//file : find_wall_utils.c
void	increment_coord(t_ray *ray, float *step, t_data *data);
void	infinite_dist(int type, t_ray *ray, float alpha);
bool	is_in_screen(int x, int y, char **map, t_ray *ray);
bool	is_in_screen(int x, int y, char **map, t_ray *ray);
//file : find_collide.c
bool	ray_in_angle(t_ray *ray, t_data *data, float alpha);
//file : texturing.c
void	draw_wall(t_data *data, t_ray *ray, int n_ray);

//-------------MOVEMENTS---------------//
//file : move_player.c
int		move_backward_forward(t_data *data, t_player *player, t_dir dir);
//file : shift_player.c
int		move_left_right(t_data *data, t_player *player, t_dir dir);
//file : wall_collision.c
bool	check_collide(t_data *data, float pos[2], float x, float y);
//file : rotate_player.c
int		rotate_player(t_data *data, t_player *player, t_dir dir);

//-------------INPUT---------------//
//file : key_functions.c
void	key_input(void *param);
int		movement_key(t_data *data);

#endif
