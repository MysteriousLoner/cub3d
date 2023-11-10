/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:47:45 by yalee             #+#    #+#             */
/*   Updated: 2023/11/10 13:42:06 by cyu-xian         ###   ########.fr       */
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
