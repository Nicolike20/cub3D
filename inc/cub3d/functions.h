#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structs.h"

//manage_window.c
int init_window(t_mlx *mlx);

//keys.c
int manage_keys(int keycode, t_mlx *mlx);
int key_press(int keycode, t_mlx *mlx);
int key_relase(int keycode, t_mlx *mlx);

//game_loop.c
int game_loop(void *mlx);

//draw.c
void draw(t_mlx *mlx);

//crosshire.c
void crosshire(t_img img);

//mlx_functions.c
void	mlx_put_pixel_color(t_img img, int x, int y, int color);

//mlx_memory.c
void free_mlx(t_mlx *mlx);

//utils.c
int arg_error(void);

//init.c
void init_crosshire(t_crosshire *chre, char c);

#endif
