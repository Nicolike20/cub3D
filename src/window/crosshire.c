/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshire.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:13:03 by Vsavilov          #+#    #+#             */
/*   Updated: 2023/04/27 14:14:57 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	print_crosshire(t_img img, t_crosshire ch, char c)
{
	int	i;
	int	j;

	j = -1;
	if (c == 'y')
	{
		while (j < 2)
		{
			i = 0;
			while (++i < CROSSHIRE_LEN)
				mlx_put_pixel_color(img, ch.x + j, ch.y + i, ch.color);
			j++;
		}
	}
	if (c == 'x')
	{
		while (j < 2)
		{
			i = 0;
			while (++i < CROSSHIRE_LEN)
				mlx_put_pixel_color(img, ch.x + i, ch.y + j, ch.color);
			j++;
		}
	}
}

void	crosshire(t_img img)
{
	t_crosshire	chre;

	init_crosshire(&chre, 'N');
	print_crosshire(img, chre, 'y');
	init_crosshire(&chre, 'S');
	print_crosshire(img, chre, 'y');
	init_crosshire(&chre, 'W');
	print_crosshire(img, chre, 'x');
	init_crosshire(&chre, 'E');
	print_crosshire(img, chre, 'x');
}
