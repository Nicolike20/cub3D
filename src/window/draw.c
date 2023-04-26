/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:16:19 by Vsavilov          #+#    #+#             */
/*   Updated: 2023/04/26 14:16:20 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void draw(t_mlx *mlx)
{
	mlx->ray->door[X] = -1;
	mlx->ray->door[Y] = -1;
	ft_bzero(mlx->img.addr, WIN_W * WIN_H * (mlx->img.bpp / 8));
	raycast(mlx);
	crosshire(mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	draw_minimap(mlx);
}
