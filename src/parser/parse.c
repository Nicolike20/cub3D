/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:44:53 by nortolan          #+#    #+#             */
/*   Updated: 2023/03/10 15:00:42 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

//TODO: espacios entre los elementos (en la propia linea rollo 540,   30, 23)?;
//TODO: klk si pongo dos veces una ruta a una textura (p.e. dos veces SO ./asdf;
//TODO: check leaks;

void	line_cmp_aux(t_map *vars, char *l, int *i)
{
	vars->in_map = 1;
	while (l[++*i] != '\n')
	{
		if (l[*i] == 'D' || l[*i] == '0' || l[*i] == 'N' || l[*i] == 'S'
			|| l[*i] == 'E' || l[*i] == 'W')
		{
			write (1, "Map must have walls all around\n", 31);
			exit (1);
		}
		else if (l[*i] != '1' && l[*i] != ' ')
		{
			write (1, "Invalid character in file\n", 26);
			exit (1);
		}
	}
}

int	line_cmp(t_map *vars, char *l, int i)
{
	int	aux;

	aux = i;
	if (ft_strncmp(l, "NO ", 3) != 0 && ft_strncmp(l, "SO ", 3) != 0
		&& ft_strncmp(l, "WE ", 3) != 0 && ft_strncmp(l, "EA ", 3) != 0
		&& ft_strncmp(l, "F ", 2) != 0 && ft_strncmp(l, "C ", 2) != 0
		&& ft_strncmp(l, "D ", 2) != 0 && vars->in_map == 0)
	{
		if (vars->in_map == 0 && l[0] != '\n')
		{
			if (i != -1)
				i = -1;
			if (l[++i] != '1' && l[i] != 'D' && l[i] != '0' && l[i] != 'N'
				&& l[i] != 'S' && l[i] != 'E' && l[i] != 'W' & l[i] != ' ')
			{
				write (1, "Invalid character in file\n", 26);
				exit (1);
			}
			else if (++vars->height)
			{
				line_cmp_aux(vars, l, &i);
			}
		}
	}
	return (aux);
}

static void	first_read(t_map *vars, int fd)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		i = -1;
		if (vars->in_map == 1 && ft_strncmp("\n", line, ft_strlen(line) != 0))
			vars->height++;
		else
		{
			while (*line == ' ' && *line && (++i || i == 0))
				line++;
		}
		i = line_cmp(vars, line, i);
		while (i-- >= 0)
			line--;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	get_width(t_map *vars)
{
	int	i;

	i = -1;
	while (vars->map[++i])
	{
		if ((int)ft_strlen(vars->map[i]) > vars->width)
			vars->width = ft_strlen(vars->map[i]);
	}
}

void	file_read(char *file, t_map *vars)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write (1, "Invalid file\n", 13);
		exit (1);
	}
	first_read(vars, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	get_lines(vars, fd);
	close(fd);
	get_width(vars);
	///////////TEST///////////////
	int	i;

	i = -1;
	printf("---------TEST-----------\n");
	while (vars->map[++i])
	{
		printf("<'%s'\n", vars->map[i]);
	}
	printf("<%s\n", vars->map[i]);
	printf("Map height: %d\n", vars->height);
	printf("Map width: %d\n", vars->width);
	///////////TEST///////////////
	map_checker(vars);
	printf("pos x: %f\npos y: %f\n", vars->pos_x, vars->pos_y); ////TEST;
	freedom(vars);
}
