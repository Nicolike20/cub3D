/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:19:11 by Vsavilov          #+#    #+#             */
/*   Updated: 2023/04/27 14:48:47 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	x_close(int keycode, t_mlx *mlx)
{
	(void)keycode;
	(void)mlx;
	exit(0);
	return (0);
}

static void	mlx_key_events(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, (1L << 0), key_press, mlx);
	mlx_hook(mlx->win, 3, (1L << 1), key_relase, mlx);
	mlx_hook(mlx->win, 17, (1L << 17), x_close, mlx);
	mlx_hook(mlx->win, 6, (1L << 6), handle_mouse, mlx);
}

int	init_window(t_mlx *mlx)
{
	init_mlx(mlx);
	mlx_key_events(mlx);
	mlx_loop_hook(mlx->mlx, game_loop, mlx);
	mlx_loop(mlx->mlx);
	free_mlx(mlx);
	return (0);
}
