#include <cub3d.h>

int	valid_chars(t_map *vars, int i, int j)
{
	int	player;

	player = 0;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] != '1' && vars->map[i][j] != '0' && vars->map[i][j] != ' ')
			{
				if (vars->map[i][j] == 'N' || vars->map[i][j] == 'S' || vars->map[i][j] == 'W' || vars->map[i][j] == 'E')
				{
					if (player == 0)
						player = 1;
					else
						return (2);
				}
				else
					return (1);
			}
		}
	}
	if (player)
		return (0);
	return (1);
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
			if (vars->map[i][j] != ' ' && vars->map[i][j] != '1' && vars->map[i][j]) //check diagonales;
			{
				if (vars->map[i - 1][j] == ' ' || vars->map[i + 1][j] == ' ' || (vars->map[i][j + 1] == ' ' || vars->map[i][j + 1] == '\0') || (vars->map[i][j - 1] == ' ' || vars->map[i][j - 1] == '\0')) //check que la linea no acabe? (\0);
					return (1);
			}
		}
	}
	return (0);
}

//00 01 02 03 04
//10 11 12 13 14
//20 21 22 23 24
//30 31 32 33 34
//40 41 42 43 44

/*int	void_in_map(t_map *vars, int i, int j)
{
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == '0')
				//?;
		}
	}
}*/

void	map_checker(t_map *vars)
{
	int	check;
//	int	j;

	check = valid_chars(vars, -1, -1);
//	j = -1;
	if (check == 1) //juntar todos los checks en este exit?;
	{
		write (1, "Invalid characters in map\n", 26);
		exit (1);
	}
	if (check == 2) //juntar todos los checks en este exit?;
	{
		write (1, "Multiple players in map\n", 24);
		exit (1);
	}
	if (open_walls(vars, 0, -1))
	{
		write (1, "Map must have walls all around\n", 31);
		exit (1);
	}
/*	if (void_in_map(vars, i, j))
	{
		write (1, "Invalid voids in map\n", 21);
		exit (1);
	}*/
}
