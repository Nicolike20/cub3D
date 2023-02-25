/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:58:25 by nortolan          #+#    #+#             */
/*   Updated: 2023/02/25 19:56:46 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/*void	leaks(void)
{
	system("leaks -q cub3D");
}
	atexit(leaks);*/

static void fill_map(t_map *map) {
	map->map = (char **)malloc(sizeof(char *) * 6);
	map->map[0] = ft_strdup("111111");
	map->map[1] = ft_strdup("100101");
	map->map[2] = ft_strdup("100101");
	map->map[3] = ft_strdup("1100N1");
	map->map[4] = ft_strdup("111001");
	map->map[5] = ft_strdup("111111");
	
	for (int i = 0; i < 6; i++) {
		printf("%s\n", map->map[i]);
	}
}

int	main(int argc, char **argv)
{
	t_mlx *mlx = (t_mlx *)malloc(sizeof(t_mlx) * 10);
	t_map *map = (t_map *)malloc(sizeof(t_map) * 500);
	mlx->map = map;

	if (argc != 2)
		return (arg_error());
	fill_map(mlx->map);
	/*if (check_file(argv[1]))
		return (1);
	file_read(argv[1], mlx->map);*/
	(void)argv;
	init_window(mlx);

	return (0);
}
