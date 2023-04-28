/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:51:52 by Vsavilov          #+#    #+#             */
/*   Updated: 2023/04/27 14:56:00 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
	int	color;

	if (map[y][x] == FLOOR)
		color = SILVER;
	else if (map[y][x] == DOOR)
		color = BROWN;
	else if (map[y][x] == WALL)
		color = BLUE;
	else
		color = WHITE;
	return (color);
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
