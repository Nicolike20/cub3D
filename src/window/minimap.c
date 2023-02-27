#include <cub3d.h>

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

void	mmap_mlx_image(t_mlx *mlx, t_minimap *mmap)
{
	t_img img;

	img.img = mlx_new_image(mlx->mlx, mmap->xy_large, mmap->xy_large);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.ln_len, &img.endian);
	mmap->img = img;
}

void	minimap(t_mlx *mlx)
{
	t_minimap	mmap;

	init_minimap(mlx, &mmap);
}
