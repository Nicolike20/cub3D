#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structs.h"

//manage_window.c
int init_window(t_mlx *mlx);

//keys.c
int manage_keys(int keycode, t_mlx *mlx);

//game_loop.c
int game_loop(void *mlx);

//mlx_memory.c
void free_mlx(t_mlx *mlx);

#endif
