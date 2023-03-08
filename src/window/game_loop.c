#include <cub3d.h>

int game_loop(void *mlx)
{
	t_mlx *tmp;

	tmp = (t_mlx *)mlx;
	if (++tmp->frameRate >= MAX_FPS) {
		tmp->frameRate = 0;
		printf("%d\n", tmp->frameRate);
	}
	draw(tmp);
	printf("%d\n",tmp->keys.w);
	manage_move_keys(tmp);
	return (0);
}
