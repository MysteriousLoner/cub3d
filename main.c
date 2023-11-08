#include "cub3d.h"
#include <stdlib.h>

// close_window
int close_window(t_cub3d *game_vars)
{
    mlx_destroy_window(game_vars->mlx, game_vars->win);
    // free_game_vars(game_vars);
    exit(0);
}

// returns one of the few strings based on a random number roll
char *roll()
{
    int roll;

    roll = (rand() % 5) + 1;
    if (roll == 1)
        return (ft_strdup("Bitch yo better start strippin' before I make you!\n"));
    if (roll == 2)
        return (ft_strdup("Nigga you wan some of these?\n"));
    if (roll == 3)
        return (ft_strdup("NIGGA yo better be cappin'!\n"));
    if (roll == 4)
        return (ft_strdup("Yo NIGGA we have a problem here?\n"));
    if (roll == 5)
        return (ft_strdup("NIGGA you wanna fuck with  me? \n"));
    else
        return("ft_strdup(Me speechless yo\n");
}

// key_handler
int     key_handler(int keycode, void *game_vars)
{
    t_cub3d *vars = (t_cub3d *) game_vars;
    if (keycode == KEY_ESC)
        close_window(game_vars);
    if (keycode == KEY_W) // W
        vars->key_state[0] = 1;
        // move_player(game_vars->player, game_vars->map->map, 'W');
    if (keycode == KEY_A) // A
        vars->key_state[1] = 1;
        // move_player(game_vars->player, game_vars->map->map, 'A');
    if (keycode == KEY_S) // S
        vars->key_state[2] = 1;
        // move_player(game_vars->player, game_vars->map->map, 'S');
    if (keycode == KEY_D) // D
        vars->key_state[3] = 1;
        // move_player(game_vars->player, game_vars->map->map, 'D');
    // for_real_engine(vars);
    if (vars->key_state[0])
        move_player(vars->player, vars->map->map, 'W');
    if (vars->key_state[1])
        move_player(vars->player, vars->map->map, 'A');
    if (vars->key_state[2])
        move_player(vars->player, vars->map->map, 'S');
    if (vars->key_state[3])
        move_player(vars->player, vars->map->map, 'D');
    if (keycode == KEY_SPACE)
    {
        if (ft_strncmp(vars->mc_path, "mc/mc2.xpm", 10) == 0)
        {
            vars->mc_path = ft_strdup("mc/mc.xpm");
            vars->bs = roll();
            vars->bsf = 1;
        }
        else
        {
            vars->mc_path = ft_strdup("mc/mc2.xpm");
            vars->bsf = 0;
        }
    }
    for_real_engine(vars);
    if (vars->bsf)
        mlx_string_put(vars->mlx, vars->win, WIDTH / 2 - 50, HEIGHT / 2, 0x000000, vars->bs);
    // init_graphics(game_vars);
    return (0);
}

int    key_release_handler(int keycode, void *game_vars)
{
    t_cub3d *vars = (t_cub3d *) game_vars;
    if (keycode == KEY_W)
        vars->key_state[0] = 0;
    if (keycode == KEY_A)
        vars->key_state[1] = 0;
    if (keycode == KEY_S)
        vars->key_state[2] = 0;
    if (keycode == KEY_D)
        vars->key_state[3] = 0;
    if (vars->key_state[0])
        move_player(vars->player, vars->map->map, 'W');
    if (vars->key_state[1])
        move_player(vars->player, vars->map->map, 'A');
    if (vars->key_state[2])
        move_player(vars->player, vars->map->map, 'S');
    if (vars->key_state[3])
        move_player(vars->player, vars->map->map, 'D');
    return (0);
}
//initialize game vars
void    init_game_vars(t_cub3d *game_vars, char *argv )
{
    int   i;
    i = 0;
    game_vars->mlx = mlx_init();
    game_vars->width = WIDTH;
    game_vars->height = HEIGHT;
    game_vars->player = malloc(sizeof(t_player));
    game_vars->bs = 0;
    game_vars->bsf = 0;
    game_vars->map = map_check(argv, game_vars);
    game_vars->mc_path = ft_strdup("mc/mc2.xpm");
    while (i < 4)
    {
        game_vars->key_state[i] = 0;
        i++;
    }
    if (game_vars->map == NULL)
    {
        printf("MAP ERROR!\n");
        exit(0);
    }
    game_vars->win = mlx_new_window(game_vars->mlx, game_vars->width, game_vars->height, "cub3d");
    mlx_hook(game_vars->win, 2, 0, key_handler, game_vars);
    mlx_hook(game_vars->win, 3, 0, key_release_handler, game_vars);
    mlx_hook(game_vars->win, BUTTON_X, ((1L<<17) | (1L<<19)), close_window, game_vars);
    // mlx_key_hook(game_vars->win, key_handler, game_vars);
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
    init_graphics(&game_vars);
    // for_real_engine(&game_vars);
    mlx_loop(game_vars.mlx);
    // free_game_vars(game_vars);
    (void)argc;
    (void)argv;
}
