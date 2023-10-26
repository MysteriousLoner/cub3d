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
    if (keycode == 13) // W
        move_player(game_vars->player, 'W');
    if (keycode == 0) // A
        move_player(game_vars->player, 'A');
    if (keycode == 1) // S
        move_player(game_vars->player, 'S');
    if (keycode == 2) // D
        move_player(game_vars->player, 'D');
    print_player(game_vars->player);
    return (0);
}

//initialize game vars
void    init_game_vars(t_cub3d *game_vars, char *argv )
{
    game_vars->mlx = mlx_init();
    game_vars->width = 600;
    game_vars->height = 600;
    game_vars->player = malloc(sizeof(t_player));
    game_vars->map = map_check(argv, game_vars);
    printf("player start: \n");
    print_player(game_vars->player);
    if (game_vars->map == NULL)
    {
        printf("MAP ERROR!\n");
        exit(0);
    }
    game_vars->win = mlx_new_window(game_vars->mlx, game_vars->width, game_vars->height, "cub3d");
    mlx_hook(game_vars->win, 17, ((1L<<17) | (1L<<19)), close_window, game_vars->mlx);
    mlx_key_hook(game_vars->win, key_handler, game_vars);
}

// garbage collector
void    free_game_vars(t_cub3d *game_vars)
{
    free(game_vars);
}

int main(int argc, char **argv)
{
    t_cub3d game_vars;

    if (argc != 2)
        return (0);
    init_game_vars(&game_vars, argv[1]);
    for_real_engine(&game_vars);
    mlx_loop(game_vars.mlx);
    // free_game_vars(game_vars);
    (void)argc;
    (void)argv;
}
