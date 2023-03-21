/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:57:04 by nortolan          #+#    #+#             */
/*   Updated: 2023/03/21 20:25:40 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	in_range(char **tmp)
{
	int	i;
	int	n;

	i = -1;
	while (tmp[++i])
	{
		n = ft_atoi(tmp[i]);
		printf ("test atoi: %d\n", n);
		if (n < 0 || n > 255)
			return (0);
	}
	return (1);
}

void	free_tmp(char **tmp, int i)
{
	while (--i >= 0)
		free(tmp[i]);
	free(tmp);
}

void	check_colors(char *color)
{
	char	**tmp;
	int		i;

	i = 0;
	if (color)
	{
		tmp = ft_split(color, ',');
		while (tmp[i])
			i++;
		printf("test i: %d\n", i);
		if (i != 3 || !in_range(tmp))
		{
			write (1, "Invalid colors\n", 15);
			exit (1);
		}
		free_tmp(tmp, i);
	}
}
