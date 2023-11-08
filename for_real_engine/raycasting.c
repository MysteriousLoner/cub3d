#include "../cub3d.h"

float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

float	norm_angle(float angle)
{
	if (angle < 0)
		angle += (2 * PI);
	else if (angle > (2 * PI))
		angle -= (2 * PI);
	return (angle);
}
void	init_horizontal(t_raycasting_vars *ray_vars, t_cub3d *vars, t_player *player)
{
	ray_vars->dof = 0;
	ray_vars->aTan = -1 / tan(ray_vars->ra);
	if (ray_vars->ra > PI)
	{
		ray_vars->ry = (int) player->y - 0.0001;
		ray_vars->rx = (player->y - ray_vars->ry) * ray_vars->aTan + player->x;
		ray_vars->yo = -1; //x
		ray_vars->xo = -ray_vars->yo * ray_vars->aTan;
	}
	if (ray_vars->ra < PI)
	{
		ray_vars->ry = (int)player->y + 1; //x
		ray_vars->rx = (player->y - ray_vars->ry) * ray_vars->aTan + player->x;
		ray_vars->yo = 1; //x
		ray_vars->xo = -ray_vars->yo * ray_vars->aTan;
	}
	if (ray_vars->ra == 0 || ray_vars->ra == PI)
	{
		ray_vars->rx = player->x;
		ray_vars->ry = player->y;
		ray_vars->dof = longest_d(vars->map->map);
	}
}

void	check_horizontal(t_raycasting_vars *ray_vars, t_cub3d *vars, t_player *player)
{
	init_horizontal(ray_vars, vars, player);
	while (ray_vars->dof < 20)
	{
		ray_vars->mx = (int) ray_vars->rx >> 0;
		ray_vars->my = (int) ray_vars->ry >> 0 ;
		if (ray_vars->mx < 0 || ray_vars->my < 0 || ray_vars->mx > longest_row(vars->map->map) || ray_vars->my > map_height(vars->map->map))
		{
			ray_vars->dof = longest_d(vars->map->map);
		}
		if (ray_vars->dof < longest_d(vars->map->map) && vars->map->map[ray_vars->my][ray_vars->mx] == '1')
		{
			ray_vars->hx = ray_vars->rx;
			ray_vars->hy = ray_vars->ry;
			ray_vars->distH = dist(player->x, player->y, ray_vars->hx, ray_vars->hy);
			ray_vars->dof = longest_d(vars->map->map);
		}
		else
		{
			ray_vars->rx += ray_vars->xo;
			ray_vars->ry += ray_vars->yo;
			ray_vars->dof += 1;
		}
	}
}

void	init_vertical(t_raycasting_vars *ray_vars, t_cub3d *vars, t_player *player)
{
	ray_vars->dof = 0;
	ray_vars->nTan = -1 * tan(ray_vars->ra);
	if (ray_vars->ra > (PI / 2 ) && ray_vars->ra < (3 * PI / 2))
	{
		ray_vars->rx = (int) player->x - 0.0001;
		ray_vars->ry = (player->x - ray_vars->rx) * ray_vars->nTan + player->y;
		ray_vars->xo = -1; //x
		ray_vars->yo = -ray_vars->xo * ray_vars->nTan;
	}
	if (ray_vars->ra < (PI / 2) || ray_vars->ra > (3 * PI / 2))
	{
		ray_vars->rx = (int)player->x + 1; //x
		ray_vars->ry = (player->x - ray_vars->rx) * ray_vars->nTan + player->y;
		ray_vars->xo = 1; //x
		ray_vars->yo = -ray_vars->xo * ray_vars->nTan;
	}
	if (ray_vars->ra == PI / 2 || ray_vars->ra == 3 * PI / 2)
	{
		ray_vars->rx = player->x;
		ray_vars->ry = player->y;
		ray_vars->dof = longest_d(vars->map->map);
	}
}

void	check_vertical(t_raycasting_vars *ray_vars, t_cub3d *vars, t_player *player)
{
	init_vertical(ray_vars, vars, player);
	while (ray_vars->dof < 20)
	{
		ray_vars->mx = (int) ray_vars->rx >> 0;
		ray_vars->my = (int) ray_vars->ry >> 0 ;
		if (ray_vars->mx < 0 || ray_vars->my < 0 || ray_vars->my > map_height(vars->map->map) || ray_vars->mx > longest_row(vars->map->map))
		{
			ray_vars->dof = longest_d(vars->map->map);
		}
		else if (vars->map->map[ray_vars->my][ray_vars->mx] == '1')
		{
			ray_vars->vx = ray_vars->rx;
			ray_vars->vy = ray_vars->ry;
			ray_vars->distV = dist(player->x, player->y, ray_vars->vx, ray_vars->vy);
			ray_vars->dof = longest_d(vars->map->map);
		}
		else
		{
			ray_vars->rx += ray_vars->xo;
			ray_vars->ry += ray_vars->yo;
			ray_vars->dof += 1;
		}
	}
}

void	init_rays(t_cub3d *vars, t_player *player, t_raycasting_vars *ray_vars)
{
		ray_vars->distH = 10000000000;
		ray_vars->distV = 10000000000;
		ray_vars->hx = player->x;
		ray_vars->hy = player->y;
		ray_vars->vx = player->x;
		ray_vars->vy = player->y;
}

void	calculate_and_render_wall(t_cub3d *vars, t_player *player, t_raycasting_vars *ray_vars)
{
	if (ray_vars->distH < ray_vars->distV)
	{
		ray_vars->rx = ray_vars->hx;
		ray_vars->ry = ray_vars->hy;
		if (ray_vars->ra > PI)
			ray_vars->dimg = vars->south;
		if (ray_vars->ra < PI)
			ray_vars->dimg = vars->north;
		ray_vars->d = 'h';
		draw_walls(vars, ray_vars->r, ray_vars->distH * cos(norm_angle(player->angle - ray_vars->ra)), ray_vars);
	}
	if (ray_vars->distV < ray_vars->distH)
	{
		ray_vars->rx = ray_vars->vx;
		ray_vars->ry = ray_vars->vy;
		if (ray_vars->ra > (PI / 2 ) && ray_vars->ra < (3 * PI / 2))
			ray_vars->dimg = vars->west;
		else if (ray_vars->ra < (PI / 2) || ray_vars->ra > (3 * PI / 2))
			ray_vars->dimg = vars->east;
		ray_vars->d = 'v';
		draw_walls(vars, ray_vars->r, ray_vars->distV * cos(norm_angle(player->angle - ray_vars->ra)), ray_vars);
	}
	player->lov = ray_vars->ra;
	draw_line_to_point(vars, ray_vars->rx, ray_vars->ry, player);
}

void	draw_rays(t_cub3d *vars, t_player *player)
{
	t_raycasting_vars *ray_vars;
	int	flag;

	flag = 0;
	ray_vars = malloc(sizeof(t_raycasting_vars));
	ray_vars->ra = norm_angle(player->angle - DG * 30);
	ray_vars->r = 0;
	while (ray_vars->r < 400)
	{
		init_rays(vars, player, ray_vars);
		check_horizontal(ray_vars, vars, player);
		check_vertical(ray_vars, vars, player);
		calculate_and_render_wall(vars, player, ray_vars);
		ray_vars->r++;
		ray_vars->ra = norm_angle(ray_vars->ra + 1.0472 / 400);
	}
}