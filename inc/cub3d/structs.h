/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:35:37 by Vsavilov          #+#    #+#             */
/*   Updated: 2023/03/17 13:59:22 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_keys {
	_Bool	a;
	_Bool	s;
	_Bool	d;
	_Bool	w;
	_Bool	e;
	_Bool	left;
	_Bool	right;
}	t_keys;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		ln_len;
	int		endian;
}	t_img;

typedef struct s_minimap {
	t_img	img;
	t_img	ply;
	int		x;
	int		y;
	int		os_x; //map offsetX
	int		os_y; //map offsetY
	int		xy_large; //lado mas largo del mapa
	int		or_x; //orientacion x
	int		or_y; //orientacion y
	int		door[2];
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
	int		map_x;
	int		map_y;
	float	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dis_x;
	float	delta_dis_y;
	float	buffer_z[WIN_W];
	int		coll; //collision with objects
	int		ln_height;
	int		d_start;
	int		d_end;
	int		text_id;
	int		text_x;
	float		wall_dist;
	float		s_dis;
	float		tex_pos;
}	t_raycast;

typedef struct s_tex
{
//	void	*north;
//	void	*south;
//	void	*west;
//	void	*east;
//	void	*door;
//	char *path;
	t_img	img;
	int		tw;
	int		th;
}	t_tex;

//needed to load with xlm file to img-> mlx, path, tw, th (?);
//que necesita la estructura tex?

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
	t_tex	texture[5];
}	t_map;

typedef struct s_mlx {
	int			frame_rate;
	void		*mlx;
	void		*win;
	t_map		*map;
	t_minimap	*mmap;
	t_raycast	*ray;
	t_player	player;
	t_keys		keys;
	t_img		img;
	t_tex		*tex;
}	t_mlx;

#endif
