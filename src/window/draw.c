#include <cub3d.h>

static void	my_mlx_put_pixel(t_img img, int x, int y, int color)
{
	int	pixel;

	if (y >= WIN_H || x >= WIN_W || x < 0 || y < 0)
		return ;
	pixel = y * img.ln_len + x * (img.bpp / 8);
	if (img.endian == 0)
	{
		img.addr[pixel + 0] = (color) & 0xFF;
		img.addr[pixel + 1] = (color >> 8) & 0xFF;
		img.addr[pixel + 2] = (color >> 16) & 0xFF;
		img.addr[pixel + 3] = (color >> 24);
	}
	else if (img.endian == 1)
	{
		img.addr[pixel + 0] = (color >> 24);
		img.addr[pixel + 1] = (color >> 16) & 0xFF;
		img.addr[pixel + 2] = (color >> 8) & 0xFF;
		img.addr[pixel + 3] = (color) & 0xFF;
	}
}

static void crosshire(t_img img) {
	t_crosshire chre;
	float	fx;
	float	fy;

	init_crosshire(&chre);
	fy = -1;
	while (++fy < chre.ch_len)
	{
		fx = -1;
		while (++fx < chre.ch_len)
			my_mlx_put_pixel(img, chre.x + fx, chre.y + fy, chre.color);
	}
}

void draw(t_mlx *mlx)
{
	//TODO:raycast -> crosshire -> minimap? -> help panel
	//Let's start with crosshire
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, &mlx->img.ln_len, &mlx->img.endian);
	ft_bzero(mlx->img.addr, WIN_W * WIN_H * (mlx->img.bpp / 8));
	crosshire(mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}
