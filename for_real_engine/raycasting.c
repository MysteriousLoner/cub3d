#include "../cub3d.h"

// void	draw_rays(t_cub3d *vars, t_player *player)
// {
// 	t_raycasting_vars ray_vars;

// 	ray_vars.map = map_to_intmap(vars->map->map, map_height(vars->map->map), longest_row(vars->map->map));
// 	ray_vars.ra = player->angle;
// 	ray_vars.r = 0;
// 	while (ray_vars.r < 1)
// 	{
// 		ray_vars.dof = 0;
// 		ray_vars.aTan = -1 / tan(ray_vars.ra);
// 		if (ray_vars.ra > PI)
// 		{
// 			ray_vars.ry = player->y - 0.0001;
// 			ray_vars.rx = (player->y - ray_vars.ry) * ray_vars.aTan + player->x;
// 			ray_vars.yo = -0.5;
// 			ray_vars.xo = -ray_vars.yo * ray_vars.aTan;
// 		}
// 		if (ray_vars.ra < PI)
// 		{
// 			ray_vars.ry = player->y + 0.5;
// 			ray_vars.rx = (player->y - ray_vars.ry) * ray_vars.aTan + player->x;
// 			ray_vars.yo = 0.5;
// 			ray_vars.xo = -ray_vars.yo * ray_vars.aTan;
// 		}
// 		if (ray_vars.ra == 0 || ray_vars.ra == PI)
// 		{
// 			ray_vars.rx = player->x;
// 			ray_vars.ry = player->y;
// 			ray_vars.dof = 8;
// 		}
// 		while (ray_vars.dof < 8)
// 		{
// 			ray_vars.mx = ray_vars.rx;
// 			ray_vars.my = ray_vars.ry;
// 			ray_vars.mp = ray_vars.my * longest_row(vars->map->map) + ray_vars.mx;
// 			printf("ray_vars.mx: %d\n", ray_vars.mx);
// 			printf("ray_vars.my: %d\n", ray_vars.my);
// 			printf("ray_vars.mp: %d\n", ray_vars.mp);
// 			if (ray_vars.mp < longest_row(vars->map->map) * map_height(vars->map->map) && ray_vars.map[ray_vars.mp] == 1)
// 				ray_vars.dof = 8;
// 			else
// 			{
// 				ray_vars.rx += ray_vars.xo;
// 				ray_vars.ry += ray_vars.yo;
// 				ray_vars.dof += 1;
// 			}
// 		}
// 		printf("ray_vars.rx: %f\n", ray_vars.rx);
// 		printf("ray_vars.ry: %f\n", ray_vars.ry);
// 		draw_line_to_point(vars, ray_vars.rx, ray_vars.ry, player);
// 		ray_vars.r++;
// 	}
// }