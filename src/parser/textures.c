/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:39:30 by nortolan          #+#    #+#             */
/*   Updated: 2023/03/27 15:52:59 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	load_image(t_mlx *mlx, t_tex *tex, char *path)
{
	if (path == NULL)
	{
		write (1, "Texture path is null\n", 21);
		exit (1);
	}
	tex->img.img = mlx_xpm_file_to_image(mlx->mlx, path, &tex->tw, &tex->th);
	if (tex->img.img == NULL)
	{
		write (1, "Failed to load textures\n", 24);
		exit (1);
	}
	tex->img.addr = mlx_get_data_addr(tex->img.img, &tex->img.bpp,
			&tex->img.ln_len, &tex->img.endian);
	if (tex->img.addr == NULL)
	{
		write (1, "Failed to get image address\n", 28);
		exit (1);
	}
	printf("img loaded with texture: '%s'\n", path);
}

void	loading_textures(t_mlx *mlx)
{
	load_image(mlx, &mlx->tex[T_NORTH], mlx->map->no);
	load_image(mlx, &mlx->tex[T_SOUTH], mlx->map->so);
	load_image(mlx, &mlx->tex[T_WEST], mlx->map->we);
	load_image(mlx, &mlx->tex[T_EAST], mlx->map->ea);
	load_image(mlx, &mlx->tex[T_DOOR], mlx->map->d);
}
