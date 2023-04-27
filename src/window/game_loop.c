/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:16:57 by Vsavilov          #+#    #+#             */
/*   Updated: 2023/04/27 14:17:09 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	game_loop(void *mlx)
{
	t_mlx	*tmp;

	tmp = (t_mlx *)mlx;
	if (++tmp->frame_rate >= MAX_FPS)
		tmp->frame_rate = 0;
	manage_move_keys(tmp);
	draw(tmp);
	return (0);
}
