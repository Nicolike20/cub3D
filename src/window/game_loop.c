#include <cub3d.h>

int game_loop(void *mlx)
{
	t_mlx *tmp;

	tmp = (t_mlx *)mlx;
	if (++tmp->frameRate >= MAX_FPS)
		tmp->frameRate = 0;
	manage_move_keys(tmp);
	draw(tmp);
	//printf("%d\n",tmp->keys.w);
	return (0);
}
