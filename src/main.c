/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:58:25 by nortolan          #+#    #+#             */
/*   Updated: 2022/10/19 12:42:20 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

//TODO: LEAAAAAAAAAAAAAAAAAAAAKS;
//TODO: cambiar variables mayusculas por minusculas;

//TODO: hacer un primer barrido del mapa encontrando elementos invalidos;
//TODO: liberar elementos de vars;
//TODO: comrpobar elementos del mapa (por ejemplo que no haya mas de una letra);
//TODO: espacios en los elementos?;

int	is_map(char *line)
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

void	get_lines(t_map *vars, int fd)
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

void	first_read(t_map *vars, int fd)
{
	int		in_map;
	int		i;
	char	*line;

	in_map = 0;
	i = -1;
	line = get_next_line(fd);
	while (line)
	{
		if (in_map == 1)
			vars->map_len++;
		if (ft_strncmp(line, "NO ", 3) != 0 && ft_strncmp(line, "SO ", 3) != 0 && ft_strncmp(line, "WE ", 3) != 0 && ft_strncmp(line, "EA ", 3) != 0 && ft_strncmp(line, "F ", 2) != 0 && ft_strncmp(line, "C ", 2) != 0 && in_map == 0)
		{
			//printf("hola?\n\n");
			if (in_map == 0 && line[0] != '\n')
			{
				while(line[++i] == ' ')
					;
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
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	printf("Map Length: %d\n", vars->map_len);
}

void	freedom(t_map *vars)
{
	int	i;

	i = -1;
	while (++i < vars->map_len)
		free(vars->map[i]);
	free(vars->map);
	free(vars->no);
	free(vars->so);
	free(vars->we);
	free(vars->ea);
	free(vars->f);
	free(vars->c);
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
	freedom(&vars);
	//free vars;
	/*if (vars.NO)
		free(vars.NO);
	free(vars.SO);
	free(vars.WE);
	free(vars.EA);
	free(vars.F);
	free(vars.C);*/
}

void	leaks(void)
{
	system("leaks -q cub3D");
}

int	main(int argc, char **argv)
{
	atexit(leaks);
	if (argc != 2)
	{
		write (1, "Wrong number of arguments. Only one map expected\n", 49);
		return (1);
	}
	if (check_file(argv[1]))
		return (1);
	file_read(argv[1]);
//	paco();
	return (0);
}
