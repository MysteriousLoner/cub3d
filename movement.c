#include "cub3d.h"

void	move_player(t_player *player, char **map, char key)
{
	if (key == 'A')
	{
		player->angle -= 0.1;
		if (player->angle < 0)
			player->angle += 2 * PI;
		player->dx = cos(player->angle);
		player->dy = sin(player->angle);
	}
	if (key == 'D')
	{
		player->angle += 0.1;
		if (player->angle > 2 * PI)
			player->angle -= 2 * PI;
		player->dx = cos(player->angle);
		player->dy = sin(player->angle);
	}
	if (key == 'W')
	{
		player->x += player->dx;
		player->y += player->dy;
	}
	if (key == 'S')
	{
		player->x -= player->dx;
		player->y -= player->dy;
	}
	(void)map;
}
