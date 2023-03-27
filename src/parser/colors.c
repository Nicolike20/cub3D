/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:57:04 by nortolan          #+#    #+#             */
/*   Updated: 2023/03/27 15:54:38 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	in_range(char **tmp)
{
	int	i;
	int	n;

	i = -1;
	while (tmp[++i])
	{
		n = ft_atoi(tmp[i]);
		if (n < 0 || n > 255)
			return (0);
	}
	return (1);
}

static int	is_alpha(char **tmp)
{
	int	i;
	int	j;

	i = -1;
	while (tmp[++i])
	{
		j = -1;
		while (tmp[i][++j])
		{
			if ((tmp[i][j] < '0' || tmp[i][j] > '9') && tmp[i][j] != ' ')
				return (0);
		}
	}
	return (1);
}

static char	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nb;
	unsigned int	len;

	len = ft_strlen(base);
	nb = nbr;
	if (nb < len)
	{
		if (base[nb] >= '0' && base[nb] <= '9')
			return (base[nb] - 48);
		return (base[nb] - 87);
	}
	else
	{
		if (base[nb % len] >= '0' && base[nb % len] <= '9')
			return (base[nb % len] - 48);
		return (base[nb % len] - 87);
	}
}

static int	arr_to_hex(char **tmp)
{
	int	result;
	int	n;

	result = 0x000000;
	n = ft_atoi(tmp[0]);
	if (n >= 16)
		result += (0x100000 * ft_putnbr_base(n / 16, "0123456789abcdef"));
	result += (0x10000 * ft_putnbr_base(n, "0123456789abcdef"));
	n = ft_atoi(tmp[1]);
	if (n >= 16)
		result += (0x1000 * ft_putnbr_base(n / 16, "0123456789abcdef"));
	result += (0x100 * ft_putnbr_base(n, "0123456789abcdef"));
	n = ft_atoi(tmp[2]);
	if (n >= 16)
		result += (0x10 * ft_putnbr_base(n / 16, "0123456789abcdef"));
	result += (0x1 * ft_putnbr_base(n, "0123456789abcdef"));
	return (result);
}

void	check_colors(t_map *vars, char *color, int check, int i)
{
	char	**tmp;

	if (color)
	{
		tmp = ft_split(color, ',');
		while (tmp[i])
			i++;
		if (i != 3 || !in_range(tmp) || !is_alpha(tmp))
		{
			write (1, "Invalid colors\n", 15);
			exit (1);
		}
		if (check)
			vars->f_hex = arr_to_hex(tmp);
		else
			vars->c_hex = arr_to_hex(tmp);
		free_tmp(tmp, i);
	}
	else
	{
		write(1, "Need color parameters\n", 22);
		exit (1);
	}
}
