/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:58:27 by nortolan          #+#    #+#             */
/*   Updated: 2023/03/09 20:05:04 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	is_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if ((line[i] != '1' && line[i] != ' ' && line[i] != '\n'
				&& line[i] != '0' && line[i] != 'D' && line[i] != 'N'
				&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E')
			|| line[0] == '\n')
			return (0);
	}
	return (1);
}

static int	in_map_checks(t_map *vars, char *line, int i)
{
	if (vars->in_map == 0)
	{
		vars->in_map = is_map(line);
		get_id(vars, line);
		if (vars->tmp)
			free(vars->tmp);
		if (vars->tmp_aux)
			free(vars->tmp_aux);
	}
	if (vars->in_map == 2 && ft_strncmp(line, "\n", ft_strlen(line) != 0))
	{
		write (1, "Invalid map\n", 12);
		exit (1);
	}
	if (vars->in_map == 1)
	{
		if (line[0] == '\n')
			vars->in_map = 2;
		else
			vars->map[i++] = ft_substr(line, 0, ft_strlen(line) - 1);
		vars->map[i] = NULL;
	}
	return (i);
}

void	get_lines(t_map *vars, int fd)
{
	char	*line;
	int		i;

	i = 0;
	vars->in_map = 0;
	vars->map = (char **)malloc(sizeof(char *) * (vars->height + 1));
	if (vars->map == NULL)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	line = get_next_line(fd);
	if (!line)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	while (line)
	{
		i = in_map_checks(vars, line, i);
		free(line);
		line = get_next_line(fd);
	}
	printf("---------------\nNO=%s\nSO=%s\nWE=%s\nEA=%s\nD=%s\nF=%s\nC=%s\n",
		vars->no, vars->so, vars->we, vars->ea, vars->d, vars->f, vars->c);
	free(line);
}
