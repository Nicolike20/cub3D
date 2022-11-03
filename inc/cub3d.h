/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:57:57 by nortolan          #+#    #+#             */
/*   Updated: 2022/11/03 16:06:55 by nicolike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
//# include <mlx.h>

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*c;
	char	*f;
	char	*tmp;
	char	*tmp_aux;
	char	**map;
	int		map_len;
}t_map;

/*parse.c*/
void	file_read(char *file);

/*parse_utils.c*/
t_map	vars_init(t_map *vars);
void	freedom(t_map *vars);
void	get_id(t_map *vars, char *line);
int		check_file(char *file);

/*check_map.c*/
void	map_checker(t_map *vars);

#endif
