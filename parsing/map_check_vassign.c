/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_vassign.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:45:44 by yalee             #+#    #+#             */
/*   Updated: 2023/11/09 18:39:13 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_cardinal(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	add_nswe(char **dir, char *line)
{
	*dir = ft_substr(line, 3, ft_strlen(line) - 4);
}

// format check and assign rgb value to struct
void	add_rgb(t_map *map, char c, char *line)
{
	char	**rgb;

	line = line + 2;
	rgb = ft_split(line, ',');
	if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL)
		return ;
	if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[2]) > 255)
		return ;
	if (ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[2]) < 0)
		return ;
	if (c == 'F')
	{
		map->floor = (t_rgb *)malloc(sizeof(t_rgb));
		map->floor->r = ft_atoi(rgb[0]);
		map->floor->g = ft_atoi(rgb[1]);
		map->floor->b = ft_atoi(rgb[2]);
	}
	else if (c == 'C')
	{
		map->ceiling = (t_rgb *)malloc(sizeof(t_rgb));
		map->ceiling->r = ft_atoi(rgb[0]);
		map->ceiling->g = ft_atoi(rgb[1]);
		map->ceiling->b = ft_atoi(rgb[2]);
	}
}

// assign variables to player struct
void	assign_pvars(int i, int j, char c, t_player *player)
{
	player->x = j + 0.5;
	player->y = i + 0.5;
	if (c == 'S')
		player->angle = PI / 2;
	if (c == 'N')
		player->angle = 3 * PI / 2;
	if (c == 'E')
		player->angle = 0;
	if (c == 'W')
		player->angle = PI;
	player->dy = sin(player->angle) * 0.2;
	player->dx = cos(player->angle) * 0.2;
}
