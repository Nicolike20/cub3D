#include <cub3d.h>

//init ray-print walls- print sprites

void raycast(t_mlx *mlx)
{
	int x = -1;

	while (++x < WIN_W)
	{
		init_raycast(mlx->ray, mlx->plane, x);
	}
}
