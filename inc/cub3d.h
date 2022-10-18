/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:57:57 by nortolan          #+#    #+#             */
/*   Updated: 2022/10/18 15:06:44 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_map
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*C;
	char	*F;
	char	**map;
	int		map_len;
}t_map;

void	paco(void);

/*parse_utils.c*/
t_map	vars_init(t_map *vars);
void	get_id(t_map *vars, char *line);
int		check_file(char *file);


#endif
