/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:44:53 by nortolan          #+#    #+#             */
/*   Updated: 2022/12/24 16:43:01 by nicolike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

//TODO: guardar coordenadas de las puertas?;
//TODO: puede haber saltos de linea tras el mapa?;
//TODO: espacios entre los elementos (en la propia linea rollo 540,   30, 23)?;
//TODO: puede haber lineas en el mapa rollo 111111111       1 (sin conectar con el mapa);
//TODO: check leaks;

static int	is_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if ((line[i] != '1' && line[i] != ' ' && line[i] != '\n')
			|| line[0] == '\n')
			return (0);
	}
	return (1);
}

static void	get_lines(t_map *vars, int fd)
{
	char	*line;
	int		in_map;
	int		i;

	in_map = 0;
	i = 0;
	vars->map = (char **)malloc(sizeof(char *) * (vars->map_len + 1));
	if (vars->map == NULL)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	line = get_next_line(fd);
	if (!line)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	while (line)
	{
		if (in_map == 0)
		{
			in_map = is_map(line);
			get_id(vars, line);
		}
		if (in_map == 2 && ft_strncmp(line, "\n", ft_strlen(line) != 0))
		{
			write (1, "Invalid map\n", 12);
			exit (1);
		}
		if (in_map == 1)
		{
			//vars->map[i++] = ft_strdup(line);
			if (line[0] == '\n')
			{
				in_map = 2;
				printf("teeeeest\n");
			}
			else
				vars->map[i++] = ft_substr(line, 0, ft_strlen(line) - 1);
			vars->map[i] = NULL; //probar si funciona debajo de esto;
		}
		free(line);
		line = get_next_line(fd);
	}
	printf("---------------\nNO=%s\nSO=%s\nWE=%s\nEA=%s\nD=%s\nF=%s\nC=%s\n", vars->no, vars->so, vars->we, vars->ea, vars->d, vars->f, vars->c);
	free(line);
}


int	line_cmp(t_map *vars, char *l, int i)
{
	if (ft_strncmp(l, "NO ", 3) != 0 && ft_strncmp(l, "SO ", 3) != 0
			&& ft_strncmp(l, "WE ", 3) != 0 && ft_strncmp(l, "EA ", 3) != 0
			&& ft_strncmp(l, "F ", 2) != 0 && ft_strncmp(l, "C ", 2) != 0
			&& ft_strncmp(l, "D ", 2) != 0 && vars->in_map == 0)
	{
		if (vars->in_map == 0 && l[0] != '\n')
		{
			/*while(l[i] == ' ') por la cara aqui no entra
			{
				printf("VALOR DE I: %d\n", i);
				l++;
				i++;
			}*/
			if (i == -1 && ++i == 0)
				vars->ns = 1;
			if (l[i] != '1')
			{
				write (1, "Invalid character in file\n", 26);
				exit (1);
			}
			else
			{
				vars->in_map = 1;
				vars->map_len++;
			}
		}
	}
	return (i);
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
			vars->map_len++;
		else
		{
			while (*line == ' ' && *line && (++i || i == 0))
				line++;
		}
		i = line_cmp(vars, line, i);
		if (vars->ns == 1)
			i -= 1;
		while (i-- >= 0)
			line--;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	printf("Map Length: %d\n", vars->map_len);
}

void	file_read(char *file)
{
	t_map	vars;
	int		fd;

	fd = open(file, O_RDONLY);
	vars = vars_init(&vars);
	if (fd < 0)
	{
		write (1, "Invalid file\n", 13);
		exit (1);
	}
	first_read(&vars, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	get_lines(&vars, fd);
	close(fd);
	///////////TEST///////////////
	int	i;

	i = -1;
	printf("---------TEST-----------\n");
	while (vars.map[++i])
	{
		printf("<'%s'\n", vars.map[i]);
	}
	printf("<%s", vars.map[i]);
	///////////TEST///////////////
	map_checker(&vars);
	freedom(&vars);
}
