/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:47:23 by yalee             #+#    #+#             */
/*   Updated: 2023/11/09 18:47:35 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// check if the zero has space a space around it
int	unclosed_zero2(char **map, int i, int j, int mi)
{
	if (i - 1 > 0 && (map[i - 1][j] == ' ' || map[i - 1][j] == '\n'
		|| map[i - 1][j] == 0))
		return (1);
	if (i + 1 < mi && (map[i + 1][j] == ' ' || map[i + 1][j] == '\n'
		|| map[i + 1][j] == 0))
		return (1);
	if (j - 1 > 0 && (map[i][j - 1] == ' ' || map[i][j - 1] == '\n'
		|| map[i][j - 1] == 0))
		return (1);
	if (j + 1 < (int)(ft_strlen(map[i]) - 1) && (map[i][j + 1] == ' '
		|| map[i][j + 1] == '\n' || map[i][j + 1] == 0))
		return (1);
	return (0);
}

int	unclosed_zero(char **map, int i, int j)
{
	int	mi;

	mi = 0;
	while (map[mi])
		mi++;
	if (i == mi - 1)
		return (1);
	if (i == 0)
		return (1);
	if (map[i + 1] == 0)
		return (1);
	if (j == 0)
		return (1);
	if (map[i][j + 1] == 0 || map[i][j + 1] == '\n')
		return (1);
	if (unclosed_zero2(map, i, j, mi))
		return (1);
	return (0);
}

// check if map is closed
int	map_not_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (unclosed_zero(map, i, j))
				{
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

// mini switch
int	map_valid(t_map *map, t_cub3d *vars)
{
	char	**tmp;

	tmp = dup_2d(map->map);
	if (map_unclean(map->map, &vars))
		return (0);
	if (map_not_closed(tmp))
		return (0);
	free_2d(tmp);
	return (1);
}

// check if the map is fully enclosed and traversable
int	check_map(t_map *map, int fd, t_cub3d *vars)
{
	char	*line;

	map->map = malloc(sizeof(char *) * (2));
	map->map[0] = get_next_line(fd);
	map->map[1] = 0;
	while (map->map[0][0] == '\n')
	{
		free(map->map[0]);
		map->map[0] = get_next_line(fd);
	}
	line = get_next_line(fd);
	while (line)
	{
		append_map(&map->map, line);
		free(line);
		line = get_next_line(fd);
	}
	if (map_valid(map, vars) == 0)
		return (0);
	return (1);
}
