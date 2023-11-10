/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:19:13 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/11/10 13:59:42 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	texture_init(t_cub3d *vars)
{
	vars->north = malloc(sizeof(t_image));
	vars->south = malloc(sizeof(t_image));
	vars->east = malloc(sizeof(t_image));
	vars->west = malloc(sizeof(t_image));
	vars->north->img = mlx_xpm_file_to_image(vars->mlx,
			vars->map->no, &vars->north->width, &vars->north->height);
	vars->north->addr = mlx_get_data_addr(vars->north->img,
			&vars->north->bpp, &vars->north->line_length, &vars->north->endian);
	vars->south->img = mlx_xpm_file_to_image(vars->mlx, vars->map->so,
			&vars->south->width, &vars->south->height);
	vars->south->addr = mlx_get_data_addr(vars->south->img,
			&vars->south->bpp, &vars->south->line_length, &vars->south->endian);
	vars->east->img = mlx_xpm_file_to_image(vars->mlx, vars->map->ea,
			&vars->east->width, &vars->east->height);
	vars->east->addr = mlx_get_data_addr(vars->east->img, &vars->east->bpp,
			&vars->east->line_length, &vars->east->endian);
	vars->west->img = mlx_xpm_file_to_image(vars->mlx, vars->map->we,
			&vars->west->width, &vars->west->height);
	vars->west->addr = mlx_get_data_addr(vars->west->img, &vars->west->bpp,
			&vars->west->line_length, &vars->west->endian);
}
