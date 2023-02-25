/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:57:57 by nortolan          #+#    #+#             */
/*   Updated: 2023/02/25 10:45:34 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

# include <cub3d/macros.h>
# include <cub3d/structs.h>
# include <cub3d/functions.h>

/*parse.c*/
void	file_read(char *file, t_map *vars);

/*parse_utils.c*/
void	vars_init(t_map *vars);
void	freedom(t_map *vars);
void	get_id(t_map *vars, char *line);
int		check_file(char *file);

/*check_map.c*/
void	map_checker(t_map *vars);

#endif
