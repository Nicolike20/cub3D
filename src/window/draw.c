#include <cub3d.h>

void draw(t_mlx *mlx)
{
	//TODO:raycast -> crosshire -> minimap? -> help panel
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, &mlx->img.ln_len, &mlx->img.endian);
	ft_bzero(mlx->img.addr, WIN_W * WIN_H * (mlx->img.bpp / 8));
	//raycast
//	minimap(mlx);
	crosshire(mlx->img);
	//minimap
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}
