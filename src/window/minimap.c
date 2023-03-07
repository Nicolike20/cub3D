#include <cub3d.h>

//Minimapa: Suelo 0, Muro 1, Pj NSWE Puerta open O close C

/*static void minimap_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	mlx_put_pixel_color(mlx->mmap->img, x, y, color);
}

static	void draw_empty_minimap(t_mlx *mlx, int x, int y)
{
	int px;
	int py;
	int end_x;
	int end_y;
	//add color for every type of char map

	end_y = (y + 1) * mlx->mmap.xy_large / fmax(mlx->map->width, mlx->map->height);
	py = y * mlx->mmap.xy_large / fmax(mlx->map->width, mlx->map->height);
	while (py < end_y)
	{
		end_x = (x + 1) * mlx->mmap.xy_large / fmax(mlx->map->width, mlx->map->height);
		px = x * mlx->mmap.xy_large / fmax(mlx->map->width, mlx->map->height);
		while (px < end_x)
		{
			minimap_put_pixel(mlx, x, y, WHITE);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_mlx *mlx)
{
	mlx->mmap.y = -1;
	while (++mlx->mmap.y < mlx->map->height)
	{
		if (mlx->map->map[mlx->mmap.y] == NULL)
			break ;
		mlx->mmap.x = -1;
		while (++mlx->mmap.x < mlx->map->width)
		{
			if (mlx->map->map[mlx->mmap.y][mlx->mmap.x] == '\0')
				break ;
			draw_empty_minimap(mlx, mlx->mmap.x, mlx->mmap.y);
		}
	}
}*/

void	minimap(t_mlx *mlx)
{
	init_minimap(mlx);
}

void	mmap_background(t_minimap mmap)
{
	mmap.y = -1;
	while (++mmap.y < mmap.xy_large)
	{
		mmap.x = -1;
		while (mmap.x < mmap.xy_large)
			mlx_put_pixel_color(mmap.img, mmap.x, mmap.y, WHITE);
	}
}

void	mmap_mlx_image(t_minimap *map, void *ptr)
{
	map->img.img = mlx_new_image(ptr, map->xy_large, map->xy_large);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bpp, &map->img.ln_len, &map->img.endian);
}

void	calculate_offset(t_minimap *map, int width, int height)
{
	map->osX = 0;
	map->osY = 0;
	if (width > height)
		map->osY = (width - height) * fmax(WIN_W, WIN_H) / MINIMAP_SCALE / width;
	else if (height > width)
		map->osX = (height - width) * fmax(WIN_W, WIN_H) / MINIMAP_SCALE / height;
}

void init_minimap(t_mlx *mlx)
{
	mlx->mmap = (t_minimap *)malloc(sizeof(t_minimap));
	mlx->mmap->xy_large = fmax(WIN_W, WIN_H) / MINIMAP_SCALE;
	calculate_offset(mlx->mmap, mlx->map->width, mlx->map->height);
	mmap_mlx_image(mlx->mmap, mlx->mlx);
	mmap_background(*mlx->mmap);
}
