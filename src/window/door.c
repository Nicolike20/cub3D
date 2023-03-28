#include <cub3d.h>

void	io_door(char **map, t_raycast *ray, int x)
{
	if (map[ray->map_y][ray->map_x] == DOOR
		|| map[ray->map_y][ray->map_x] == DOPEN)
	{
		ray->io_door = 1;
		if (x == WIN_W / 2)
		{
			ray->door[X] = ray->map_x;
			ray->door[Y] = ray->map_y;
		}
	}
}

void	input_door(t_mlx *mlx)
{
	t_player	*p;
	char	**m;
	int	door_x;
	int	door_y;

	p = &mlx->player;
	door_x = mlx->ray->door[X];
	door_y = mlx->ray->door[Y];
	m = mlx->map->map;
	if (mlx->ray->door[X] == -1 || mlx->ray->door[Y] == -1)
		return ;
	if (m[door_y][door_x] == DOOR && ((int)p->pos_x != door_x
			|| (int)p->pos_y != door_y))
		m[door_y][door_x] = DOPEN;
	else if (m[door_y][door_x] == DOPEN && ((int)p->pos_x != door_x
			|| (int)p->pos_y != door_y))
		m[door_y][door_x] = DOOR;
	printf("No return\n");
}
