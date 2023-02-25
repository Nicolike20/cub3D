#include <cub3d.h>

int arg_error(void)
{
	ft_putstr_fd("Error: Only one map expected: Usage: ./cub3D [map]\n", 2);
	return (1);
}
