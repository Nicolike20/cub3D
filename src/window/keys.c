#include <cub3d.h>

static void exit_win_key(t_mlx *mlx)
{
	(void)mlx;
	//mlx_destroy_image(mlx->mlx, mlx->img.img);
	//free(mlx);
	exit(EXIT_SUCCESS);
}

int manage_keys(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		exit_win_key(mlx);
	return (0);
}
