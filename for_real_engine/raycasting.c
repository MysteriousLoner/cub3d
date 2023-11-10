/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:37:59 by yalee             #+#    #+#             */
/*   Updated: 2023/11/10 23:39:57 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_rays(t_cub3d *vars, t_player *player, t_raycasting_vars *ray_vars)
{
		ray_vars->disth = 10000000000;
		ray_vars->distv = 10000000000;
		ray_vars->hx = player->x;
		ray_vars->hy = player->y;
		ray_vars->vx = player->x;
		ray_vars->vy = player->y;
}

void	calculate_and_render_wall(t_cub3d *v, t_player *p,
	t_raycasting_vars *rv)
{
	if (rv->disth < rv->distv)
	{
		rv->rx = rv->hx;
		rv->ry = rv->hy;
		if (rv->ra > PI)
			rv->dimg = v->south;
		if (rv->ra < PI)
			rv->dimg = v->north;
		rv->d = 'h';
		drawwalls(v, rv->r, rv->disth * cos(norm_angle(p->angle - rv->ra)), rv);
	}
	if (rv->distv < rv->disth)
	{
		rv->rx = rv->vx;
		rv->ry = rv->vy;
		if (rv->ra > (PI / 2) && rv->ra < (3 * PI / 2))
			rv->dimg = v->west;
		else if (rv->ra < (PI / 2) || rv->ra > (3 * PI / 2))
			rv->dimg = v->east;
		rv->d = 'v';
		drawwalls(v, rv->r, rv->distv * cos(norm_angle(p->angle - rv->ra)), rv);
	}
	p->lov = rv->ra;
	draw_line_to_point(v, rv->rx, rv->ry, p);
}

void	render_walls(t_cub3d *vars, t_player *player)
{
	t_raycasting_vars	*ray_vars;
	int					flag;

	flag = 0;
	ray_vars = malloc(sizeof(t_raycasting_vars));
	ray_vars->ra = norm_angle(player->angle - DG * 30);
	ray_vars->r = 0;
	while (ray_vars->r < 600)
	{
		init_rays(vars, player, ray_vars);
		check_horizontal(ray_vars, vars, player);
		check_vertical(ray_vars, vars, player);
		calculate_and_render_wall(vars, player, ray_vars);
		ray_vars->r++;
		ray_vars->ra = norm_angle(ray_vars->ra + 1.0472 / 600);
	}
}
