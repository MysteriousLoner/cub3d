/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:05:56 by yalee             #+#    #+#             */
/*   Updated: 2023/11/09 19:15:40 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// returns one of the few strings based on a random number roll
char	*roll(void)
{
	int	roll;

	roll = (rand() % 5) + 1;
	if (roll == 1)
		return (ft_strdup("Bitchyo better start strippin'beforeI make you!\n"));
	if (roll == 2)
		return (ft_strdup("Nigga you wan some of these?\n"));
	if (roll == 3)
		return (ft_strdup("NIGGA yo better be cappin'!\n"));
	if (roll == 4)
		return (ft_strdup("Yo NIGGA we have a problem here?\n"));
	if (roll == 5)
		return (ft_strdup("NIGGA yiu wanna fuck with  me? \n"));
	else
		return (ft_strdup("Me speechless yo\n"));
}

// key_handler
void	player_action(t_cub3d *vars, int keycode)
{
	if (vars->key_state[0])
		move_player(vars->player, vars->map->map, 'W');
	if (vars->key_state[1])
		move_player(vars->player, vars->map->map, 'A');
	if (vars->key_state[2])
		move_player(vars->player, vars->map->map, 'S');
	if (vars->key_state[3])
		move_player(vars->player, vars->map->map, 'D');
}

void	space(t_cub3d *vars)
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

int	key_handler(int keycode, void *game_vars)
{
	t_cub3d	*vars;

	vars = (t_cub3d *) game_vars;
	if (keycode == KEY_ESC)
		close_window(game_vars);
	if (keycode == KEY_W)
		vars->key_state[0] = 1;
	if (keycode == KEY_A)
		vars->key_state[1] = 1;
	if (keycode == KEY_S)
		vars->key_state[2] = 1;
	if (keycode == KEY_D)
		vars->key_state[3] = 1;
	player_action(vars, keycode);
	if (keycode == KEY_SPACE)
		space(vars);
	for_real_engine(vars);
	if (vars->bsf)
		mlx_string_put(vars->mlx, vars->win, WIDTH
			/ 2 - 50, HEIGHT / 2, 0xFF0000, vars->bs);
	return (0);
}

int	key_release_handler(int keycode, void *game_vars)
{
	t_cub3d	*vars;

	vars = (t_cub3d *) game_vars;
	if (keycode == KEY_W)
		vars->key_state[0] = 0;
	if (keycode == KEY_A)
		vars->key_state[1] = 0;
	if (keycode == KEY_S)
		vars->key_state[2] = 0;
	if (keycode == KEY_D)
		vars->key_state[3] = 0;
	player_action(vars, keycode);
	for_real_engine(vars);
	if (vars->bsf)
		mlx_string_put(vars->mlx, vars->win, WIDTH
			/ 2 - 50, HEIGHT / 2, 0xFF0000, vars->bs);
	return (0);
}
