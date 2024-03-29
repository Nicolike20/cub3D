/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:35:23 by Vsavilov          #+#    #+#             */
/*   Updated: 2023/04/28 20:07:13 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structs.h"

//manage_window.c
int		init_window(t_mlx *mlx);

//door.c
void	input_door(t_mlx *mlx);
void	io_door(char **map, t_raycast *ray, int x);

//keys.c
void	init_keys(t_mlx *mlx);
int		key_press(int keycode, t_mlx *mlx);
int		key_relase(int keycode, t_mlx *mlx);

//keys_move.c
void	manage_move_keys(t_mlx *mlx);
void	fpp_camera(int key, t_mlx *mlx, float speed);

//mouse.c
void	input_mouse(t_mlx *mlx);
int		handle_mouse(int x, int y, t_mlx *mlx);

//game_loop.c
int		game_loop(void *mlx);

//draw.c
void	draw(t_mlx *mlx);

//raycast_utils.c
void	init_side_dist(t_raycast *ray, t_player *p);
void	player_collision(t_map *map, t_raycast *ray, int x);
void	calculate_line(t_raycast *ray);

//raycast.c
void	raycast(t_mlx *mlx);
int		pixel_color(t_img img, int x, int y);

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

//utils.c
int		arg_error(void);
int		put_error(char *s, int e);

//init.c
void	init_crosshire(t_crosshire *chre, char c);
void	init_minimap(t_mlx *mlx);
void	init_mlx(t_mlx *mlx);
void	init_raycast(t_raycast *ray, t_player *p, int x);

/*parse.c*/
void	file_read(char *file, t_map *vars);
//void	loading_textures(t_mlx *mlx, t_map *map);

/*get_lines.c*/
void	get_lines(t_map *vars, int fd);

/*parse_utils.c*/
void	vars_init(t_map *vars);
void	freedom(t_map *vars);
void	free_tmp(char **tmp, int i);
void	get_id(t_map *vars, char *line);
int		check_file(char *file);

/*check_map.c*/
void	map_checker(t_map *vars);

/*textures.c*/
void	loading_textures(t_mlx *mlx);

/*colors.c*/
void	check_colors(t_map *vars, char *color, int check, int i);

#endif
