/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:49:57 by vsavilov          #+#    #+#             */
/*   Updated: 2023/04/27 14:55:06 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	draw_minimap_pixel_put(t_img img, int pos_sx, int pos_sy)
{
	float	x;
	float	y;

	y = -1;
	while (++y < 5)
	{
		x = -1;
		while (++x < 5)
			mlx_put_pixel_color(img, pos_sx + x, pos_sy + y, RED);
	}
}

static void	draw_minimap_supp(t_minimap *m)
{
	int	x;
	int	y;

	y = -1;
	while (++y < m->xy_large)
	{
		x = -1;
		while (++x < m->xy_large)
			mlx_put_pixel_color(m->ply, x, y,
				pixel_color(m->img, x, y));
	}
}

void	draw_minimap(t_mlx *mlx)
{
	t_minimap	*m;
	int			side_len;
	int			px;
	int			py;

	m = mlx->mmap;
	draw_minimap_supp(m);
	px = (m->os_x / 2) + (mlx->player.pos_x
			* ((m->img.ln_len / m->img.bpp * 8)
				/ fmax(mlx->map->width, mlx->map->height)));
	py = (m->os_y / 2) +(mlx->player.pos_y
			* ((m->img.ln_len / m->img.bpp * 8)
				/ fmax(mlx->map->width, mlx->map->height)));
	side_len = 5;
	px -= side_len / 2;
	py -= side_len / 2;
	draw_minimap_pixel_put(m->ply, px, py);
	mlx_put_image_to_window(mlx->mlx, mlx->win, m->ply.img,
		WIN_W - (m->ply.ln_len / m->ply.bpp * 8) - 15, 15);
}

void	mmap_background(t_minimap mmap)
{
	mmap.y = -1;
	while (++mmap.y < mmap.xy_large)
	{
		mmap.x = -1;
		while (++mmap.x < mmap.xy_large)
			mlx_put_pixel_color(mmap.img, mmap.x, mmap.y, WHITE);
	}
}

void	mmap_mlx_image(t_minimap *map, void *ptr)
{
	map->img.img = mlx_new_image(ptr, map->xy_large, map->xy_large);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bpp,
			&map->img.ln_len, &map->img.endian);
	map->ply.img = mlx_new_image(ptr, map->xy_large, map->xy_large);
	map->ply.addr = mlx_get_data_addr(map->ply.img, &map->ply.bpp,
			&map->ply.ln_len, &map->ply.endian);
}
