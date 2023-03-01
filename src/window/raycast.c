#include <cub3d.h>

//init ray-print walls- print sprites

static void init_sideDist(t_raycast *ray, t_player *p)
{
	if (ray->stepX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (p->posX - ray->mapX) * ray->deltaDisX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1 - p->posX) * ray->deltaDisX;
	}
	if (ray->stepY < 0)
	{
		ray->stepY = 1;
		ray->sideDistY = (p->posY - ray->mapY) * ray->deltaDisY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1 - p->posY) * ray->deltaDisY;
	}
}

void raycast(t_mlx *mlx)
{
	int x = -1;

	while (++x < WIN_W)
	{
		init_raycast(mlx->ray, &mlx->player, x);
		init_sideDist(mlx->ray, &mlx->player);
	}
}
