/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:30:53 by vsavilov          #+#    #+#             */
/*   Updated: 2023/03/08 12:30:55 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void sidesteps(int key , t_mlx *mlx, float speed)
{
	
}

static void for_backward_steps(int key, t_mlx *mlx, float speed)
{
	t_player *p;
	char	**map;
	(void)key;
	p = &mlx->player;
	map = mlx->map->map;
	if (map[(int)p->pos_y][(int)(p->pos_x + p->dirX * speed)] == FLOOR)
		p->pos_x += p->dirX * speed;
	if (map[(int)(p->pos_y + p->dirY * speed)][(int)p->pos_x] == FLOOR)
		p->pos_y += p->dirX * speed;
}

void	manage_move_keys(t_mlx *mlx)
{
	if (mlx->keys.w != mlx->keys.s)
	{
		if (mlx->keys.w == TRUE)
			for_backward_steps(KEY_W, mlx, SPEED);
		else if (mlx->keys.s == TRUE)
			for_backward_steps(KEY_S, mlx, -SPEED);
	}
	if (mlx->keys.a != mlx->keys.d)
	{
		if (mlx->keys.a == TRUE)
			sidesteps(KEY_A, mlx, SPEED);
		else if (mlx->keys.d == TRUE)
			sidesteps(KEY_D, mlx, -SPEED);
	}
}
