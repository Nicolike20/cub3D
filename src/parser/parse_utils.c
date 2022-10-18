/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:07:23 by nortolan          #+#    #+#             */
/*   Updated: 2022/10/18 15:05:43 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_map	vars_init(t_map *vars)
{
	vars->NO = NULL;
	vars->SO = NULL;
	vars->WE = NULL;
	vars->EA = NULL;
	vars->C = NULL;
	vars->F = NULL;
	vars->map_len = 0;
	return (*vars);
}

void	get_id(t_map *vars, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		vars->NO = ft_strdup(ft_strtrim(ft_substr(line, 3,
						ft_strlen(line) - 4), " "));
	if (!ft_strncmp(line, "SO ", 3))
		vars->SO = ft_strdup(ft_strtrim(ft_substr(line, 3,
						ft_strlen(line) - 4), " "));
	if (!ft_strncmp(line, "WE ", 3))
		vars->WE = ft_strdup(ft_strtrim(ft_substr(line, 3,
						ft_strlen(line) - 4), " "));
	if (!ft_strncmp(line, "EA ", 3))
		vars->EA = ft_strdup(ft_strtrim(ft_substr(line, 3,
						ft_strlen(line) - 4), " "));
	if (!ft_strncmp(line, "F ", 2))
		vars->F = ft_strdup(ft_strtrim(ft_substr(line, 2,
						ft_strlen(line) - 3), " "));
	if (!ft_strncmp(line, "C ", 2))
		vars->C = ft_strdup(ft_strtrim(ft_substr(line, 2,
						ft_strlen(line) - 3), " "));
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
