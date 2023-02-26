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

typedef struct s_crosshire {
	int	x;
	int	y;
	int	ch_len;
	int	color;
}	t_crosshire;

typedef struct s_raycasting {
	int	x;
	int	y;
	int	map_x;
	int	map_y;
	int	draw_start;
	int	draw_end;
}	t_raycasting;

typedef struct s_map {
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
	t_keys	keys;
	t_img	img;
}	t_mlx;

#endif
