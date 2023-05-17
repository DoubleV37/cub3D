/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:50:20 by vviovi            #+#    #+#             */
/*   Updated: 2023/05/17 15:33:04 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "type.h"
# include "../../libft/include/libft.h"

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

//map_get_info	-PARSING
int		get_texture_info(int file_fd, char *card, t_data *data, int index_tab);
int		get_color_info(int file_fd, char place, t_data *data);

//map_verif	-PARSING
int		valid_extension(char *path, char *extension);
int		valid_color(int red, int green, int blue);
int		valid_texture(char *path_texture);

//utils_map	-PARSING
char	*gnl_skip_void(int fd_file);
int		len_dbl_tab(char **tab);
int		print_error_map(int type_error);

//load_map	-PARSING
int		load_file(char **argv, t_data *data);

//init_setup	-RAYCASTING
void	init_player(t_player *player, t_data *data);

//draw_map		-DRAW
void	draw_map(t_data *data);

#endif
