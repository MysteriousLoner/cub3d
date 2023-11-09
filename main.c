/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:30:49 by yalee             #+#    #+#             */
/*   Updated: 2023/11/09 18:55:57 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

// close_window
int	close_window(t_cub3d *game_vars)
{
	mlx_destroy_window(game_vars->mlx, game_vars->win);
	exit(0);
}

//initialize game vars
void	init_game_vars(t_cub3d *gv, char *argv )
{
	int	i;

	i = 0;
	gv->mlx = mlx_init();
	gv->width = WIDTH;
	gv->height = HEIGHT;
	gv->player = malloc(sizeof(t_player));
	gv->bs = 0;
	gv->bsf = 0;
	gv->mc_path = ft_strdup("mc/mc2.xpm");
	if (!map_check(argv, gv))
	{
		printf("MAP ERROR!\n");
		exit(0);
	}
	while (i < 4)
	{
		gv->key_state[i] = 0;
		i++;
	}
	gv->win = mlx_new_window(gv->mlx, gv->width,
			gv->height, "cub3d");
	mlx_hook(gv->win, 2, 0, key_handler, gv);
	mlx_hook(gv->win, 3, 0, key_release_handler, gv);
	mlx_hook(gv->win, BUTTON_X, ((1L << 17) | (1L << 19)), close_window, gv);
}

// garbage collector
void	free_game_vars(t_cub3d *game_vars)
{
	free(game_vars);
}

int	main(int argc, char **argv)
{
	t_cub3d	game_vars;

	if (argc != 2)
		return (0);
	init_game_vars(&game_vars, argv[1]);
	texture_init(&game_vars);
	init_graphics(&game_vars);
	mlx_loop(game_vars.mlx);
	(void)argc;
	(void)argv;
}
