#include <cub3d.h>

void init_raycast(t_raycast *ray, t_player *p, int x)
{
	ray->camX = (2 * x) / (float)WIN_W - 1;
	ray->rayDirX = p->dirX + p->planeX * ray->camX;
	ray->rayDirY = p->dirY + p->planeY * ray->camX;
	ray->mapX = (int)p->pos_x;
	ray->mapY = (int)p->pos_y;
	ray->coll = 0;
	ray->side = 0;
	if (ray->rayDirX == 0)
		ray->deltaDisX = 1e30;
	else
		ray->deltaDisX = fabs(1 / ray->rayDirX);
	if (ray->rayDirY == 0)
		ray->deltaDisY = 1e30;
	else
		ray->deltaDisY = fabs(1 / ray->rayDirY);
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
	mlx->frameRate = -1;
	init_keys(mlx);
	init_player(&mlx->player, mlx->map->pos_x, mlx->map->pos_y, mlx->map->ori);
	mlx->mlx = mlx_init();
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img,
			&mlx->img.bpp, &mlx->img.ln_len, &mlx->img.endian);
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, NAME);
	mlx->ray = (t_raycast *)malloc(sizeof(t_raycast));
	init_minimap(mlx);
}
