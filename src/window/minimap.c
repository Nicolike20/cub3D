/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:49:57 by vsavilov          #+#    #+#             */
/*   Updated: 2023/03/09 21:15:07 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

//Minimapa: Suelo 0, Muro 1, Pj NSWE Puerta open O close C

static void	draw_minimap_pixel_put(t_minimap *m, int pos_sx, int pos_sy)
{
	float	x;
	float	y;

	y = -1;
	while (++y < 5)
	{
		x = -1;
		while (++x < 5)
		{
			mlx_put_pixel_color(m->img, pos_sx + x, pos_sy + y, RED);
		}
	}
}

void	draw_minimap(t_mlx *mlx)
{
	int			ln;
	int			pos_sx;
	int			pos_sy;
	t_minimap	*map;

	map = mlx->mmap;
	pos_sx = (map->os_x / 2) + (mlx->player.pos_x
			* ((map->img.ln_len / map->img.bpp * 8)
				/ fmax(mlx->map->width, mlx->map->height)));
	pos_sy = (map->os_y / 2) +(mlx->player.pos_y
			* ((map->img.ln_len / map->img.bpp * 8)
				/ fmax(mlx->map->width, mlx->map->height)));
	ln = 5;
	pos_sx -= ln / 2;
	pos_sy -= ln / 2;
	draw_minimap_pixel_put(map, pos_sx, pos_sy);
	mlx_put_image_to_window(mlx->mlx, mlx->win, map->img.img,
		WIN_W - (map->img.ln_len / map->img.bpp * 8) - 15, 15);
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
}

void	calculate_offset(t_minimap *map, int width, int height)
{
	map->os_x = 0;
	map->os_y = 0;
	if (width > height)
		map->os_y = (width - height) * (fmax(WIN_W, WIN_H)
				/ MINIMAP_SCALE / width);
	else if (height > width)
		map->os_x = (height - width) * (fmax(WIN_W, WIN_H)
				/ MINIMAP_SCALE / height);
}

static void	mmap_put_pixel(t_minimap *m, int x, int y)
{
	mlx_put_pixel_color(m->img, x + (m->os_x / 2), y + (m->os_y / 2), BLUE);
}

static void	mmap_draw_pixel(t_minimap *mmap, t_map *map)
{
	int	px;
	int	py;
	int	d_y;
	int	d_x;

	d_y = (mmap->y + 1) * mmap->xy_large / fmax(map->width, map->height);
	py = mmap->y * mmap->xy_large / fmax(map->width, map->height);
	while (py < d_y)
	{
		d_x = (mmap->x + 1) * mmap->xy_large / fmax(map->width, map->height);
		px = mmap->x * mmap->xy_large / fmax(map->width, map->height);
		while (px < d_x)
		{
			mmap_put_pixel(mmap, px, py);
			px++;
		}
		py++;
	}
}	

static void	mmap_draw(t_minimap *mmap, t_map *map)
{
	mmap->y = -1;
	while (++mmap->y < map->height)
	{
		if (map->map[mmap->y] == NULL)
			break ;
		mmap->x = -1;
		while (++mmap->x < map->width)
		{
			if (map->map[mmap->y][mmap->x] == '\0')
				break ;
			mmap_draw_pixel(mmap, map);
		}
	}
}

void	init_minimap(t_mlx *mlx)
{
	mlx->mmap = (t_minimap *)malloc(sizeof(t_minimap));
	mlx->mmap->xy_large = fmax(WIN_W, WIN_H) / MINIMAP_SCALE;
	calculate_offset(mlx->mmap, mlx->map->width, mlx->map->height);
	mmap_mlx_image(mlx->mmap, mlx->mlx);
	mmap_background(*mlx->mmap);
	mmap_draw(mlx->mmap, mlx->map);
}
