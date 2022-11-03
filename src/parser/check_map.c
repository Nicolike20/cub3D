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
			if (vars->map[i][j] != '1' && vars->map[i][j] != '0' && vars->map[i][j] != ' ' && vars->map[i][j] != '\n')
			{
				if (vars->map[i][j] == 'N' || vars->map[i][j] == 'S' || vars->map[i][j] == 'W' || vars->map[i][j] == 'E')
				{
					if (player == 0)
						player = 1;
					else
						return (1);
				}
				else
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

int	void_in_map(t_map *vars, int i, int j)
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
}

void	map_checker(t_map *vars)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (valid_chars(vars, i, j))
	{
		write (1, "Invalid characters in map\n", 26);
		exit (1);
	}
	if (void_in_map(vars, i, j))
	{
		write (1, "Invalid voids in map\n", 21);
		exit (1);
	}
}
