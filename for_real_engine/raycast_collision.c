/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_collision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:39:44 by yalee             #+#    #+#             */
/*   Updated: 2023/11/09 18:19:51 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_horizontal(t_raycasting_vars *ray_vars, t_cub3d *vars,
	t_player *player)
{
	ray_vars->dof = 0;
	ray_vars->aTan = -1 / tan(ray_vars->ra);
	if (ray_vars->ra > PI)
	{
		ray_vars->ry = (int) player->y - 0.0001;
		ray_vars->rx = (player->y - ray_vars->ry) * ray_vars->aTan + player->x;
		ray_vars->yo = -1;
		ray_vars->xo = -ray_vars->yo * ray_vars->aTan;
	}
	if (ray_vars->ra < PI)
	{
		ray_vars->ry = (int)player->y + 1;
		ray_vars->rx = (player->y - ray_vars->ry) * ray_vars->aTan + player->x;
		ray_vars->yo = 1;
		ray_vars->xo = -ray_vars->yo * ray_vars->aTan;
	}
	if (ray_vars->ra == 0 || ray_vars->ra == PI)
	{
		ray_vars->rx = player->x;
		ray_vars->ry = player->y;
		ray_vars->dof = longest_d(vars->map->map);
	}
}

void	check_horizontal(t_raycasting_vars *rv, t_cub3d *vars,
	t_player *player)
{
	init_horizontal(rv, vars, player);
	while (rv->dof < 20)
	{
		rv->mx = (int) rv->rx >> 0;
		rv->my = (int) rv->ry >> 0 ;
		if (rv->mx < 0 || rv->my < 0 || rv->mx
			> longest_row(vars->map->map) || rv->my
			> map_height(vars->map->map))
			rv->dof = longest_d(vars->map->map);
		if (rv->dof < longest_d(vars->map->map)
			&& vars->map->map[rv->my][rv->mx] == '1')
		{
			rv->hx = rv->rx;
			rv->hy = rv->ry;
			rv->distH = dist(player->x, player->y, rv->hx, rv->hy);
			rv->dof = longest_d(vars->map->map);
		}
		else
		{
			rv->rx += rv->xo;
			rv->ry += rv->yo;
			rv->dof += 1;
		}
	}
}

void	init_vertical(t_raycasting_vars *ray_vars, t_cub3d *vars,
	t_player *player)
{
	ray_vars->dof = 0;
	ray_vars->nTan = -1 * tan(ray_vars->ra);
	if (ray_vars->ra > (PI / 2) && ray_vars->ra < (3 * PI / 2))
	{
		ray_vars->rx = (int) player->x - 0.0001;
		ray_vars->ry = (player->x - ray_vars->rx) * ray_vars->nTan + player->y;
		ray_vars->xo = -1;
		ray_vars->yo = -ray_vars->xo * ray_vars->nTan;
	}
	if (ray_vars->ra < (PI / 2) || ray_vars->ra > (3 * PI / 2))
	{
		ray_vars->rx = (int)player->x + 1;
		ray_vars->ry = (player->x - ray_vars->rx) * ray_vars->nTan + player->y;
		ray_vars->xo = 1;
		ray_vars->yo = -ray_vars->xo * ray_vars->nTan;
	}
	if (ray_vars->ra == PI / 2 || ray_vars->ra == 3 * PI / 2)
	{
		ray_vars->rx = player->x;
		ray_vars->ry = player->y;
		ray_vars->dof = longest_d(vars->map->map);
	}
}

void	check_vertical(t_raycasting_vars *rv, t_cub3d *vars,
	t_player *player)
{
	init_vertical(rv, vars, player);
	while (rv->dof < 20)
	{
		rv->mx = (int) rv->rx >> 0;
		rv->my = (int) rv->ry >> 0;
		if (rv->mx < 0 || rv->my < 0 || rv->my
			> map_height(vars->map->map) || rv->mx
			> longest_row(vars->map->map))
		{
			rv->dof = longest_d(vars->map->map);
		}
		else if (vars->map->map[rv->my][rv->mx] == '1')
		{
			rv->vx = rv->rx;
			rv->vy = rv->ry;
			rv->distV = dist(player->x, player->y, rv->vx, rv->vy);
			rv->dof = longest_d(vars->map->map);
		}
		else
		{
			rv->rx += rv->xo;
			rv->ry += rv->yo;
			rv->dof += 1;
		}
	}
}
