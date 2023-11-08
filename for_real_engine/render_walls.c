#include "../cub3d.h"

void	draw_walls(t_cub3d *vars, int r, float dist, int color)
{
	int		x;
	int		y;
	int		line_h;

	line_h = (HEIGHT / dist);
	if (line_h > HEIGHT)
		line_h = HEIGHT;
	x = r * 3;
	while (x < ((r + 1) * 3))
	{
		y = (HEIGHT / 2) - (line_h / 2);
		while (y < ((HEIGHT / 2) + (line_h / 2)))
		{
			put_pixel(vars, x, y, rgb_to_int(color, 0, 0));
			y++;
		}
		x++;
	} 
	// (void)color;
}