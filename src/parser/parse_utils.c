/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:07:23 by nortolan          #+#    #+#             */
/*   Updated: 2023/03/05 19:20:52 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_map	vars_init(t_map *vars)
{
	vars = (t_map *)malloc(sizeof(t_map));
	vars->no = NULL;
	vars->so = NULL;
	vars->we = NULL;
	vars->ea = NULL;
	vars->d = NULL;
	vars->c = NULL;
	vars->f = NULL;
	vars->height = 0;
	vars->width = 0;
	vars->in_map = 0;
	vars->posX = 0.0;
	vars->posY = 0.0;
	vars->ns = 0;
	return *vars;
}

void	freedom(t_map *vars)
{
//	int	i;

//	i = -1;
//	while (++i < vars->height)
//		free(vars->map[i]);
//	free(vars->map);
	free(vars->no);
	free(vars->so);
	free(vars->we);
	free(vars->ea);
	free(vars->d);
	free(vars->f);
	free(vars->c);
}

void	get_id_aux(t_map *vars, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
	{
		vars->tmp_aux = ft_substr(line, 3, ft_strlen(line) - 4);
		vars->tmp = ft_strtrim(vars->tmp_aux, " ");
		vars->no = ft_strdup(vars->tmp);
	}
	if (!ft_strncmp(line, "SO ", 3))
	{
		vars->tmp_aux = ft_substr(line, 3, ft_strlen(line) - 4);
		vars->tmp = ft_strtrim(vars->tmp_aux, " ");
		vars->so = ft_strdup(vars->tmp);
	}
	if (!ft_strncmp(line, "WE ", 3))
	{
		vars->tmp_aux = ft_substr(line, 3, ft_strlen(line) - 4);
		vars->tmp = ft_strtrim(vars->tmp_aux, " ");
		vars->we = ft_strdup(vars->tmp);
	}
	if (!ft_strncmp(line, "EA ", 3))
	{
		vars->tmp_aux = ft_substr(line, 3, ft_strlen(line) - 4);
		vars->tmp = ft_strtrim(vars->tmp_aux, " ");
		vars->ea = ft_strdup(vars->tmp);
	}
}

void	get_id(t_map *vars, char *line)
{
	vars->tmp = NULL;
	vars->tmp_aux = NULL;
	while (*line == ' ')
		line++;
	get_id_aux(vars, line);
	if (!ft_strncmp(line, "D ", 2))
	{
		vars->tmp_aux = ft_substr(line, 2, ft_strlen(line) - 3);
		vars->tmp = ft_strtrim(vars->tmp_aux, " ");
		vars->d = ft_strdup(vars->tmp);
	}
	if (!ft_strncmp(line, "F ", 2))
	{
		vars->tmp_aux = ft_substr(line, 2, ft_strlen(line) - 3);
		vars->tmp = ft_strtrim(vars->tmp_aux, " ");
		vars->f = ft_strdup(vars->tmp);
	}
	if (!ft_strncmp(line, "C ", 2))
	{
		vars->tmp_aux = ft_substr(line, 2, ft_strlen(line) - 3);
		vars->tmp = ft_strtrim(vars->tmp_aux, " ");
		vars->c = ft_strdup(vars->tmp);
	}
	if (vars->tmp)
		free(vars->tmp);
	if (vars->tmp_aux)
		free(vars->tmp_aux);
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
