#ifndef STRUCTS_H
# define STRUCTS_H


typedef struct s_img {
	void	*img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}	t_img;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	t_img	img;
}	t_mlx;

#endif
