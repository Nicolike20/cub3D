#include <cub3d.h>

void draw(t_mlx *mlx)
{
	mlx->ray->door[X] = -1;
	mlx->ray->door[Y] = -1;
	ft_bzero(mlx->img.addr, WIN_W * WIN_H * (mlx->img.bpp / 8));
	raycast(mlx);
	//printf("posX = %f -- posY= %f\n", mlx->player.pos_x, mlx->player.pos_y);
	crosshire(mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	draw_minimap(mlx);
	printf("%d\n", mlx->ray->door[X]);
	printf("%d\n", mlx->ray->door[Y]);
}
