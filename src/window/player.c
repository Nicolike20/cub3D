#include <cub3d.h>

static t_player dir_plane(float dirX, float dirY, float planeX, float planeY)
{
	t_player p;

	p.dirX = dirX;
	p.dirY = dirY;
	p.planeX = planeX;
	p.planeY = planeY;
	return (p);
}

void	init_player(t_player *p, float posX, float posY, char c)
{
	if (c == 'N')
		*p = dir_plane(0, -1, -0.66, 0);
	if (c == 'S')
		*p = dir_plane(0, 1, 0.66, 0);
	if (c == 'W')
		*p = dir_plane(0, 1, 0, 0.66);
	if (c == 'E')
		*p = dir_plane(1, 0, 0, -0.66);
	(void)posX;
	(void)posY;
	//posicion del personaje.
	p->pos_x = posX + 0.5;
	p->pos_y = posY + 0.5;
}
