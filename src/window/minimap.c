#include <cub3d.h>

void	mmap_background(t_mlx *mlx, t_minimap *mmap)
{
(void)mlx;
(void)mmap;
}

void	mmap_mlx_image(t_mlx *mlx, t_minimap *mmap)
{
	mmap->img = mlx_new_image(mlx->mlx, mmap->xy_large, mmap->xy_large);
	mmap->addr = mlx_get_data_addr(mmap->img, &mmap->bpp, &mmap->ln_len, &mmap->endian);
}

void	minimap(t_mlx *mlx)
{
	t_minimap	mmap;

	init_minimap(mlx, &mmap);
}
