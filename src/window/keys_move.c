/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:30:53 by vsavilov          #+#    #+#             */
/*   Updated: 2023/03/09 19:06:02 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void fpp_camera(int key, t_mlx *mlx, float speed)
{
	t_player *p;
	float auxdirx;
	float auxplanex;

	p = &mlx->player;
	auxdirx = p->dirX;
	auxplanex = p->planeX;
	if (key == KEY_LEFT)
	{
		p->dirX = p->dirX * cos(-speed) - p->dirY * sin(-speed);
		p->dirY = auxdirx * sin(-speed) + p->dirY * cos(-speed);
		p->planeX = p->planeX * cos(-speed) - p->planeY * sin(-speed);
		p->planeY = auxplanex * sin(-speed) + p->planeY * cos(-speed);
	}
	if (key == KEY_RIGHT)
	{
		p->dirX = p->dirX * cos(speed) - p->dirY * sin(speed);
		p->dirY = auxdirx * sin(speed) + p->dirY * cos(speed);
		p->planeX = p->planeX * cos(speed) - p->planeY * sin(speed);
		p->planeY = auxplanex *sin(speed) + p->planeY * cos(speed);
	}
}

static void sidesteps(int key , t_mlx *mlx, float speed)
{
	char	**map;
	t_player *p;
	float	auxX;
	float	auxY;

	p = &mlx->player;
	map = mlx->map->map;
	auxX = p->pos_x;
	auxY = p->pos_y;
	if (key == KEY_A)
	{
		p->pos_x += p->planeX * speed;
		p->pos_y += p->planeY * speed;
		if (map[(int)p->pos_y][(int)p->pos_x] == WALL)
		{
			p->pos_x = auxX;
			p->pos_y = auxY;
		}
	}
	if (key == KEY_D)
	{
		p->pos_x -= p->planeX * speed;
		p->pos_y -= p->planeY * speed;
		if (map[(int)p->pos_y][(int)p->pos_x] == WALL)
		{
			p->pos_x = auxX;
			p->pos_y = auxY;
		}
	}
}

static void for_backward_steps(int key, t_mlx *mlx, float speed)
{
	t_player *p;
	char	**map;
	float	auxX;
	float	auxY;

	p = &mlx->player;
	map = mlx->map->map;
	auxX = p->pos_x;
	auxY = p->pos_y;
	if (key == KEY_W)
	{
		p->pos_x += p->dirX * speed;
		p->pos_y += p->dirY * speed;
		if (map[(int)p->pos_y][(int)p->pos_x] == WALL)
		{
			p->pos_x = auxX;
			p->pos_y = auxY;
		}
	}
	if (key == KEY_S)
	{
		p->pos_x -= p->dirX * speed;
		p->pos_y -= p->dirY * speed;
		if (map[(int)p->pos_y][(int)p->pos_x] == WALL)
		{
			p->pos_x = auxX;
			p->pos_y = auxY;
		}
	}
}

void	manage_move_keys(t_mlx *mlx)
{
	if (mlx->keys.w != mlx->keys.s)
	{
		if (mlx->keys.w == TRUE)
			for_backward_steps(KEY_W, mlx, SPEED);
		else if (mlx->keys.s == TRUE)
			for_backward_steps(KEY_S, mlx, SPEED);
	}
	if (mlx->keys.a != mlx->keys.d)
	{
		if (mlx->keys.a == TRUE)
			sidesteps(KEY_A, mlx, SPEED);
		else if (mlx->keys.d == TRUE)
			sidesteps(KEY_D, mlx, SPEED);
	}
	if (mlx->keys.left != mlx->keys.right)
	{
		if (mlx->keys.left == TRUE)
			fpp_camera(KEY_LEFT, mlx, FPP_CAM_SPEED);
		else if (mlx->keys.right == TRUE)
			fpp_camera(KEY_RIGHT, mlx, FPP_CAM_SPEED);
	}
}
