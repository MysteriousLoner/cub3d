#include "cub3d.h"

int		can_move(t_player *player, char **map, char sign)
{
	if (sign == '+')
	{
		if (map[(int)(player->y + player->dy)][(int)(player->x + player->dx)] == '1')
		{
			printf("WALL!\n");
			return (0);
		}
	}
	if (sign == '-')
	{
		if (map[(int)(player->y - player->dy)][(int)(player->x - player->dx)] == '1')
		{
			printf("WALL!\n");
			return (0);
		}
	}
	return (1);
}

void	move_player(t_player *player, char **map, char key)
{
	if (key == 'A')
	{
		player->angle -= 0.1;
		if (player->angle < 0)
			player->angle += 2 * PI;
	}
	if (key == 'D')
	{
		player->angle += 0.1;
		if (player->angle > 2 * PI)
			player->angle -= 2 * PI;
	}
	player->dx = cos(player->angle) * 0.5;
	player->dy = sin(player->angle) * 0.5;
	if (key == 'W' && can_move(player, map, '+'))
	{
		player->x += player->dx;
		player->y += player->dy;
	}
	if (key == 'S' && can_move(player, map, '-'))
	{
		player->x -= player->dx;
		player->y -= player->dy;
	}
}
