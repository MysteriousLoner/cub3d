/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:24:29 by yalee             #+#    #+#             */
/*   Updated: 2023/11/09 18:24:56 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_sky(t_cub3d *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < vars->height * 0.5)
	{
		while (x < vars->width)
		{
			put_pixel(vars, x, y, rgb_to_int(vars->map->ceiling->r,
					vars->map->ceiling->g, vars->map->ceiling->b));
			x++;
		}
		x = 0;
		y++;
	}
}

void	render_earth(t_cub3d *vars)
{
	int	x;
	int	y;

	x = 0;
	y = vars->height * 0.5;
	while (y < vars->height)
	{
		while (x < vars->width)
		{
			put_pixel(vars, x, y, rgb_to_int(vars->map->floor->r,
					vars->map->floor->g, vars->map->floor->b));
			x++;
		}
		x = 0;
		y++;
	}
}
