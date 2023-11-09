/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:25:10 by yalee             #+#    #+#             */
/*   Updated: 2023/11/09 18:25:11 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_map_size(char **map, int width, int height)
{
	int	i;
	int	longest;

	i = 0;
	longest = 0;
	while (map[i] != 0)
	{
		if ((int)ft_strlen(map[i]) - 1 > longest)
			longest = ft_strlen(map[i]) - 1;
		i++;
	}
	if (i > longest)
		return (height / i);
	return (width / longest);
}

// void	minimap_render_player(t_player)
void	minimap_put_wall(int size, t_cub3d *vars, int pos_x, int pos_y)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = pos_x * size;
	y = pos_y * size;
	i = 0;
	while (i <= size)
	{
		j = 0;
		while (j <= size)
		{
			if (j != 0 && j != size && i != 0 && i != size)
				put_pixel(vars, x + i, y + j, rgb_to_int(255, 255, 255));
			else
				put_pixel(vars, x + i, y + j, rgb_to_int(0, 0, 0));
			j++;
		}
		i++;
	}
}

void	minimap_put_floor(int size, t_cub3d *vars, int pos_x, int pos_y)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = pos_x * size;
	y = pos_y * size;
	i = 0;
	while (i <= size)
	{
		j = 0;
		while (j <= size)
		{
			if (j != 0 && j != size && i != 0 && i != size)
				put_pixel(vars, x + i, y + j, rgb_to_int(128, 128, 128));
			else
				put_pixel(vars, x + i, y + j, rgb_to_int(0, 0, 0));
			j++;
		}
		i++;
	}
}

void	render_minimap(int width, int height, t_cub3d *vars)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = get_map_size(vars->map->map, width, height);
	if (size % 2 == 0)
		size++;
	vars->size = size;
	vars->player->c_pos = size / 2;
	while (vars->map->map[i] != 0)
	{
		j = 0;
		while (vars->map->map[i][j] != '\0' && vars->map->map[i][j] != '\n')
		{
			if (vars->map->map[i][j] == '1')
				minimap_put_wall(size, vars, j, i);
			if (vars->map->map[i][j] == '0')
				minimap_put_floor(size, vars, j, i);
			j++;
		}
		i++;
	}
}
