#include "cub3d.h"
#include <stdlib.h>

typedef struct s_vars {
    void *mlx;
    void *win;
} t_vars;

//handle keypress
int close_win(void *param)
{
    t_vars *vars = (t_vars *)param;
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
    return (0);
}

int key_hook(int keycode, void *param)
{
    t_vars *vars = (t_vars *)param;
    printf("keycode: %d\n", keycode);
    if (keycode == 65307)
        close_win(vars);
    return (0);
}
int main(void)
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    mlx_hook(vars.win, 33, 0L, close_win, &vars);
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
    return (0);
}
