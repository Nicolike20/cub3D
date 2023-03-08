#include <cub3d.h>

static void for_backward_steps(int key, t_mlx *mlx, float speed)
{
	t_player *p;
	char	**map;
(void)key;
	p = &mlx->player;
	map = mlx->map->map;
	if (map[(int)p->pos_y][(int)(p->pos_x + p->dirX * speed)] == '0')
		p->pos_x += p->dirX * speed;
	if (map[(int)(p->pos_y + p->dirY * speed)][(int)p->pos_x] == '0')
		p->pos_y += p->dirX * speed;
}

void	manage_move_keys(t_mlx *mlx)
{
	if (mlx->keys.w != mlx->keys.s)
	{
		if (mlx->keys.w == TRUE)
			for_backward_steps(KEY_W, mlx, 0.05);
		else if (mlx->keys.s == TRUE)
			for_backward_steps(KEY_S, mlx, -0.05);
	}
	
}
