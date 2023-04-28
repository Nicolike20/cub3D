/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:46:21 by vsavilov          #+#    #+#             */
/*   Updated: 2023/04/27 14:09:30 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	put_error(char *s, int e)
{
	ft_putstr_fd(s, 2);
	return (e);
}

int	arg_error(void)
{
	ft_putstr_fd("Error: Only one map expected: Usage: ./cub3D [map]\n", 2);
	return (1);
}
