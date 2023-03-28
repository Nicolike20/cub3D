/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:46:37 by vsavilov          #+#    #+#             */
/*   Updated: 2023/03/28 19:19:15 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_raycast(t_raycast *ray, t_player *p, int x)
{
	ray->cam_x = (2 * x) / (float)WIN_W - 1;
	ray->ray_dir_x = p->dir_x + p->plane_x * ray->cam_x;
	ray->ray_dir_y = p->dir_y + p->plane_y * ray->cam_x;
	ray->map_x = (int)p->pos_x;
	ray->map_y = (int)p->pos_y;
	ray->coll = 0;
	ray->side = 0;
	ray->io_door = 0;
	if (ray->ray_dir_x == 0)
		ray->delta_dis_x = 1e30;
	else
		ray->delta_dis_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dis_y = 1e30;
	else
		ray->delta_dis_y = fabs(1 / ray->ray_dir_y);
}

void	init_crosshire(t_crosshire *chre, char c)
{
	if (c == 'W')
	{
		chre->x = WIN_W / 2 - CROSSHIRE_LEN;
		chre->y = WIN_H / 2;
	}
	else if (c == 'N')
	{
		chre->x = WIN_W / 2;
		chre->y = WIN_H / 2 - CROSSHIRE_LEN;
	}
	else
	{
		chre->x = WIN_W / 2;
		chre->y = WIN_H / 2;
	}
	chre->color = CYAN;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->frame_rate = -1;
	init_keys(mlx);
	init_player(&mlx->player, mlx->map->pos_x, mlx->map->pos_y, mlx->map->ori);
	mlx->mlx = mlx_init();
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img,
			&mlx->img.bpp, &mlx->img.ln_len, &mlx->img.endian);
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, NAME);
	loading_textures(mlx);
	mlx->ray = (t_raycast *)malloc(sizeof(t_raycast));
	init_minimap(mlx);
}
