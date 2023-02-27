#include <cub3d.h>

//Minimapa: Suelo 0, Muro 1, Pj NSWE Puerta open O close C

static void minimap_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	mlx_put_pixel_color(mlx->mmap.img, x, y, color);
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
	//borrar:
	//mlx->map->width = 8;
	//mlx->map->height = 8;

	//borrar
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

void	mmap_mlx_image(t_mlx *mlx)
{
	mlx->mmap.img.img = mlx_new_image(mlx->mlx, mlx->mmap.xy_large, mlx->mmap.xy_large);
	mlx->mmap.img.addr = mlx_get_data_addr(mlx->mmap.img.img, &mlx->mmap.img.bpp,
			&mlx->mmap.img.ln_len, &mlx->mmap.img.endian);
}

void	minimap(t_mlx *mlx)
{
	init_minimap(mlx);
}
