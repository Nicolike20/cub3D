/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:35:23 by Vsavilov          #+#    #+#             */
/*   Updated: 2023/03/21 20:23:04 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structs.h"

void loading_textures(t_mlx *mlx, t_map *map);

//manage_window.c
int		init_window(t_mlx *mlx);

//keys.c
void	init_keys(t_mlx *mlx);
int		key_press(int keycode, t_mlx *mlx);
int		key_relase(int keycode, t_mlx *mlx);

//keys_move.c
void	manage_move_keys(t_mlx *mlx);

//game_loop.c
int		game_loop(void *mlx);

//draw.c
void	draw(t_mlx *mlx);

//raycast.c
void	raycast(t_mlx *mlx);
int	pixel_color(t_img img, int x, int y);

//player.c
void	init_player(t_player *p, float posX, float posY, char c);

//minimap.c
void	mmap_background(t_minimap mmap);
void	mmap_mlx_image(t_minimap *map, void *ptr);
void	draw_minimap(t_mlx *mlx);

//crosshire.c
void	crosshire(t_img img);

//mlx_functions.c
void	mlx_put_pixel_color(t_img img, int x, int y, int color);

//mlx_memory.c
void	free_mlx(t_mlx *mlx);

//utils.c
int		arg_error(void);

//init.c
void	init_crosshire(t_crosshire *chre, char c);
void	init_minimap(t_mlx *mlx);
void	init_mlx(t_mlx *mlx);
void	init_raycast(t_raycast *ray, t_player *p, int x);

/*parse.c*/
void	file_read(char *file, t_map *vars);

/*get_lines.c*/
void	get_lines(t_map *vars, int fd);

/*parse_utils.c*/
void	vars_init(t_map *vars);
void	freedom(t_map *vars);
void	get_id(t_map *vars, char *line);
int		check_file(char *file);

/*check_map.c*/
void	map_checker(t_map *vars);

/*check_colors.c*/
void	check_colors(char *color);

#endif
