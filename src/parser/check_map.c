/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:47:49 by nortolan          #+#    #+#             */
/*   Updated: 2023/03/28 19:02:25 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	set_position(t_map *vars, int y, int x)
{
	vars->ori = vars->map[y][x];
	vars->pos_x = x;
	vars->pos_y = y;
	return (1);
}

static int	valid_chars_aux(t_map *vars, int i, int j, int player)
{
	if (vars->map[i][j] != '1' && vars->map[i][j] != '0'
	&& vars->map[i][j] != ' ' && vars->map[i][j] != 'D')
	{
		if (vars->map[i][j] == 'N' || vars->map[i][j] == 'S'
		|| vars->map[i][j] == 'W' || vars->map[i][j] == 'E')
		{
			if (player == 0)
				player = set_position(vars, i, j);
			else if (i == 0 || i == vars->height)
				return (3);
			else
				return (2);
		}
		else
		{
			write (1, "Invalid character in map\n", 25);
			exit (1);
		}
	}
	else if ((vars->map[i][j] == '0' || vars->map[i][j] == 'D')
			&& (i == 0 || i == vars->height - 1))
		return (3);
	return (player);
}

static int	valid_chars(t_map *vars, int i, int j)
{
	int	player;

	player = 0;
	while (++i < vars->height)
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
	}
	return (player);
}

static int	open_walls(t_map *vars, int i, int j)
{
	int	len;

	while (vars->map[++i])
	{
		j = -1;
		len = ft_strlen(vars->map[i]);
		while (++j <= len)
		{
			if (vars->map[i][j] != ' ' && vars->map[i][j]
				!= '1' && vars->map[i][j])
			{
				if (vars->map[i - 1][j] == ' '
				|| (vars->map[i][j + 1] == ' ' || vars->map[i][j + 1] == '\0')
				|| (vars->map[i][j - 1] == ' ' || vars->map[i][j - 1] == '\0')
				|| ((int)ft_strlen(vars->map[i + 1]) < j + 1
				|| (vars->map[i + 1] && vars->map[i + 1][j] == ' '))
				|| (vars->map[i][0] != '1' && vars->map[i][0] != ' '))
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
	if (check == 3 || open_walls(vars, 0, -1))
	{
		write (1, "Map must have walls all around\n", 31);
		exit (1);
	}
}
