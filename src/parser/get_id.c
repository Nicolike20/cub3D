/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:58:00 by nortolan          #+#    #+#             */
/*   Updated: 2023/03/13 17:58:36 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	get_id_error(void)
{
	write (1, "Multiple textures for the same ID\n", 34);
	exit (1);
}

void	get_id_aux_two(t_map *vars, char *line)
{
	if (!ft_strncmp(line, "WE ", 3))
	{
		vars->tmp_aux = ft_substr(line, 3, ft_strlen(line) - 4);
		vars->tmp = ft_strtrim(vars->tmp_aux, " ");
		if (vars->we != NULL)
			get_id_error();
		vars->we = ft_strdup(vars->tmp);
	}
	if (!ft_strncmp(line, "EA ", 3))
	{
		vars->tmp_aux = ft_substr(line, 3, ft_strlen(line) - 4);
		vars->tmp = ft_strtrim(vars->tmp_aux, " ");
		if (vars->ea != NULL)
			get_id_error();
		vars->ea = ft_strdup(vars->tmp);
	}
}

void	get_id_aux(t_map *vars, char *line)
{
	if (!ft_strncmp(line, "D ", 2))
	{
		printf ("ILLOOO??: %s\n", line);
		vars->tmp_aux = ft_substr(line, 2, ft_strlen(line) - 3);
		vars->tmp = ft_strtrim(vars->tmp_aux, " ");
		if (vars->d != NULL)
			get_id_error();
		vars->d = ft_strdup(vars->tmp);
		printf("OLLIIIII???: %s\n", vars->d);
	}
	if (!ft_strncmp(line, "NO ", 3))
	{
		vars->tmp_aux = ft_substr(line, 3, ft_strlen(line) - 4);
		vars->tmp = ft_strtrim(vars->tmp_aux, " ");
		if (vars->no != NULL)
			get_id_error();
		vars->no = ft_strdup(vars->tmp);
	}
	if (!ft_strncmp(line, "SO ", 3))
	{
		vars->tmp_aux = ft_substr(line, 3, ft_strlen(line) - 4);
		vars->tmp = ft_strtrim(vars->tmp_aux, " ");
		if (vars->so != NULL)
			get_id_error();
		vars->so = ft_strdup(vars->tmp);
	}
	get_id_aux_two(vars, line);
}

void	get_id(t_map *vars, char *line)
{
	vars->tmp = NULL;
	vars->tmp_aux = NULL;
	while (*line == ' ')
		line++;
	get_id_aux(vars, line);
	if (!ft_strncmp(line, "F ", 2))
	{
		vars->tmp_aux = ft_substr(line, 2, ft_strlen(line) - 3);
		vars->tmp = ft_strtrim(vars->tmp_aux, " ");
		if (vars->f != NULL)
			get_id_error();
		vars->f = ft_strdup(vars->tmp);
	}
	if (!ft_strncmp(line, "C ", 2))
	{
		vars->tmp_aux = ft_substr(line, 2, ft_strlen(line) - 3);
		vars->tmp = ft_strtrim(vars->tmp_aux, " ");
		if (vars->c != NULL)
			get_id_error();
		vars->c = ft_strdup(vars->tmp);
	}
	printf("tetetetetetete: %s\n", vars->d);
}
