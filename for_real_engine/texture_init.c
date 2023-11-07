/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:19:13 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/11/07 18:39:53 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	texture_init(t_cub3d *vars)
{
	vars->n = malloc(sizeof(t_image));
	printf("acess: %i\n", access("./texture/North_texture.xpm", R_OK));
	printf("NO:%s\n", vars->map->NO);
	vars->n->img = mlx_xpm_file_to_image(vars->mlx, "./texture/North_texture.xpm", &vars->n->width, &vars->n->height);
	vars->n->addr = mlx_get_data_addr(vars->n->img, &vars->n->bpp, &vars->n->line_length, &vars->n->endian);
	// printf("addr: %s\n", vars->n->addr);
}