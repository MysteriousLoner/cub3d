#include "../cub3d.h"

void	put_texture(t_cub3d *vars)
{
	int x = 0;
	int y = 0;
	char *pixel;
	char *pixel2;
	int color;
	// vars->n->img = mlx_xpm_file_to_image(vars->mlx, "./texture/North_texture.xpm", &vars->n->width, &vars->n->height);
	while (x < vars->n->width)
	{
		y = 0;
		while (y < vars->n->height)
		{
			// printf("ll: %i, bpp: %i\n", vars->n->line_length, vars->n->bpp);
			// pixel2 = vars->n->addr + ((y * vars->n->line_length) + (x * (vars->n->bpp / 8)));
			pixel2 = vars->n->addr + (y * vars->n->line_length + x * (vars->n->bpp / 8));
			color = mlx_get_color_value(vars->mlx, *(int *)pixel2);
			put_pixel(vars, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_walls(t_cub3d *vars, int r, float dist)
{
	int		x;
	int		y;
	float	line_h;
	int		color;
	char	*pixel;
	int		tmp;
	int		tmp2;

	tmp = 0;
	line_h = (HEIGHT / dist);
	if (line_h > HEIGHT)
		line_h = HEIGHT;
	x = r * 3;
	while (x < ((r + 1) * 3))
	{
		tmp = 0;
		y = (HEIGHT / 2) - (line_h / 2);
		while (y < ((HEIGHT / 2) + (line_h / 2)))
		{
			// printf("y: %i\n", y);
			// printf("ll: %i\n", vars->n->line_length);
			pixel = vars->n->addr + (tmp * vars->n->line_length +  x * (vars->n->bpp / 8));
			color = mlx_get_color_value(vars->mlx, *(int*)pixel);
			put_pixel(vars, x, y, color);
			tmp++;
			y++;
		}
		// tmp++;
		x++;
	} 
}