#include <cub3d.h>

//init ray-print walls- print sprites

static void init_sideDist(t_raycast *ray, t_player *p)
{
	if (ray->stepX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (p->pos_x - ray->mapX) * ray->deltaDisX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1 - p->pos_x) * ray->deltaDisX;
	}
	if (ray->stepY < 0)
	{
		ray->stepY = 1;
		ray->sideDistY = (p->pos_y - ray->mapY) * ray->deltaDisY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1 - p->pos_y) * ray->deltaDisY;
	}
}

/*static void player_collision(t_map *map, t_raycast *ray)
{
	while (ray->coll == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDisX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDisY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (map->map[ray->mapY][ray->mapX] == '1')
			ray->coll = 1;
	}
}*/

static void calculate_line(t_raycast *ray)
{
	if (ray->side == 0)
		ray->perpWallDist = ray->sideDistX - ray->deltaDisX;
	else
		ray->perpWallDist = ray->sideDistY - ray->deltaDisY;
	ray->ln_height = (int)(WIN_H / ray->perpWallDist);
	ray->d_start = -ray->ln_height / 2 + WIN_H / 2;
	if (ray->d_start < 0)
		ray->d_start = 0;
	ray->d_end = ray->ln_height / 2 + WIN_H / 2;
	if (ray->d_end >= WIN_H)
		ray->d_end = WIN_H - 1;
}

static void	draw_line(t_mlx *mlx, t_raycast *ray, int x)
{
	int y;

	y = -1;
	while (++y < WIN_H)
	{
		if (y < ray->d_start)
			mlx_put_pixel_color(mlx->img, WIN_W - x - 1, y, FUCHSIA);
		if (y >= ray->d_start && y <= ray->d_end)
			mlx_put_pixel_color(mlx->img, WIN_W - x - 1, y, RED);
		if (y > ray->d_end)
			mlx_put_pixel_color(mlx->img, WIN_W - x - 1, y, BLUE);
	}
}

void raycast(t_mlx *mlx)
{
	int x = -1;
	t_raycast *aux;

	aux = mlx->ray;
	while (++x < WIN_W)
	{
		init_raycast(aux, &mlx->player, x);
		init_sideDist(aux, &mlx->player);
		//player_collision(mlx->map, aux);
		calculate_line(aux);
		draw_line(mlx, aux, x);
		aux->bufferZ[x] = aux->perpWallDist;
	}
}
