#include <cub3d.h>

static t_player dir_plane(float dir_x, float dir_y, float pl_x, float pl_y)
{
	t_player p;

	p.dir_x = dir_x;
	p.dir_y = dir_y;
	p.plane_x = pl_x;
	p.plane_y = pl_y;
	return (p);
}

void	init_player(t_player *p, float pos_x, float pos_y, char c)
{
	if (c == 'N')
		*p = dir_plane(0, -1, -0.66, 0.0);
	if (c == 'S')
		*p = dir_plane(0, 1, 0.66, 0.0);
	if (c == 'W')
		*p = dir_plane(0, 1, 0.0, 0.66);
	if (c == 'E')
		*p = dir_plane(1, 0, 0.0, -0.66);
	p->pos_x = pos_x + 0.5;
	p->pos_y = pos_y + 0.5;
}
