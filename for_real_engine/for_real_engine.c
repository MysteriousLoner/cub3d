#include "../cub3d.h"

int		rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	put_pixel(t_cub3d *vars, int x, int y, int color)
{
	// vars->screen->addr = mlx_get_data_addr(vars->screen->img, &vars->screen->bpp,
	// 	&vars->screen->line_length, &vars->screen->endian);
	*(unsigned int *)(vars->screen->addr +
		(y * vars->screen->line_length + x * (vars->screen->bpp / 8))) = color;
}

void	init_sky(t_cub3d *vars)
{
	int	x;
	int	y;

	x = vars->width * 0.40;
	y = 0;
	while (y < vars->height * 0.40)
	{
		while (x < vars->width)
		{
			put_pixel(vars, x, y, rgb_to_int(vars->map->ceiling->r,
				vars->map->ceiling->g, vars->map->ceiling->b));
			x++;
		}
		x = vars->width * 0.40;
		y++;
	}
	while (y < vars->height / 2)
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
	mlx_put_image_to_window(vars->mlx, vars->win, vars->screen->img, 0, 0);
}

void	init_graphics(t_cub3d *vars)
{
	printf("init_graphics, screen\n");
	init_screen(vars);
	printf("init_graphics, sky\n");
	init_sky(vars);
	printf("init_graphics, earth\n");
	init_earth(vars);
	printf("init_graphics, minimap\n");
	init_minimap(vars->width * 0.40, vars->height * 0.40, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->screen->img, 0, 0);
	// render_player(vars->width * 0.40, vars->height * 0.40, vars->player);
	// render_walls(vars);
}

void	for_real_engine(t_cub3d *vars)
{
	printf("for_real_engine\n");
	print_player(vars->player);
	render_player(vars, vars->width * 0.40, vars->height * 0.40, vars->player);
}