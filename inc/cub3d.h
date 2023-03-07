/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:57:57 by nortolan          #+#    #+#             */
/*   Updated: 2023/03/07 18:56:26 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
//# include <mlx.h>

typedef struct s_tex
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	void	*door;
}t_tex;

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*d;
	char	*c;
	char	*f;
	char	*tmp;
	char	*tmp_aux;
	char	**map;
	int		height;
	int		width;
	int		in_map;
	char	ori;
	float	x;
	float	y;
	int		ns;
}t_map;

/*parse.c*/
void	file_read(char *file, t_map *vars);

/*get_lines.c*/
void	get_lines(t_map *vars, int fd);

/*parse_utils.c*/
t_map	vars_init(t_map *vars);
void	freedom(t_map *vars);
void	get_id(t_map *vars, char *line);
int		check_file(char *file);

/*check_map.c*/
void	map_checker(t_map *vars);

#endif
