#include "../cub3d.h"

float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	check_horizontal(t_raycasting_vars *ray_vars)
{
	ray_vars->dof = 0;
	ray_vars->aTan = -1 / tan(ray_vars->ra);
	if (ray_vars->ra > PI)
	{
		flag = 1;
		ray_vars->ry = (((int)player->y >> 0) << 0) - 0.0001;
		ray_vars->rx = (player->y - ray_vars->ry) * ray_vars->aTan + player->x;
		ray_vars->yo = -1; //x
		ray_vars->xo = -ray_vars->yo * ray_vars->aTan;
	}
	else if (ray_vars->ra < PI)
	{
		ray_vars->ry = (((int)player->y >> 0) << 0) + 1; //x
		ray_vars->rx = (player->y - ray_vars->ry) * ray_vars->aTan + player->x;
		ray_vars->yo = 1; //x
		ray_vars->xo = -ray_vars->yo * ray_vars->aTan;
	}
	else if (ray_vars->ra == 0 || ray_vars->ra == PI)
	{
		ray_vars->rx = player->x;
		ray_vars->ry = player->y;
		ray_vars->dof = 8;
	}
	while (ray_vars->dof < 8)
	{
		ray_vars->mx = (int) ray_vars->rx >> 0;
		ray_vars->my = (int) ray_vars->ry >> 0 ;
		if (ray_vars->mp < longest_row(vars->map->map) * map_height(vars->map->map) && vars->map->map[ray_vars->my][ray_vars->mx] == '1')
		{
			ray_vars->dof = 8;
		}
		else
		{
			ray_vars->rx += ray_vars->xo;
			ray_vars->ry += ray_vars->yo;
			ray_vars->dof += 1;
		}
}

void	check_vertical(t_raycasting_vars *ray_vars)
{
	check vertical lines
	ray_vars->dof = 0;
	ray_vars->verX = 100000;
	ray_vars->vx = player->x;
	ray_vars->vy = player->y;
	ray_vars->nTan = -(tan(ray_vars->ra));
	if (ray_vars->ra > P2 && ray_vars->ra < P3)
	{
		ray_vars->rx = (((int)player->x >> 0) << 0) - 0.001;
		ray_vars->ry = (player->x - ray_vars->rx) * ray_vars->nTan + player->y;
		ray_vars->xo = -1; //x
		ray_vars->yo = -ray_vars->xo * ray_vars->nTan;
	}
	if (ray_vars->ra < P2 || ray_vars->ra > P3)
	{
		ray_vars->rx = (((int)player->x >> 0) << 0) + 1; //x
		ray_vars->ry = (player->x - ray_vars->rx) * ray_vars->nTan + player->y;
		ray_vars->xo = 1; //x
		ray_vars->yo = -ray_vars->xo * ray_vars->nTan;
	}
	if (ray_vars->ra == 0 || ray_vars->ra == PI)
	{
		ray_vars->rx = player->x;
		ray_vars->ry = player->y;
		ray_vars->dof = 8;
	}
	while (ray_vars->dof < 8)
	{
		ray_vars->mx = (int) ray_vars->rx >> 0;
		ray_vars->my = (int) ray_vars->ry >> 0;
		ray_vars->mp = ray_vars->my * longest_row(vars->map->map) + ray_vars->mx;
		if (ray_vars->mp > 0 && ray_vars->mp > longest_row(vars->map->map) * map_height(vars->map->map) && vars->map->map[ray_vars->my][ray_vars->mx] == '1')
		{
			ray_vars->vx = ray_vars->rx;
			ray_vars->vy = ray_vars->ry;
			ray_vars->verX = dist(player->x, player->y, ray_vars->vx, ray_vars->vy);
			ray_vars->dof = 8;
		}
		else
		{
			ray_vars->rx += ray_vars->xo;
			ray_vars->ry += ray_vars->yo;
			ray_vars->dof += 1;
		}
	}
	if (ray_vars->verX < ray_vars->horX)
	{
		ray_vars->rx = ray_vars->vx;
		ray_vars->ry = ray_vars->vy;
	}
	if (ray_vars->verX > ray_vars->horX)
	{
		ray_vars->rx = ray_vars->hx;
		ray_vars->ry = ray_vars->hy;
	}
}

void	draw_rays(t_cub3d *vars, t_player *player)
{
	t_raycasting_vars *ray_vars;
	int	flag;

	flag = 0;
	ray_vars = malloc(sizeof(t_raycasting_vars));
	ray_vars->map = map_to_intmap(vars->map->map, map_height(vars->map->map), longest_row(vars->map->map));
	ray_vars->ra = player->angle;
	ray_vars->r = 0;
	while (ray_vars->r < 1)
	{
		check_horizontal(ray_vars);
		check_vertical(ray_vars);
		draw_line_to_point(vars, ray_vars->rx, ray_vars->ry, player);
		ray_vars->r++;
		free(ray_vars);
	}
}