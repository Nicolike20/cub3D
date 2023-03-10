/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:30:53 by vsavilov          #+#    #+#             */
/*   Updated: 2023/03/10 11:31:02 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void fpp_camera(int key, t_mlx *mlx, float speed)
{
	t_player *p;
	float auxdirx;
	float auxplanex;

	p = &mlx->player;
	auxdirx = p->dir_x;
	auxplanex = p->plane_x;
	if (key == KEY_LEFT)
	{
		p->dir_x = p->dir_x * cos(-speed) - p->dir_y * sin(-speed);
		p->dir_y = auxdirx * sin(-speed) + p->dir_y * cos(-speed);
		p->plane_x = p->plane_x * cos(-speed) - p->plane_y * sin(-speed);
		p->plane_y = auxplanex * sin(-speed) + p->plane_y * cos(-speed);
	}
	if (key == KEY_RIGHT)
	{
		p->dir_x = p->dir_x * cos(speed) - p->dir_y * sin(speed);
		p->dir_y = auxdirx * sin(speed) + p->dir_y * cos(speed);
		p->plane_x = p->plane_x * cos(speed) - p->plane_y * sin(speed);
		p->plane_y = auxplanex *sin(speed) + p->plane_y * cos(speed);
	}
}

static void sidesteps(int key , t_mlx *mlx, float speed)
{
	char	**map;
	t_player *p;
	float	aux_x;
	float	aux_y;

	p = &mlx->player;
	map = mlx->map->map;
	aux_x = p->pos_x;
	aux_y = p->pos_y;
	if (key == KEY_A)
	{
		p->pos_x += p->plane_x * speed;
		p->pos_y += p->plane_y * speed;
		if (map[(int)p->pos_y][(int)p->pos_x] == WALL)
		{
			p->pos_x = aux_x;
			p->pos_y = aux_y;
		}
	}
	if (key == KEY_D)
	{
		p->pos_x -= p->plane_x * speed;
		p->pos_y -= p->plane_y * speed;
		if (map[(int)p->pos_y][(int)p->pos_x] == WALL)
		{
			p->pos_x = aux_x;
			p->pos_y = aux_y;
		}
	}
}

static void for_backward_steps(int key, t_mlx *mlx, float speed)
{
	t_player *p;
	char	**map;
	float	aux_x;
	float	aux_y;

	p = &mlx->player;
	map = mlx->map->map;
	aux_x = p->pos_x;
	aux_y = p->pos_y;
	if (key == KEY_W)
	{
		p->pos_x += p->dir_x * speed;
		p->pos_y += p->dir_y * speed;
		if (map[(int)p->pos_y][(int)p->pos_x] == WALL)
		{
			p->pos_x = aux_x;
			p->pos_y = aux_y;
		}
	}
	if (key == KEY_S)
	{
		p->pos_x -= p->dir_x * speed;
		p->pos_y -= p->dir_y * speed;
		if (map[(int)p->pos_y][(int)p->pos_x] == WALL)
		{
			p->pos_x = aux_x;
			p->pos_y = aux_y;
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
