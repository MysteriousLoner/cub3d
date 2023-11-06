#include "../cub3d.h"


// Calculate the endpoint of the line based on the player's angle
void	draw_line(t_cub3d *vars, int size, t_player *player, float angle)
{
    int		x;
    int		y;
    int		i;
    int		j;
    float	line_len;
    // float	line_dx;
    // float	line_dy;
    float	line_width;

    // Calculate the endpoint of the line based on the player's angle
    i = 0;
    line_len = size * 0.2 * 4.0;
    // line_dx = line_len * cos(player->angle);
    // line_dy = line_len * sin(player->angle);
    x = (player->x + 0.5) * size - line_len / 2.0;
    y = (player->y + 0.5) * size - line_len / 2.0;

    // Calculate the width of the line based on the player's size
    line_width = size * 0.2 * 0.2;

    // Draw the line as a rectangle with the given width
    while (i < line_len)
    {
        j = 0;
        while (j < line_width + 1)
        {
            put_pixel(vars, x + i * cos(angle) - j * sin(angle),
                      y + i * sin(angle) + j * cos(angle),
                      rgb_to_int(255, 0, 0));
            j++;
        }
        i++;
    }
}

// render the player as a 4x4 square pixel by changing colour of pixels on the minimap
void	render_player(t_cub3d *vars, int size, t_player *player)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = player->x * size - size * 0.1;
	y = player->y * size - size * 0.1;
	i = 0;
	while (i <= size * 0.2)
	{
		j = 0;
		while (j <= size * 0.2)
		{
			put_pixel(vars, x + i, y + j, rgb_to_int(255, 255, 255));
			j++;
		}
		i++;
	}
    draw_line(vars, size, player, player->angle);
}