/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:58:25 by nortolan          #+#    #+#             */
/*   Updated: 2023/03/27 15:57:57 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

//TODO: puertas;
//TODO: quitar comments y printfs
//TODO: si hay puerta pero no textura / si hay textura pero no puertas?;
//TODO: check leaks;

/*void	leaks(void)
{
	system("leaks -q cub3D");
}
	atexit(leaks);*/

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (arg_error());
	if (check_file(argv[1]))
		return (1);
	t_mlx *mlx = (t_mlx *)malloc(sizeof(t_mlx) * 10);
	if (mlx == NULL)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	mlx->map = (t_map *)malloc(sizeof(t_map));
	if (mlx->map == NULL)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	vars_init(mlx->map);
	file_read(argv[1], mlx->map);
	freedom (mlx->map);
	init_window(mlx);
	return (0);
}
