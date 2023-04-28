/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:49:30 by vsavilov          #+#    #+#             */
/*   Updated: 2023/04/28 18:36:09 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_image(mlx->mlx, mlx->mmap->img.img);
	mlx_destroy_image(mlx->mlx, mlx->mmap->ply.img);
	mlx_destroy_image(mlx->mlx, mlx->tex[T_NORTH].img.img);
	mlx_destroy_image(mlx->mlx, mlx->tex[T_SOUTH].img.img);
	mlx_destroy_image(mlx->mlx, mlx->tex[T_WEST].img.img);
	mlx_destroy_image(mlx->mlx, mlx->tex[T_EAST].img.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx);
}
