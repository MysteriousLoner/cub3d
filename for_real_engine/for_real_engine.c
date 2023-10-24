#include "../cub3d.h"

int		rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	render_sky(t_cub3d *vars)
{
	int	x;
	int	y;

	x = vars->width * 0.25;
	y = 0;
	while (y < vars->height * 0.25)
	{
		while (x < vars->width)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, y, rgb_to_int(135, 206, 235));
			x++;
		}
		x = vars->width * 0.25;
		y++;
	}
	while (y < vars->height / 2)
	{
		while (x < vars->width)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, y, rgb_to_int(135, 206, 235));
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
			mlx_pixel_put(vars->mlx, vars->win, x, y, rgb_to_int(205, 133, 65));
			x++;
		}
		x = 0;
		y++;
	}
}

int	for_real_engine(t_cub3d *vars)
{
	render_sky(vars);
	render_earth(vars);
	// render_minimap(vars);
	// render_player(vars);
	// render_walls(vars);
	return (1);
}