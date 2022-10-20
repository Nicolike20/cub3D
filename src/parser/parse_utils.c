/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:07:23 by nortolan          #+#    #+#             */
/*   Updated: 2022/10/19 14:12:47 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_map	vars_init(t_map *vars)
{
	vars->no = NULL;
	vars->so = NULL;
	vars->we = NULL;
	vars->ea = NULL;
	vars->c = NULL;
	vars->f = NULL;
	vars->map_len = 0;
	return (*vars);
}

//codigo muy feo, intentar mejorarlo;
void	get_id(t_map *vars, char *line)
{
	char	*tmp;
	char	*tmp_aux;

	tmp = NULL;
	tmp_aux = NULL;
	if (!ft_strncmp(line, "NO ", 3))
	{
		tmp_aux = ft_substr(line, 3, ft_strlen(line) - 4);
		tmp = ft_strtrim(tmp_aux, " ");
		vars->no = ft_strdup(tmp);
	}
	if (!ft_strncmp(line, "SO ", 3))
	{
		tmp_aux = ft_substr(line, 3, ft_strlen(line) - 4);
		tmp = ft_strtrim(tmp_aux, " ");
		vars->so = ft_strdup(tmp);
	}
	if (!ft_strncmp(line, "WE ", 3))
	{
		tmp_aux = ft_substr(line, 3, ft_strlen(line) - 4);
		tmp = ft_strtrim(tmp_aux, " ");
		vars->we = ft_strdup(tmp);
	}
	if (!ft_strncmp(line, "EA ", 3))
	{
		tmp_aux = ft_substr(line, 3, ft_strlen(line) - 4);
		tmp = ft_strtrim(tmp_aux, " ");
		vars->ea = ft_strdup(tmp);
	}
	if (!ft_strncmp(line, "F ", 2))
	{
		tmp_aux = ft_substr(line, 2, ft_strlen(line) - 3);
		tmp = ft_strtrim(tmp_aux, " ");
		vars->f = ft_strdup(tmp);
	}
	if (!ft_strncmp(line, "C ", 2))
	{
		tmp_aux = ft_substr(line, 2, ft_strlen(line) - 3);
		tmp = ft_strtrim(tmp_aux, " ");
		vars->c = ft_strdup(tmp);
	}
	if (tmp)
		free(tmp);
	if (tmp_aux)
		free(tmp_aux);
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
