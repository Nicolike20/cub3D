#include <cub3d.h>

int game_loop(void *mlx)
{
	t_mlx *tmp;

	tmp = (t_mlx *)mlx;
	if (++tmp->frame_rate >= MAX_FPS)
		tmp->frame_rate = 0;
	manage_move_keys(tmp);
	draw(tmp);
	return (0);
}
