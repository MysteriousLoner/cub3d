/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:13:48 by yalee             #+#    #+#             */
/*   Updated: 2023/11/10 13:57:08 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// check if the directory of NO SO EA WE is valid
int	check_graphic(int fd, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	while (i < 4)
	{
		line = get_next_line(fd);
		if (line[0] == '\n')
			break ;
		if (line[0] == 'N' && line[1] == 'O')
			add_nswe(&map->no, line);
		if (line[0] == 'S' && line[1] == 'O')
			add_nswe(&map->so, line);
		if (line[0] == 'E' && line[1] == 'A')
			add_nswe(&map->ea, line);
		if (line[0] == 'W' && line[1] == 'E')
			add_nswe(&map->we, line);
		free(line);
		i++;
	}
	if (map->no == NULL || map->so == NULL
		|| map->ea == NULL || map->we == NULL)
		return (0);
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

// append the map with new line
void	append_map(char ***map, char *new_map)
{
	int		i;
	char	**tmp;

	i = 0;
	while ((*map)[i])
		i++;
	tmp = dup_2d((*map));
	free_2d((*map));
	(*map) = malloc(sizeof(char *) * (i + 2));
	(*map)[i + 1] = 0;
	i = 0;
	while (tmp[i])
	{
		(*map)[i] = ft_strdup(tmp[i]);
		i++;
	}
	(*map)[i] = ft_strdup(new_map);
	free_2d(tmp);
	return ;
}

// check map for invalid characters and missing or extra sprites
int	cheese(int pcount)
{
	if (pcount != 1)
		return (1);
	else
		return (0);
}

int	map_unclean(char **map, t_cub3d **vars)
{
	int	i;
	int	j;
	int	p_count;

	i = 0;
	p_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_cardinal(map[i][j]))
			{
				assign_pvars(i, j, map[i][j], (*vars)->player);
				map[i][j] = '0';
				p_count++;
			}
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '
				&& !is_cardinal(map[i][j]) && map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (cheese(p_count));
}
