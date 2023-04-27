/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:30:53 by vsavilov          #+#    #+#             */
/*   Updated: 2023/04/27 14:47:06 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	sidesteps_key_d(int key, t_mlx *mlx, float speed)
{
	char		**map;
	t_player	*p;
	float		aux_x;
	float		aux_y;

	p = &mlx->player;
	map = mlx->map->map;
	aux_x = p->pos_x;
	aux_y = p->pos_y;
	if (key == KEY_D)
	{
		p->pos_x -= p->plane_x * speed;
		p->pos_y -= p->plane_y * speed;
		if (map[(int)p->pos_y][(int)p->pos_x] == WALL
			|| map[(int)p->pos_y][(int)p->pos_x] == DOOR)
		{
			p->pos_x = aux_x;
			p->pos_y = aux_y;
		}
	}
}

static void	sidesteps(int key, t_mlx *mlx, float speed)
{
	char		**map;
	t_player	*p;
	float		aux_x;
	float		aux_y;

	p = &mlx->player;
	map = mlx->map->map;
	aux_x = p->pos_x;
	aux_y = p->pos_y;
	if (key == KEY_A)
	{
		p->pos_x += p->plane_x * speed;
		p->pos_y += p->plane_y * speed;
		if (map[(int)p->pos_y][(int)p->pos_x] == WALL
			|| map[(int)p->pos_y][(int)p->pos_x] == DOOR)
		{
			p->pos_x = aux_x;
			p->pos_y = aux_y;
		}
	}
	sidesteps_key_d(key, mlx, speed);
}

static void	step_key_s(int key, t_mlx *mlx, float speed)
{
	t_player	*p;
	char		**map;
	float		aux_x;
	float		aux_y;

	p = &mlx->player;
	map = mlx->map->map;
	aux_x = p->pos_x;
	aux_y = p->pos_y;
	if (key == KEY_S)
	{
		p->pos_x -= p->dir_x * speed;
		p->pos_y -= p->dir_y * speed;
		if (map[(int)p->pos_y][(int)p->pos_x] == WALL
			|| map[(int)p->pos_y][(int)p->pos_x] == DOOR)
		{
			p->pos_x = aux_x;
			p->pos_y = aux_y;
		}
	}
}

static void	for_backward_steps(int key, t_mlx *mlx, float speed)
{
	t_player	*p;
	char		**map;
	float		aux_x;
	float		aux_y;

	p = &mlx->player;
	map = mlx->map->map;
	aux_x = p->pos_x;
	aux_y = p->pos_y;
	if (key == KEY_W)
	{
		p->pos_x += p->dir_x * speed;
		p->pos_y += p->dir_y * speed;
		if (map[(int)p->pos_y][(int)p->pos_x] == WALL
			|| map[(int)p->pos_y][(int)p->pos_x] == DOOR)
		{
			p->pos_x = aux_x;
			p->pos_y = aux_y;
		}
	}
	step_key_s(key, mlx, speed);
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
