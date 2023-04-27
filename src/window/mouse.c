/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:57:27 by Vsavilov          #+#    #+#             */
/*   Updated: 2023/04/27 14:57:28 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	handle_mouse(int x, int y, t_mlx *mlx)
{
	float	dis;

	(void)y;
	mlx->prev_x = mlx->mouse_x;
	mlx->mouse_x = x;
	dis = (float)mlx->mouse_x - (float)mlx->prev_x;
	if (mlx->keys.mouse == TRUE)
	{
		if (dis > 0)
			fpp_camera(KEY_RIGHT, mlx, fabs(dis) / (float)MOUSE_SPEED);
		else
			fpp_camera(KEY_LEFT, mlx, fabs(dis) / (float)MOUSE_SPEED);
	}
	return (0);
}

void	input_mouse(t_mlx *mlx)
{
	if (mlx->keys.mouse == TRUE)
		mlx->keys.mouse = FALSE;
	else
		mlx->keys.mouse = TRUE;
}
