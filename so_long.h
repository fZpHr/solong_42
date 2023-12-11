#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

typedef struct s_global
{
    int     img_x = 0;
    int     img_y = 0;
	int     img_player_x = 250; 
    int     img_player_y = 250; 
    void    *background_ptr;
    void    *player_ptr_s1;
    void    *player_ptr_s2;
    void    *player_ptr_s3;
    void    *player_ptr_s4;
    void    *player_ptr_s5;
    void    *player_ptr_w1;
    void    *player_ptr_w2;
    void    *player_ptr_w3;
    void    *player_ptr_w4;
    void    *player_ptr_w5;
    void    *player_ptr_d1;
    void    *player_ptr_d2;
    void    *player_ptr_d3;
    void    *player_ptr_d4;
    void    *player_ptr_d5;
    void    *player_ptr_a1;
    void    *player_ptr_a2;
    void    *player_ptr_a3;
    void    *player_ptr_a4;
    void *player_ptr_a5;
    void *win_ptr;
    void *mlx_ptr;
    static int  j = 0;
    int window_width = 845; 
    int window_height = 600; 
    int	width = 10;
    int	height = 10;
}				t_global;

#endif
