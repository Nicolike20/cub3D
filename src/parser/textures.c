/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:39:30 by nortolan          #+#    #+#             */
/*   Updated: 2023/03/18 19:17:23 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

//check si el path es null;
//proteger por si falla la funcion mlx_xpm_file_to_image;
//como usar ahora estas texturas en vez de colores?
//esto sta bien hecho?; lol
void	load_image(t_mlx *mlx, t_tex *tex, char *path)
{
	if (path == NULL)
	{
		write (1, "Texture path is null\n", 21);
		exit (1);
	}
	if (!(tex->img.img = mlx_xpm_file_to_image(mlx, path, &tex->tw, &tex->th)))
	{
		write (1, "Failed to load textures\n", 24);
		exit (1);
	}
	if (!(tex->img.addr = mlx_get_data_addr(tex->img.img, &tex->img.bpp, &tex->img.ln_len, &tex->img.endian)))
	{
		write (1, "Failed to get image address\n", 28);
		exit (1);
	}
	printf("img loaded with texture: '%s'\n", path);
}
void	loading_textures(t_mlx *mlx, t_map *vars)
{
	mlx->tex = (t_tex *)malloc(sizeof(t_tex) * 5);
//	printf("test vars->no: %s\n", vars->no);
	load_image(mlx, &mlx->tex[T_NORTH], vars->no);
	load_image(mlx, &mlx->tex[T_SOUTH], vars->so);
	load_image(mlx, &mlx->tex[T_WEST], vars->we);
	load_image(mlx, &mlx->tex[T_EAST], vars->ea);
	load_image(mlx, &mlx->tex[T_DOOR], vars->d);

//	load_image(mlx, &vars->texture[0], "textures/custom/blue_bricks.xpm");
	//mlx->tex = vars->texture;
}
