#include "cub3d.h"
#include <stdlib.h>

// close_window
int close_window(t_cub3d *game_vars)
{
    mlx_destroy_window(game_vars->mlx, game_vars->win);
    // free_game_vars(game_vars);
    exit(0);
}
// key_handler
int     key_handler(int keycode, t_cub3d *game_vars)
{
    printf("keycode: %d\n", keycode);
    if (keycode == 53)
        close_window(game_vars);
    return (0);
}

//initialize game vars
void    init_game_vars(t_cub3d *game_vars)
{
    // game_vars = malloc(sizeof(t_cub3d));
    game_vars->mlx = mlx_init();
    game_vars->win = mlx_new_window(game_vars->mlx, 640, 480, "cub3d");
    mlx_hook(game_vars->win, 17, ((1L<<17) | (1L<<19)), close_window, game_vars->mlx);
    mlx_key_hook(game_vars->win, key_handler, game_vars);
    mlx_loop(game_vars->mlx);
}

// garbage collector
void    free_game_vars(t_cub3d *game_vars)
{
    free(game_vars);
}

int main(int argc, char **argv)
{
    t_cub3d game_vars;

    init_game_vars(&game_vars);
    // free_game_vars(game_vars);
    (void)argc;
    (void)argv;
}
