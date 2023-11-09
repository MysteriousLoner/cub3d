/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:30:20 by yalee             #+#    #+#             */
/*   Updated: 2023/11/09 19:12:16 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	compute_colour(t_cub3d *vars, int y, float dist,
	t_raycasting_vars *ray_vars)
{
	int		color;
	float	px;
	float	py;
	char	*pixel;

	if (ray_vars->d == 'h')
		px = ray_vars->rx - (int)ray_vars->rx;
	if (ray_vars->d == 'v')
		px = ray_vars->ry - (int)ray_vars->ry;
	py = (y - ((HEIGHT / 2) - (HEIGHT / dist))) / (HEIGHT / dist)
		* ray_vars->dimg->height / 2;
	pixel = ray_vars->dimg->addr + ((int)py * ray_vars->dimg->line_length
			+ (int)(px * ray_vars->dimg->width) * (ray_vars->dimg->bpp / 8));
	color = mlx_get_color_value(vars->mlx, *(int *) pixel);
	return (color);
}

void	drawWalls(t_cub3d *vars, int r, float dist,
	t_raycasting_vars *ray_vars)
{
	int		x;
	int		y;
	float	line_h;
	int		color;
	char	*pixel;

	line_h = (HEIGHT / dist);
	if (line_h > HEIGHT)
		line_h = HEIGHT;
	x = r * 3;
	while (x < ((r + 1) * 3))
	{
		y = (HEIGHT / 2) - (line_h / 2);
		while (y < ((HEIGHT / 2) + (line_h / 2)))
		{
			color = compute_colour(vars, y, dist, ray_vars);
			put_pixel(vars, x, y, color);
			y++;
		}
		x++;
	}
}
