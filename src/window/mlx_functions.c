/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:49:49 by vsavilov          #+#    #+#             */
/*   Updated: 2023/03/09 19:49:49 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	mlx_put_pixel_color(t_img img, int x, int y, int color)
{
	int	pixel;

	if (y >= WIN_H || x >= WIN_W || x < 0 || y < 0)
		return ;
	pixel = y * img.ln_len + x * (img.bpp / 8);
	if (img.endian == 0)
	{
		img.addr[pixel + 0] = (color) & 0xFF;
		img.addr[pixel + 1] = (color >> 8) & 0xFF;
		img.addr[pixel + 2] = (color >> 16) & 0xFF;
		img.addr[pixel + 3] = (color >> 24);
	}
	else if (img.endian == 1)
	{
		img.addr[pixel + 0] = (color >> 24);
		img.addr[pixel + 1] = (color >> 16) & 0xFF;
		img.addr[pixel + 2] = (color >> 8) & 0xFF;
		img.addr[pixel + 3] = (color) & 0xFF;
	}
}
