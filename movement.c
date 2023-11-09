/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:56:42 by yalee             #+#    #+#             */
/*   Updated: 2023/11/09 18:56:59 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	can_move(t_player *player, char **map, char sign)
{
	if (sign == '+')
	{
		if (map[(int)(player->y + player->dy)][(int)(player->x + player->dx)]
			== '1')
		{
			return (0);
		}
	}
	if (sign == '-')
	{
		if (map[(int)(player->y - player->dy)][(int)(player->x - player->dx)]
			== '1')
		{
			return (0);
		}
	}
	return (1);
}

void	move_player(t_player *player, char **map, char key)
{
	if (key == 'A')
	{
		player->angle -= 0.05;
		if (player->angle < 0)
			player->angle += 2 * PI;
	}
	if (key == 'D')
	{
		player->angle += 0.05;
		if (player->angle > 2 * PI)
			player->angle -= 2 * PI;
	}
	player->dx = cos(player->angle) * 0.2;
	player->dy = sin(player->angle) * 0.2;
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
