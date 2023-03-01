#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_keys {
	_Bool	a;
	_Bool	s;
	_Bool	d;
	_Bool	w;
}	t_keys;

typedef struct s_img {
	void	*img;
	char	*addr;
	int	bpp;
	int	ln_len;
	int	endian;
}	t_img;

typedef struct s_minimap {
	t_img	img;
	int	x;
	int	y;
	int	xy_large; //lado mas largo del mapa
	int	or_x; //orientacion x
	int	or_y; //orientacion y
}	t_minimap;

typedef struct s_crosshire {
	int	x;
	int	y;
	int	color;
}	t_crosshire;

typedef struct s_plane {
	float	posX;
	float	posY;
	float	dirX;
	float	dirY;
	float	planeX;
	float	planeY;
}	t_plane;

typedef struct s_raycast {
	float	rayDirX;
	float	rayDirY;
	float	camX;
	float	camY;
	int	mapX;
	int	mapY;
	float	sideDistX;
	float	sideDistY;
	float	deltaDisX;
	float	deltaDisY;
}	t_raycast;

typedef struct s_map {
	int	width;
	int	height;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*d;
	char	*c;
	char	*f;
	char	*tmp;
	char	*tmp_aux;
	char	**map;
	int	map_len;
	int	in_map;
	int	ns;
}	t_map;

typedef struct s_mlx {
	int	frameRate;
	void	*mlx;
	void	*win;
	t_map	*map;
	t_minimap mmap;
	t_raycast *ray;
	t_plane plane;
	t_keys	keys;
	t_img	img;
}	t_mlx;

#endif
