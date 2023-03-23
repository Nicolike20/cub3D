/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:57:04 by nortolan          #+#    #+#             */
/*   Updated: 2023/03/23 13:59:21 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

//TODO: limpiar codigo de arr_to_hex (usar vars, por ejemplo?);

int     in_range(char **tmp)
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

void    free_tmp(char **tmp, int i)
{
	while (--i >= 0)
		free(tmp[i]);
	free(tmp);
}

int     is_alpha(char **tmp)
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

char    ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nb;
	unsigned int	len;

	len = ft_strlen(base);
	nb = nbr;
	if (nb < len)
	{
		ft_putchar_fd(base[nb], 1); //quitar
		printf("\nbase[nb] if: %c\n", base[nb]); //quitar
		return (base[nb]);
	}
	else
	{
		ft_putnbr_base(nb / len, base);
		ft_putchar_fd(base[nb % len], 1); //quitar
		printf("\nbase[nb] else: %c\n", base[nb % len]); //quitar
		return (base[nb % len]);
	}
}

char	*arr_to_hex(t_map *vars, char **tmp)
{
	char	*result;
	int		n;
	int		i;

	i = 0;
	result = ft_strdup("000000");
	n = ft_atoi(tmp[0]);
	if (n < 16)
		i++;
	else
		result[i++] = ft_putnbr_base(n / 16, "0123456789abcdef");
	result[i++] = ft_putnbr_base(n, "0123456789abcdef");
	n = ft_atoi(tmp[1]);
	if (n < 16)
		i++;
	else
		result[i++] = ft_putnbr_base(n / 16, "0123456789abcdef");
	result[i++] = ft_putnbr_base(n, "0123456789abcdef");
	n = ft_atoi(tmp[2]);
	if (n < 16)
		i++;
	else
		result[i++] = ft_putnbr_base(n / 16, "0123456789abcdef");
	result[i++] = ft_putnbr_base(n, "0123456789abcdef");
	printf ("\nresult: %s\npirateo: %s\n", result, vars->no); //free result?;
/*	if (check)
		vars->f_hex = ft_strdup(result);
	else
		vars->c_hex = ft_strdup(result);*/
	return (result);
}

void    check_colors(t_map *vars, char *color, int check)
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
		if (i != 3 || !in_range(tmp) || !is_alpha(tmp))
		{
			write (1, "Invalid colors\n", 15);
			exit (1);
		}
		//free (color);
		if (check)
			vars->f_hex = ft_strdup(arr_to_hex(vars, tmp));
		else
			vars->c_hex = ft_strdup(arr_to_hex(vars, tmp));
		free_tmp(tmp, i);
	}
}
