/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:44:53 by nortolan          #+#    #+#             */
/*   Updated: 2022/11/03 15:43:19 by nicolike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

//TODO: comprobar que cada cero esté rodeado de caracteres validos (aka no espacios);
//TODO: comprobar que solo haya un caracter de jugador en el mapa;
//TODO: hacer un primer barrido del mapa encontrando elementos invalidos;
//TODO: liberar elementos de vars;
//TODO: comrpobar elementos del mapa (por ejemplo que no haya mas de una letra);
//TODO: espacios en los elementos?;
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
		printf(">%s", line);
		if (in_map == 0)
		{
			in_map = is_map(line);
			get_id(vars, line);
		} //por aqui mas o menos hay que copiar el mapa en el doble array
		if (in_map == 1)
		{
			vars->map[i++] = ft_strdup(line);
			//printf("wooo mapa\n");
		}
		vars->map[i] = NULL;
		free(line);
		line = get_next_line(fd);
	}
	printf("---------------\nNO=%s\nSO=%s\nWE=%s\nEA=%s\nF=%s\nC=%s\n", vars->no, vars->so, vars->we, vars->ea, vars->f, vars->c);
	free(line);
}

static void	first_read(t_map *vars, int fd)
{
	int		in_map;
	int		i;
	char	*line;

	in_map = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = -1;
		if (in_map == 1)
			vars->map_len++;
		else
		{
			while (*line == ' ' && *line)
			{
//				printf("hola111?\n");
//				printf("linea: '%s'i = %d\n", line, i);
//				printf("'%c'\n", line[i]);
				i++;
				line++;
			}
		}
//			printf("adios111?\n");
//			printf("'%c'\n", *line);
		if (ft_strncmp(line, "NO ", 3) != 0 && ft_strncmp(line, "SO ", 3) != 0 && ft_strncmp(line, "WE ", 3) != 0 && ft_strncmp(line, "EA ", 3) != 0 && ft_strncmp(line, "F ", 2) != 0 && ft_strncmp(line, "C ", 2) != 0 && in_map == 0)
		{
			//printf("hola?\n\n");
			if (in_map == 0 && line[0] != '\n')
			{
				while(line[i] == ' ')
				{
//					printf("hola222?\n");
//					printf("linea: '%s'i = %d\n", line, i);
//					printf("'%c'\n", line[i]);
					line++;
					i++;
				}
//				printf("adios222?\n");
//				printf("'%c'\n", line[i]);
				if (line[i] != '1')
				{
					//printf("CHAR: %c", line[i]);
					write (1, "Invalid character in file\n", 26);
					exit (1);
				}
				else
				{
					in_map = 1;
					vars->map_len++;
				}
			}
		}
		while (i-- >= 0)
		{
//			printf("ulti linea: '%s'i = %d\n", line, i);
//			printf("ulti '%c'\n", line[i]);
			line--;
		}
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
	printf("--------------------------\n");
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
		printf("<%s", vars.map[i]);
	}
	printf("<%s", vars.map[i]);
	///////////TEST///////////////
	//continuar flow del programa (check_map)-> check caracteres y 0s rodeados);
	map_checker(&vars);
	freedom(&vars);
}
