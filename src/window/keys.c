#include <cub3d.h>

static void exit_win_key(t_mlx *mlx)
{
	(void)mlx;
	//mlx_destroy_image(mlx->mlx, mlx->img.img);
	//free(mlx);
	exit(EXIT_SUCCESS);
}

int key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_A)
		mlx->keys.a = FALSE;
	else if (keycode == KEY_S)
		mlx->keys.s = FALSE;
	else if (keycode == KEY_D)
		mlx->keys.d = FALSE;
	else if (keycode == KEY_W)
		mlx->keys.w = FALSE;
	return (0);
}

int key_relase(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_A)
		mlx->keys.a = TRUE;
	else if (keycode == KEY_S)
		mlx->keys.s = TRUE;
	else if (keycode == KEY_D)
		mlx->keys.d = TRUE;
	else if (keycode == KEY_W)
		mlx->keys.w = TRUE;
	return (0);
}

int manage_keys(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		exit_win_key(mlx);
	return (0);
}

void init_keys(t_mlx *mlx)
{
	mlx->keys.a = FALSE;
	mlx->keys.s = FALSE;
	mlx->keys.d = FALSE;
	mlx->keys.w = FALSE;
}
