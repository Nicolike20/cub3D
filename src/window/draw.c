#include <cub3d.h>

void draw(t_mlx *mlx)
{
	//TODO:raycast -> crosshire -> minimap? -> help panel
	ft_bzero(mlx->img.addr, WIN_W * WIN_H * (mlx->img.bpp / 8));
	raycast(mlx);
	//pj step pos x-y;
	//printf("posX = %f -- posY= %f\n", mlx->player.pos_x, mlx->player.pos_y);
	crosshire(mlx->img);
	//minimap
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	draw_minimap(mlx);
}
