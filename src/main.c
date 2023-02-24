/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:58:25 by nortolan          #+#    #+#             */
/*   Updated: 2023/02/24 15:02:47 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/*void	leaks(void)
{
	system("leaks -q cub3D");
}
	atexit(leaks);*/

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write (1, "Wrong number of arguments. Only one map expected\n", 49);
		return (1);
	}
	/*if (check_file(argv[1]))
		return (1);
	file_read(argv[1]);*/
	(void)argv;
	t_mlx *mlx = (t_mlx *)malloc(sizeof(t_mlx));

	init_window(mlx);

	return (0);
}
