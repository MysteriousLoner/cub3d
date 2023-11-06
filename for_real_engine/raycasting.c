#include "../cub3d.h"

float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	check_horizontal(t_raycasting_vars *ray_vars, t_cub3d *vars, t_player *player)
{
	ray_vars->dof = 0;
	ray_vars->aTan = -1 / tan(ray_vars->ra);
	printf("here\n");
	if (ray_vars->ra > PI)
	{
		ray_vars->ry = (((int)player->y >> 0) << 0) - 0.0001;
		ray_vars->rx = (player->y - ray_vars->ry) * ray_vars->aTan + player->x;
		ray_vars->yo = -1; //x
		ray_vars->xo = -ray_vars->yo * ray_vars->aTan;
	}
	if (ray_vars->ra < PI)
	{
		ray_vars->ry = (((int)player->y >> 0) << 0) + 1; //x
		ray_vars->rx = (player->y - ray_vars->ry) * ray_vars->aTan + player->x;
		ray_vars->yo = 1; //x
		ray_vars->xo = -ray_vars->yo * ray_vars->aTan;
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
		ray_vars->my = (int) ray_vars->ry >> 0 ;
		if (ray_vars->mx < 0 || ray_vars->my < 0 || ray_vars->mx > longest_row(vars->map->map) || ray_vars->my > map_height(vars->map->map))
		{
			ray_vars->dof = 8;
		}
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
}

void	check_vertical(t_raycasting_vars *ray_vars, t_cub3d *vars, t_player *player)
{
	ray_vars->nTan = -1 * tan(ray_vars->ra);
	// printf("PI / 2: %f\n", PI / 2);
	if (ray_vars->ra > (PI / 2 ) && ray_vars->ra < (3 * PI / 2))
	{
		ray_vars->rx = (((int)player->y >> 0) << 0) - 0.0001;
		ray_vars->ry = (player->x - ray_vars->rx) * ray_vars->nTan + player->y;
		ray_vars->xo = -1; //x
		ray_vars->yo = -ray_vars->xo * ray_vars->nTan;
	}
	if (ray_vars->ra < (PI / 2) || ray_vars->ra > (3 * PI / 2))
	{
		ray_vars->rx = (((int)player->x >> 0) << 0) + 1; //x
		ray_vars->ry = (player->x - ray_vars->rx) * ray_vars->nTan + player->y;
		ray_vars->xo = 1; //x
		ray_vars->yo = -ray_vars->xo * ray_vars->nTan;
	}
	if (ray_vars->ra == (PI / 2) || ray_vars->ra == 3 * (PI / 2))
	{
		ray_vars->rx = player->x;
		ray_vars->ry = player->y;
		ray_vars->dof = 8;
	}
	while (ray_vars->dof < 8)
	{
		ray_vars->mx = (int) ray_vars->rx >> 0;
		ray_vars->my = (int) ray_vars->ry >> 0 ;
		printf("mx: %d, my: %d\n", ray_vars->mx, ray_vars->my);
		printf("map height: %d\n", map_height(vars->map->map));
		if (ray_vars->mx < 0 || ray_vars->my < 0 || ray_vars->my > map_height(vars->map->map) || ray_vars->mx > longest_row(vars->map->map))
		{
			printf("here\n");
			ray_vars->dof = 8;
		}
		else if (ray_vars->my < map_height(vars->map->map) && ray_vars->mx < longest_row(vars->map->map) && vars->map->map[ray_vars->my][ray_vars->mx] == '1')
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
		ray_vars->dof = 0;
		// check_horizontal(ray_vars, vars, player);
		check_vertical(ray_vars, vars, player);
		draw_line_to_point(vars, ray_vars->rx, ray_vars->ry, player);
		ray_vars->r++;
		free(ray_vars);
	}
}