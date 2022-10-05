/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:58:25 by nortolan          #+#    #+#             */
/*   Updated: 2022/10/05 18:51:06 by nortolan         ###   ########.fr       */
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
	return (*vars);
}

void	get_lines(t_map *vars, int fd)
{
	char	*line;

	*vars = vars_init(vars);
	line = get_next_line(fd);
	if (!line)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	while (line)
	{
		printf(">%s", line); //trabajar con cada linea aqui
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	file_read(char *file)
{
	t_map	vars;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write (1, "Invalid file\n", 13);
		exit (1);
	}
	get_lines(&vars, fd);
	close(fd);
}

int	check_file(char *file)
{
	int		i;
	char	*ext;

	i = ft_strlen(file);
//	printf("file name: %s, len: %d\n", file, i);
	ext = ft_substr(file, i - 4, 4);
//	printf("extension: %s, test: %d\n", ext, i - 4);
	if (ft_strncmp(ext, ".cub", 4))
	{
		write (1, "Invalid file extension\n", 23);
		return (1);
	}
	free(ext);
	return (0);

}

/*void	leaks(void)
{
	system("leaks -q cub3D");
}*/

int main(int argc, char **argv)
{
//	atexit(leaks);
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
