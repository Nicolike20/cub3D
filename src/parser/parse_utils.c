/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:07:23 by nortolan          #+#    #+#             */
/*   Updated: 2023/04/28 19:04:47 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	vars_init(t_map *vars)
{
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
}

void	freedom(t_map *vars)
{
	free(vars->f);
	free(vars->c);
}

void	free_tmp(char **tmp, int i)
{
	while (--i >= 0)
		free(tmp[i]);
	free(tmp);
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
