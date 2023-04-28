/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:58:25 by nortolan          #+#    #+#             */
/*   Updated: 2023/04/28 18:30:43 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		return (put_error("Error: malloc.\n", 2));
	if (argc != 2)
		return (arg_error());
	if (check_file(argv[1]))
		return (1);
	mlx->map = (t_map *)malloc(sizeof(t_map));
	if (mlx->map == NULL)
		return (put_error("Error: malloc.\n", 2));
	vars_init(mlx->map);
	file_read(argv[1], mlx->map);
//	loading_textures(mlx, mlx->map);
	freedom (mlx->map);
	init_window(mlx);
	return (0);
}
