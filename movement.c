#include "cub3d.h"

void	move_player(t_player *player, char key)
{
	if (key == 'A')
	{
		player->angle -= 0.1;
		if (player->angle < 0)
			player->angle += 2 * G_PI;
		player->dx = cos(player->angle) * 5;
		player->dy = sin(player->angle) * 5;
	}
	if (key == 'D')
	{
		player->angle += 0.1;
		if (player->angle > 2 * G_PI)
			player->angle -= 2 * G_PI;
		player->dx = cos(player->angle) * 5;
		player->dy = sin(player->angle) * 5;
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
	// (void)player;
	// (void)key;
}
