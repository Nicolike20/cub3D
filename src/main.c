/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:58:25 by nortolan          #+#    #+#             */
/*   Updated: 2022/12/21 01:45:12 by nortolan         ###   ########.fr       */
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
	t_map	vars;

	if (argc != 2)
	{
		write (1, "Wrong number of arguments. Only one map expected\n", 49);
		return (1);
	}
	if (check_file(argv[1]))
		return (1);
	vars = vars_init(&vars);
	file_read(argv[1], &vars);
	return (0);
}
