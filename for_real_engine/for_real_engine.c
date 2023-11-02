#include "../cub3d.h"

int		rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	put_pixel(t_cub3d *vars, int x, int y, int color)
{
	*(unsigned int *)(vars->screen->addr +
		(y * vars->screen->line_length + x * (vars->screen->bpp / 8))) = color;
}

void draw_line_to_point(t_cub3d *vars, float x, float y, t_player *player)
{
	int	i;
	int j;

	// printf("drawing line\n");
	// printf("x: %f\n", x);
	// printf("y: %f\n", y);
	i = 0;
	j = (sqrt(pow(fabs(player->x - x), 2) + pow(fabs(player->y - y), 2))) * vars->size;
	printf("sqrt(pow(fabs(player->x - x), 2) + pow(fabs(player->y - y), 2)): %f\n", (sqrt(pow(fabs(player->x - x), 2) + pow(fabs(player->y - y), 2))) * vars->size);
	while (i < j)
	{
		put_pixel(vars, (player->x * vars->size + i * cos(player->angle)), (player->y * vars->size + i * sin(player->angle)), rgb_to_int(255, 0, 0));
		i++;
	}
	// printf("done drawing line\n");
}

void	init_sky(t_cub3d *vars)
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

void	init_earth(t_cub3d *vars)
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

void	init_screen(t_cub3d *vars)
{
	vars->screen = (t_image *)malloc(sizeof(t_image));
	vars->screen->img = mlx_new_image(vars->mlx, vars->width, vars->height);
	vars->screen->addr = mlx_get_data_addr(vars->screen->img, &vars->screen->bpp,
		&vars->screen->line_length, &vars->screen->endian);
}

void	init_graphics(t_cub3d *vars)
{
	init_screen(vars);
	init_sky(vars);
	init_earth(vars);
	init_minimap(vars->width * 0.40, vars->height * 0.40, vars);
	render_player(vars, vars->size, vars->player);
	draw_rays(vars, vars->player);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->screen->img, 0, 0);
	// render_walls(vars);
}

void	for_real_engine(t_cub3d *vars)
{
	init_graphics(vars);
	// print_player(vars->player);
	// render_player(vars, vars->width * 0.40, vars->height * 0.40, vars->player);
}