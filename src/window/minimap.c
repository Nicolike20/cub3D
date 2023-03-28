/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:49:57 by vsavilov          #+#    #+#             */
/*   Updated: 2023/03/28 19:22:42 by nortolan         ###   ########.fr       */
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

static void draw_minimap_supp(t_minimap *m)
{
	int x;
	int y;

	y = -1;
	while (++y < m->xy_large)
	{
		x = -1;
		while (++x < m->xy_large)
			mlx_put_pixel_color(m->ply, x, y, 
					pixel_color(m->img, x, y));
	}
}

void draw_minimap(t_mlx *mlx)
{
	int side_len;
	int px;
	int py;
	t_minimap *m = mlx->mmap;

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
	mlx_put_image_to_window(mlx->mlx, mlx->win, m->ply.img, WIN_W - (m->ply.ln_len / m->ply.bpp * 8) - 15, 15);
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

static int	get_mmap_color(char **map, int x, int y)
{
	int color;

	if (map[y][x] == FLOOR)
		color = SILVER;
	else if (map[y][x] == DOOR)
		color = BROWN;
	else if (map[y][x] == WALL)
		color = BLUE;
	else
		color = WHITE;
	return color;
}

static void	mmap_draw_pixel(t_minimap *mmap, t_map *map)
{
	int	px;
	int	py;
	int	d_y;
	int	d_x;
	int	color;

	d_y = (mmap->y + 1) * mmap->xy_large / fmax(map->width, map->height);
	py = mmap->y * mmap->xy_large / fmax(map->width, map->height);
	while (py < d_y)
	{
		d_x = (mmap->x + 1) * mmap->xy_large / fmax(map->width, map->height);
		px = mmap->x * mmap->xy_large / fmax(map->width, map->height);
		while (px < d_x)
		{
			color = get_mmap_color(map->map, mmap->x, mmap->y);
			mlx_put_pixel_color(mmap->img, px + (mmap->os_x / 2),
					py + (mmap->os_y / 2), color);
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
