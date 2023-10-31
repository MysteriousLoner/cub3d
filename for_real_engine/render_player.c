#include "../cub3d.h"

// render the player as a 4x4 square pixel by changing colour of pixels on the minimap
void	render_player(t_cub3d *vars, int size, t_player *player)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = player->x * size;
	y = player->y * size;
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
	printf("rendering player, these are the variables you need.\n");
	printf("Use these to calculate the pixel position of the player on the minimap.\n");
	printf("player->x: %f\nplayer->y: %f\n", player->x, player->y);
	printf("Use these to calculate the mathmathical position of the player on the minimap.\n");
	printf("player->c_pos: %f\n", player->c_pos);
	printf("This is the size of the cube / 2, add it to your calculation to get where to put the pizel.\n");
	printf("center pixel for the player, x = width / player->posx + player->c_pos\n");
	printf("center pixel for the player, y = height / player->posy + player->c_pos\n");
	printf("I think glhf\n");
}