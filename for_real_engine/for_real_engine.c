/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_real_engine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:37:52 by yalee             #+#    #+#             */
/*   Updated: 2023/11/11 02:50:18 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_line_to_point(t_cub3d *vars, float x, float y, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	j = (sqrt(pow(fabs(player->x - x), 2) + pow(fabs(player->y - y), 2)))
		* vars->size;
	while (i < j)
	{
		put_pixel(vars, (player->x * vars->size + i * cos(player->lov)),
			(player->y * vars->size + i * sin(player->lov)),
			rgb_to_int(255, 0, 0));
		i++;
	}
}

void	init_screen(t_cub3d *vars)
{
	vars->screen = (t_image *)malloc(sizeof(t_image));
	vars->screen->img = mlx_new_image(vars->mlx, vars->width, vars->height);
	vars->screen->addr = mlx_get_data_addr(vars->screen->img,
			&vars->screen->bpp, &vars->screen->line_length,
			&vars->screen->endian);
}

void	init_mc(t_cub3d *vars)
{
	vars->mc = (t_image *)malloc(sizeof(t_image));
	vars->mc->img = mlx_xpm_file_to_image(vars->mlx, vars->mc_path,
			&vars->mc->width, &vars->mc->height);
	vars->mc->addr = mlx_get_data_addr(vars->mc->img, &vars->mc->bpp,
			&vars->mc->line_length, &vars->mc->endian);
}

void	init_graphics(t_cub3d *vars)
{
	init_screen(vars);
	init_mc(vars);
	render_sky(vars);
	render_earth(vars);
	render_walls(vars, vars->player);
	render_minimap(vars->width * 0.40, vars->height * 0.40, vars);
	render_player(vars, vars->size, vars->player);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->screen->img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->mc->img,
		vars->width * 0.30, vars->height - 400);
}

void	for_real_engine(t_cub3d *vars)
{
	free(vars->mc);
	init_mc(vars);
	render_sky(vars);
	render_earth(vars);
	render_minimap(vars->width * 0.40, vars->height * 0.40, vars);
	render_player(vars, vars->size, vars->player);
	render_walls(vars, vars->player);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->screen->img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->mc->img, vars->width
		* 0.30, vars->height - 400);
}
