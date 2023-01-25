/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:47:49 by nortolan          #+#    #+#             */
/*   Updated: 2023/01/25 16:50:11 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	valid_chars_aux(t_map *vars, int i, int j, int player)
{
	if (vars->map[i][j] != '1' && vars->map[i][j] != '0'
	&& vars->map[i][j] != ' ' && vars->map[i][j] != 'D')
	{
		if (vars->map[i][j] == 'N' || vars->map[i][j] == 'S'
		|| vars->map[i][j] == 'W' || vars->map[i][j] == 'E')
		{
			if (player == 0)
				player = 1;
			else
				return (2);
		}
		else //quitar la D del if de arriba y crear aqui algo pa guardar coords?
			return (1);
	}
	return (player);
}

int	valid_chars(t_map *vars, int i, int j)
{
	int	player;

	player = 0;
	while (vars->map[++i])
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
		while (vars->map[i][++j])
			player = valid_chars_aux(vars, i, j, player);
	}
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
				if (vars->map[i - 1][j] == ' ' || vars->map[i + 1][j] == ' '
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

	check = valid_chars(vars, -1, -1);
	if (check == 0)
	{
		write (1, "Invalid characters in map\n", 26);
		exit (1);
	}
	if (check == 2)
	{
		write (1, "Multiple players in map\n", 24);
		exit (1);
	}
	if (open_walls(vars, 0, -1))
	{
		write (1, "Map must have walls all around\n", 31);
		exit (1);
	}
}
