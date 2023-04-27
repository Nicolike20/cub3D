/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:58:47 by Vsavilov          #+#    #+#             */
/*   Updated: 2023/04/27 15:01:06 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_side_dist(t_raycast *ray, t_player *p)
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

void	player_collision(t_map *map, t_raycast *ray, int x)
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

void	calculate_line(t_raycast *ray)
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
