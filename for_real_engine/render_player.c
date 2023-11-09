/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:27:54 by yalee             #+#    #+#             */
/*   Updated: 2023/11/09 18:29:00 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Calculate the endpoint of the line based on the player's angle
void	draw_line(t_cub3d *vars, int size, t_player *player, float angle)
{
	int		x;
	int		y;
	int		i;
	int		j;
	float	line_width;

	i = 0;
	x = (player->x + 0.5) * size - size * 0.2 * 4.0 / 2.0;
	y = (player->y + 0.5) * size - size * 0.2 * 4.0 / 2.0;
	line_width = size * 0.2 * 0.2;
	while (i < size * 0.2 * 4.0)
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
