#include <cub3d.h>

void	input_door(t_mlx *mlx)
{
	t_player	*p;
	char	**m;
	int	door_x;
	int	door_y;

	p = &mlx->player;
	door_x = mlx->mmap->door[0];
	door_y = mlx->mmap->door[1];
	m = mlx->map->map;
	if (mlx->mmap->door[0] == -1 || mlx->mmap->door[1] == -1)
		return ;
	if (m[door_y][door_x] == DCLOSE && ((int)p->pos_x != door_x
			|| (int)p->pos_y != door_y))
		m[door_y][door_x] = DOPEN;
	else if (m[door_y][door_x] == DOPEN && ((int)p->pos_x != door_x
			|| (int)p->pos_y != door_y))
		m[door_y][door_x] = DCLOSE;
}
