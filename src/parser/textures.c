/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:39:30 by nortolan          #+#    #+#             */
/*   Updated: 2023/03/10 20:48:53 by Vsavilov         ###   ########.fr       */
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
}
void	loading_textures(t_mlx *mlx, t_map *vars)
{
	load_image(mlx, &vars->texture[0], "textures/wall_1.xpm");
	printf("img loaded\n");
	mlx->tex = vars->texture;
	//load_image(mlx, &vars->texture[1], vars->so);
	//load_image(mlx, &vars->texture[2], vars->we);
	//load_image(mlx, &vars->texture[3], vars->ea);
	//load_image(mlx, &vars->texture[4], vars->d);
	//load_image(texture[4], texture[4]->tw. texture[4]->th, vars->no);
}
