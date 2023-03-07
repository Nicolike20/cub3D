/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:19:11 by Vsavilov          #+#    #+#             */
/*   Updated: 2023/03/07 17:49:30 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void mlx_key_events(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, (1L << 0), key_press, mlx);
	mlx_hook(mlx->win, 3, (1L << 1), key_relase, mlx);
}

int init_window(t_mlx *mlx) {
	init_mlx(mlx);

	mlx_key_events(mlx);
	mlx_key_hook(mlx->win, manage_keys, mlx);
	mlx_loop_hook(mlx->mlx, game_loop, mlx);
	mlx_loop(mlx->mlx);
	free_mlx(mlx);
	return 0;
}
