/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:30:53 by vsavilov          #+#    #+#             */
/*   Updated: 2023/03/08 13:42:11 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void sidesteps(int key , t_mlx *mlx, float speed)
{
	char	**map;
	t_player *p;

	p = &mlx->player;
	map = mlx->map->map;
	if (key == KEY_A)
	{
		if (map[(int)p->pos_y][(int)(p->pos_x + p->planeX * speed)] == FLOOR)
			p->pos_x += p->planeX * speed;
		if (map[(int)(p->pos_y + p->planeY * speed)][(int)p->pos_x] == FLOOR)
			p->pos_y += p->planeY * speed;
	}
	if (key == KEY_D)
	{
		if (map[(int)p->pos_y][(int)(p->pos_x - p->planeX * speed)] == FLOOR)
			p->pos_x -= p->planeX * speed;
		if (map[(int)(p->pos_y - p->planeY * speed)][(int)p->pos_x] == FLOOR)
			p->pos_y -= p->planeY * speed;
	}
}

static void for_backward_steps(int key, t_mlx *mlx, float speed)
{
	t_player *p;
	char	**map;
	p = &mlx->player;
	map = mlx->map->map;
	if (key == KEY_W)
	{
		if (map[(int)p->pos_y][(int)(p->pos_x + p->dirX * speed)] == FLOOR)
			p->pos_x += p->dirX * speed;
	}
	if (key == KEY_S)
	{
		if (map[(int)(p->pos_y + p->dirY * speed)][(int)p->pos_x] == FLOOR)
			p->pos_y += p->dirX * speed;
	}
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
