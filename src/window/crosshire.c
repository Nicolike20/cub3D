#include <cub3d.h>

static void print_crosshire(t_img img, t_crosshire ch, char c)
{
	int i;
	int j;

	j = -1;
	printf("%d---%d\n", ch.x, ch.y);
	if (c == 'y')
		while (j < 2) {
			i = 0;
			while (++i < CROSSHIRE_LEN)
				mlx_put_pixel_color(img, ch.x + j, ch.y + i, ch.color);
			j++;
		}
	if (c == 'x')
		while (j < 2) {
			i = 0;
			while (++i < CROSSHIRE_LEN)
				mlx_put_pixel_color(img, ch.x + i, ch.y + j, ch.color);
			j++;
		}
}
/*
NORTE: mlx_put_pixel_color(img, WIN_W/2 + j, WIN_H / 2 + i - ch_width, color)
SUR: mlx_put_pixel_color(img, WIN_W / 2 + j, WIN_H / 2 + i, color);
E: mlx_put_pixel_color(img, WIN_W / 2 + i, WIN_H / 2 + j, color);
W: mlx_put_pixel_color(img, WIN_W / 2 + i - ch_width, WIN_H / 2 + j, color);
*/
void crosshire(t_img img) {
	t_crosshire chre;

	init_crosshire(&chre, 'N');
	print_crosshire(img, chre, 'y');
	init_crosshire(&chre, 'S');
	print_crosshire(img, chre, 'y');
	init_crosshire(&chre, 'W');
	print_crosshire(img, chre, 'x');
	init_crosshire(&chre, 'E');
	print_crosshire(img, chre, 'x');
}
