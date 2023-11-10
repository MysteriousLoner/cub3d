/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:47:45 by yalee             #+#    #+#             */
/*   Updated: 2023/11/11 00:57:21 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_check(char *argv, t_cub3d *vars)
{
	int	fd;

	vars->map = (t_map *)malloc(sizeof(t_map));
	vars->map->no = NULL;
	vars->map->so = NULL;
	vars->map->ea = NULL;
	vars->map->we = NULL;
	fd = open(argv, O_RDONLY);
	if (!check_graphic(fd, vars->map))
		return (0);
	if (!check_colour(fd, vars->map))
		return (0);
	if (!check_map(vars->map, fd, vars))
		return (0);
	close(fd);
	return (1);
}

// get rgb value from the map and assign it to struct
int	check_colour(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line[0] == 'F' && line[1] == ' ')
		add_rgb(map, 'F', line);
	free(line);
	line = get_next_line(fd);
	if (line[0] == 'C' && line[1] == ' ')
		add_rgb(map, 'C', line);
	free(line);
	if (map->floor == NULL || map->ceiling == NULL)
	{
		printf("COLOUR FORMAT ERROR!\n");
		return (0);
	}
	return (1);
}
