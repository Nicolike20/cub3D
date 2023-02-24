#include <cub3d.h>

int init_window(t_mlx *mlx) {
	mlx->mlx = mlx_init();
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "cub3D");

	mlx_key_hook(mlx->win, manage_keys, mlx);
	mlx_loop_hook(mlx->mlx, game_loop, mlx);
	mlx_loop(mlx->mlx);
	free_mlx(mlx);
	return 0;
}
