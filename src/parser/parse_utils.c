/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:07:23 by nortolan          #+#    #+#             */
/*   Updated: 2023/03/23 15:43:39 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	vars_init(t_map *vars)
{
//	vars = (t_map *)malloc(sizeof(t_map));
	vars->no = NULL;
	vars->so = NULL;
	vars->we = NULL;
	vars->ea = NULL;
	vars->d = NULL;
	vars->c = NULL;
	vars->f = NULL;
	vars->c_hex = 0x000000;
	vars->f_hex = 0x000000;
	vars->map = NULL;
	vars->height = 0;
	vars->width = 0;
	vars->in_map = 0;
	vars->pos_x = 0.0;
	vars->pos_y = 0.0;
	vars->ns = 0;
	vars->ori = 0;
//	return (*vars);
}

void	freedom(t_map *vars)
{
//	int	i;
//
//	i = -1;
//	while (++i < vars->map_height)
//		free(vars->map[i]);
//	free(vars->map);
	free(vars->no);
	free(vars->so);
	free(vars->we);
	free(vars->ea);
	free(vars->d);
	free(vars->f);
	free(vars->c);
	//liberar c_hex y f_hex?;
}

int	check_file(char *file)
{
	int		i;
	char	*ext;

	i = ft_strlen(file);
	ext = ft_substr(file, i - 4, 4);
	if (ft_strncmp(ext, ".cub", 4))
	{
		write (1, "Invalid file extension\n", 23);
		return (1);
	}
	free(ext);
	return (0);
}
