/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:17:03 by vsavilov          #+#    #+#             */
/*   Updated: 2023/04/26 15:45:54 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_side_dist(t_raycast *ray, t_player *p)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (p->pos_x - ray->map_x) * ray->delta_dis_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - p->pos_x) * ray->delta_dis_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (p->pos_y - ray->map_y) * ray->delta_dis_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - p->pos_y) * ray->delta_dis_y;
	}
}

static void	player_collision(t_map *map, t_raycast *ray, int x)
{
	while (ray->coll == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dis_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dis_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->map[ray->map_y][ray->map_x] == WALL
			|| map->map[ray->map_y][ray->map_x] == DOOR)
			ray->coll = 1;
		io_door(map->map, ray, x);
	}
}

static void	calculate_line(t_raycast *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dis_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dis_y;
	ray->ln_height = (int)(WIN_H / ray->perp_wall_dist);
	ray->d_start = -ray->ln_height / 2 + WIN_H / 2;
	if (ray->d_start < 0)
		ray->d_start = 0;
	ray->d_end = ray->ln_height / 2 + WIN_H / 2;
	if (ray->d_end >= WIN_H)
		ray->d_end = WIN_H - 1;
}

int	pixel_color(t_img img, int x, int y)
{
	int c;
	char *color;

	color = img.addr + (y * img.ln_len + x * (img.bpp / 8));
	c = *(unsigned int *)color;
	return c;
}

static void	draw_line(t_mlx *mlx, t_raycast *ray, int x)
{
	int	y;
	t_tex *tex;
	int c;
	int text_y;

	tex = &mlx->tex[ray->text_id];
	y = -1;
	while (++y < WIN_H)
	{
		if (y < ray->d_start)
			mlx_put_pixel_color(mlx->img, WIN_W - x - 1, y, mlx->map->c_hex);
		if (y >= ray->d_start && y <= ray->d_end)
		{
			ray->tex_pos += ray->s_dis;
			text_y = (int)ray->tex_pos & (tex->th - 1);
			c = pixel_color(tex->img, ray->text_x, text_y);
			mlx_put_pixel_color(mlx->img, WIN_W - x - 1, y, c);
		}
		if (y > ray->d_end)
			mlx_put_pixel_color(mlx->img, WIN_W - x - 1, y, mlx->map->f_hex);
	}
}

static void get_texture(t_mlx *m, t_raycast *r)
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

static void texture_pos(t_mlx *m, t_raycast *r)
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
