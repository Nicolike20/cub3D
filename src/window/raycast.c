/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:17:03 by vsavilov          #+#    #+#             */
/*   Updated: 2023/04/27 15:03:53 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	pixel_color(t_img img, int x, int y)
{
	int		c;
	char	*color;

	color = img.addr + (y * img.ln_len + x * (img.bpp / 8));
	c = *(unsigned int *)color;
	return (c);
}

static void	draw_line(t_mlx *mlx, t_raycast *ray, int x)
{
	t_tex	*tex;
	int		c;
	int		y;
	int		text_y;

	tex = &mlx->tex[ray->text_id];
	y = -1;
	while (++y < WIN_H)
	{
		if (y < ray->d_start)
			mlx_put_pixel_color(mlx->img, WIN_W - x - 1, y, CYAN);
		if (y >= ray->d_start && y <= ray->d_end)
		{
			ray->tex_pos += ray->s_dis;
			text_y = (int)ray->tex_pos & (tex->th - 1);
			c = pixel_color(tex->img, ray->text_x, text_y);
			mlx_put_pixel_color(mlx->img, WIN_W - x - 1, y, c);
		}
		if (y > ray->d_end)
			mlx_put_pixel_color(mlx->img, WIN_W - x - 1, y, WHITE);
	}
}

static void	get_texture(t_mlx *m, t_raycast *r)
{
	if (m->map->map[r->map_y][r->map_x] == DOOR
		|| m->map->map[r->map_y][r->map_x] == DOPEN)
		r->text_id = T_DOOR;
	else if ((r->map_y >= 1 && r->side == 1 && r->ray_dir_y >= 0
			&& m->map->map[r->map_y -1][r->map_x] == DOPEN)
		|| (r->map_x >= 1 && r->side == 0 && r->ray_dir_x >= 0
			&& m->map->map[r->map_y][r->map_x - 1] == DOPEN))
		r->text_id = T_DOOR;
	else if (r->side == 0)
	{
		if (r->ray_dir_x < 0)
			r->text_id = T_WEST;
		else
			r->text_id = T_EAST;
	}
	else
	{
		if (r->ray_dir_y < 0)
			r->text_id = T_NORTH;
		else
			r->text_id = T_SOUTH;
	}
}

static void	texture_pos(t_mlx *m, t_raycast *r)
{
	if (r->side == 0)
		r->wall_dist = m->player.pos_y + r->perp_wall_dist * r->ray_dir_y;
	else
		r->wall_dist = m->player.pos_x + r->perp_wall_dist * r->ray_dir_x;
	r->wall_dist -= floor(r->wall_dist);
	r->text_x = (int)(r->wall_dist * T_MAX);
	if (r->side == 0 && r->ray_dir_x > 0)
		r->text_x = m->tex[r->text_id].tw - r->text_x - 1;
	if (r->side == 1 && r->ray_dir_y < 0)
		r->text_x = m->tex[r->text_id].tw - r->text_x - 1;
	r->s_dis = 1.0 * m->tex[r->text_id].th / r->ln_height;
	r->tex_pos = (r->d_start - WIN_H / 2 + r->ln_height / 2) * r->s_dis;
}

void	raycast(t_mlx *mlx)
{
	t_raycast	*aux;
	int			x;

	x = -1;
	aux = mlx->ray;
	while (++x < WIN_W)
	{
		init_raycast(aux, &mlx->player, x);
		init_side_dist(aux, &mlx->player);
		player_collision(mlx->map, aux, x);
		calculate_line(aux);
		get_texture(mlx, aux);
		texture_pos(mlx, aux);
		draw_line(mlx, aux, x);
		aux->buffer_z[x] = aux->perp_wall_dist;
	}
}
