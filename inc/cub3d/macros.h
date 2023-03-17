/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:41:34 by vsavilov          #+#    #+#             */
/*   Updated: 2023/03/17 13:52:10 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define NAME "Cube3D"

//Colours

# define WHITE 0xFFFFFF
# define SILVER 0xC0C0C0
# define RED 0xFF0000
# define PURPLE 0x800080
# define FUCHSIA 0xFF00FF
# define LIME 0x00FF00
# define YELLOW 0xFFFF00
# define BLUE 0x0000FF
# define CYAN 0x00FFFF

# define FALSE 0
# define TRUE 1

# define CROSSHIRE_LEN 8

# define MINIMAP_SCALE 8

/* Window size */

# ifndef WIN_W
#  define WIN_W 1280
# endif

# ifndef WIN_H
#  define WIN_H 720
# endif

# ifndef MAX_FPS
#  define MAX_FPS 60
# endif

/* Map macros */

# define FLOOR '0'
# define WALL '1'
# define DOOR 'D'
# define DOPEN 'O'
# define DCLOSE 'C'

# define T_MAX 64.0

/* Texture oriantation*/

# define T_NORTH 0
# define T_SOUTH 1
# define T_WEST 2
# define T_EAST 3
# define T_DOOR 4

/* Movement */

# define SPEED 0.05
# define FPP_CAM_SPEED 0.03

/* Keys */

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_O 31
# define KEY_U 32
# define KEY_I 34
# define KEY_P 35
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_N 45
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_SHIFT 257

#endif
