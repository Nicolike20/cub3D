#include <cub3d.h>

void init_crosshire(t_crosshire *chre)
{
	chre->x = WIN_W / 2 - CROSSHIRE_LEN / 2;
	chre->y = WIN_H / 2 - CROSSHIRE_LEN / 2;
	chre->ch_len = CROSSHIRE_LEN;
	chre->color = CYAN;
}
