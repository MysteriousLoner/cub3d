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
    printf("%d\n", roll);
    if (roll == 1)
        return (ft_strdup("Bitch yo better start strippin' before I make you!\n"));
    if (roll == 2)
        return (ft_strdup("Nigga you wan some of these?\n"));
    if (roll == 3)
        return (ft_strdup("NIGGA yo better be cappin'!\n"));
    if (roll == 4)
        return (ft_strdup("Yo NIGGA we have a problem here?\n"));
    if (roll == 5)
        return (ft_strdup("NIGGA yiu wanna fuck with  me? \n"));
    else
        return("ft_strdup(Me speechless yo\n");
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
    if (keycode == KEY_SPACE)
    {
        if (ft_strncmp(game_vars->mc_path, "mc/mc2.xpm", 10) == 0)
        {
            game_vars->mc_path = ft_strdup("mc/mc.xpm");
            game_vars->bs = roll();
            game_vars->bsf = 1;
        }
        else
        {
            game_vars->mc_path = ft_strdup("mc/mc2.xpm");
            game_vars->bsf = 0;
        }
    }
    for_real_engine(game_vars);
    if (game_vars->bsf)
        mlx_string_put(game_vars->mlx, game_vars->win, WIDTH / 2 - 50, HEIGHT / 2, 0x000000, game_vars->bs);
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
    game_vars->bs = 0;
    game_vars->bsf = 0;
    game_vars->map = map_check(argv, game_vars);
    game_vars->mc_path = ft_strdup("mc/mc2.xpm");
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
