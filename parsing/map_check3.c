/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:47:45 by yalee             #+#    #+#             */
/*   Updated: 2023/11/09 18:48:03 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_check(char *argv, t_cub3d *vars)
{
	int	fd;

	vars->map = (t_map *)malloc(sizeof(t_map));
	vars->map->NO = NULL;
	vars->map->SO = NULL;
	vars->map->EA = NULL;
	vars->map->WE = NULL;
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
