/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:16:19 by Vsavilov          #+#    #+#             */
/*   Updated: 2023/04/27 14:29:13 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw(t_mlx *mlx)
{
	mlx->ray->door[X] = -1;
	mlx->ray->door[Y] = -1;
	ft_bzero(mlx->img.addr, WIN_W * WIN_H * (mlx->img.bpp / 8));
	raycast(mlx);
	crosshire(mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	draw_minimap(mlx);
}

void	fpp_camera(int key, t_mlx *mlx, float speed)
{
	t_player	*p;
	float		auxdirx;
	float		auxplanex;

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
		p->plane_y = auxplanex * sin(speed) + p->plane_y * cos(speed);
	}
}
