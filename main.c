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
    if (keycode == KEY_ESC)
        close_window(game_vars);
    if (keycode == KEY_W) // W
        move_player(game_vars->player, game_vars->map->map, 'W');
    if (keycode == KEY_A) // A
        move_player(game_vars->player, game_vars->map->map, 'A');
    if (keycode == KEY_S) // S
        move_player(game_vars->player, game_vars->map->map, 'S');
    if (keycode == KEY_D) // D
        move_player(game_vars->player, game_vars->map->map, 'D');
    for_real_engine(game_vars);
    render_wall('N', 1200, game_vars, 0);
    // init_graphics(game_vars);
    return (0);
}

//initialize game vars
void    init_game_vars(t_cub3d *game_vars, char *argv )
{
    game_vars->mlx = mlx_init();
    game_vars->width = WIDTH;
    game_vars->height = HEIGHT;
    game_vars->player = malloc(sizeof(t_player));
    game_vars->map = map_check(argv, game_vars);
    if (game_vars->map == NULL)
    {
        printf("MAP ERROR!\n");
        exit(0);
    }
    game_vars->win = mlx_new_window(game_vars->mlx, game_vars->width, game_vars->height, "cub3d");
    mlx_hook(game_vars->win, BUTTON_X, ((1L<<17) | (1L<<19)), close_window, game_vars);
    mlx_key_hook(game_vars->win, key_handler, game_vars);
}

// garbage collector
void    free_game_vars(t_cub3d *game_vars)
{
    free(game_vars);
}

void    init_texture(t_cub3d *vars)
{
    vars->north = malloc(sizeof(t_image));
	vars->north->addr = mlx_xpm_file_to_image(vars->mlx, vars->map->NO, (int *)400, (int *)400);
	vars->north->img = mlx_get_data_addr(vars->north->addr, (int *)400, (int *)400, (int *)400);
}

int main(int argc, char **argv)
{
    t_cub3d game_vars;

    if (argc != 2)
        return (0);
    init_game_vars(&game_vars, argv[1]);
    init_texture(&game_vars);
    init_graphics(&game_vars);
    // for_real_engine(&game_vars);
    mlx_loop(game_vars.mlx);
    // free_game_vars(game_vars);
    (void)argc;
    (void)argv;
}
