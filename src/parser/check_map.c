/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:47:49 by nortolan          #+#    #+#             */
/*   Updated: 2023/03/01 15:41:12 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	valid_chars_aux(t_map *vars, int i, int j, int player)
{
//	printf("ayo???: %c\n", vars->map[i][j]);
	if (vars->map[i][j] != '1' && vars->map[i][j] != '0'
	&& vars->map[i][j] != ' ' && vars->map[i][j] != 'D')
	{
		if (vars->map[i][j] == 'N' || vars->map[i][j] == 'S'
		|| vars->map[i][j] == 'W' || vars->map[i][j] == 'E')
		{
			if (player == 0)
				player = 1;
			else if (i == 0 || i == vars->map_height)
			{
//				printf("return 3\n");
				return (3);
			}
			else
			{
//				printf("return 2\n");
				return (2);
			}
		}
		else //quitar la D del if de arriba y crear aqui algo pa guardar coords?
		{
//			printf("return 1\n");
			return (1);
		}
	}
	else if ((vars->map[i][j] == '0' || vars->map[i][j] == 'D')
			&& (i == 0 || i == vars->map_height))
	{
//		printf("return 3\n");
		return (3);
	}
//	printf("return player\n");
	return (player);
}

int	valid_chars(t_map *vars, int i, int j)
{
	int	player;

	player = 0;
	while (++i < vars->map_height)
	{
		j = -1;
		while (vars->map[i][++j] == ' ')
			;
		if (vars->map[i][j] == '\0')
		{
			write (1, "Invalid map\n", 12);
			exit (1);
		}
		j = -1;
		while (vars->map[i][++j] && player != 3)
			player = valid_chars_aux(vars, i, j, player);
//		printf("-----------------------------------\n");
	}
	printf("valid chars returns: %d\n", player);
	//if (player != 1)
	return (player);
	//return (1);
}

int	open_walls(t_map *vars, int i, int j)
{
	int	len;

	while (vars->map[++i])
	{
		j = -1;
		len = ft_strlen(vars->map[i]);
		while (++j <= len)
		{
			if (vars->map[i][j] != ' ' && vars->map[i][j]
				!= '1' && vars->map[i][j]) //check diagonales;
			{
				//printf("tamos en: %c\n", vars->map[i][j]);
				//printf("i - 1, j: %c\n", vars->map[i - 1][j]);
				//printf("i + 1, j: %c\n", vars->map[i + 1][j]);
				if (vars->map[i - 1][j] == ' '
				|| (vars->map[i][j + 1] == ' ' || vars->map[i][j + 1] == '\0')
				|| (vars->map[i][j - 1] == ' ' || vars->map[i][j - 1] == '\0'))
					return (1);
			}
		}
	}
	return (0);
}

void	map_checker(t_map *vars)
{
	int	check;

//	printf("HOLA 00000\n");
	check = valid_chars(vars, -1, -1);
//	printf("HOLA 11111\n");
	if (check == 0)
	{
		write (1, "Invalid characters in map\n", 26);
		exit (1);
	}
//	printf("HOLA 22222\n");
	if (check == 2)
	{
		write (1, "Multiple players in map\n", 24);
		exit (1);
	}
//	printf("HOLA 33333\n");
	if (check == 3 || open_walls(vars, 0, -1))
	{
		write (1, "Map must have walls all around\n", 31);
		exit (1);
	}
//	printf("HOLA 44444\n");
	//TESTEAR TODO LO QUE SE TE OCURRA
}
