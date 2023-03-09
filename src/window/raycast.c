/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:17:03 by vsavilov          #+#    #+#             */
/*   Updated: 2023/03/09 19:48:44 by vsavilov         ###   ########.fr       */
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

static void	player_collision(t_map *map, t_raycast *ray)
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
		if (map->map[ray->map_y][ray->map_x] == WALL)
			ray->coll = 1;
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

static void	draw_line(t_mlx *mlx, t_raycast *ray, int x)
{
	int	y;

	y = -1;
	while (++y < WIN_H)
	{
		if (y < ray->d_start)
			mlx_put_pixel_color(mlx->img, WIN_W - x - 1, y, CYAN);
		if (y >= ray->d_start && y <= ray->d_end)
			mlx_put_pixel_color(mlx->img, WIN_W - x - 1, y, RED);
		if (y > ray->d_end)
			mlx_put_pixel_color(mlx->img, WIN_W - x - 1, y, WHITE);
	}
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
		player_collision(mlx->map, aux);
		calculate_line(aux);
		draw_line(mlx, aux, x);
		aux->buffer_z[x] = aux->perp_wall_dist;
	}
}
