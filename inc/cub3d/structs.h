/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:35:37 by Vsavilov          #+#    #+#             */
/*   Updated: 2023/03/09 19:36:43 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_keys {
	_Bool	a;
	_Bool	s;
	_Bool	d;
	_Bool	w;
	_Bool	left;
	_Bool	right;
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
	int	os_x; //map offsetX
	int	os_y; //map offsetY
	int	xy_large; //lado mas largo del mapa
	int	or_x; //orientacion x
	int	or_y; //orientacion y
}	t_minimap;

typedef struct s_crosshire {
	int	x;
	int	y;
	int	color;
}	t_crosshire;

typedef struct s_player {
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
}	t_player;

typedef struct s_raycast {
	float	ray_dir_x;
	float	ray_dir_y;
	float	cam_x;
	float	cam_y;
	int	map_x;
	int	map_y;
	float	perp_wall_dist;
	int	step_x;
	int	step_y;
	int	side;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dis_x;
	float	delta_dis_y;
	float	buffer_z[WIN_W];
	int	coll; //collision with objects
	int	ln_height;
	int	d_start;
	int	d_end;
}	t_raycast;

//incluir orientacion inicial
//nombres width y height
//player posicion inicial x, y (float)
//no hacer free

typedef struct s_tex
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	void	*door;
}t_tex;

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
	int		height;
	int		width;
	char	ori;
	float	pos_x;
	float	pos_y;
	int		in_map;
	int		ns;
}	t_map;

typedef struct s_mlx {
	int		frame_rate;
	void		*mlx;
	void		*win;
	t_map		*map;
	t_minimap	*mmap;
	t_raycast	*ray;
	t_player	player;
	t_keys		keys;
	t_img		img;
}		t_mlx;

#endif
