#include <cub3d.h>

void init_raycast(t_raycast *ray, t_plane *p, int x)
{
	ray = (t_raycast *)malloc(sizeof(t_raycast));
	ray->camX = (2 * x) / (float)WIN_W - 1;
	ray->rayDirX = p->dirX + p->planeX * ray->camX;
	ray->rayDirY =p->dirY + p->planeY * ray->camX;
	ray->mapX = (int)p->posX;
	ray->mapY = (int)p->posY;
	if (ray->rayDirX == 0)
		ray->deltaDisX = 1e30;
	else
		ray->deltaDisX = fabs(1 / ray->rayDirX);
	if (ray->rayDirY == 0)
		ray->deltaDisY = 1e30;
	else
		ray->deltaDisY = fabs(1 / ray->rayDirY);
}

void init_minimap(t_mlx *mlx)
{
	mlx->mmap.xy_large = fmax(WIN_W, WIN_H) / MINIMAP_SCALE;
	mmap_mlx_image(mlx);
//	mmap_background(mlx->mmap);
}

void init_crosshire(t_crosshire *chre, char c)
{
	if (c == 'W')
	{
		chre->x = WIN_W / 2 - CROSSHIRE_LEN;
		chre->y = WIN_H / 2;
	}
	else if (c == 'N')
	{
		chre->x = WIN_W / 2;
		chre->y = WIN_H / 2 - CROSSHIRE_LEN;
	}
	else
	{
		chre->x = WIN_W / 2;
		chre->y = WIN_H / 2;
	}
	chre->color = CYAN;
}

void init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, NAME);
}
