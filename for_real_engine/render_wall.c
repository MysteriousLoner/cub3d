/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:27:00 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/11/06 22:49:47 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_wall(char dir, int height, t_cub3d *vars, float sp)
{
	unsigned int	**pixel1;
	unsigned int	**pixel2;
	//pixel1 = wall
	//pixel2 = texture
	// unsigned int	pixel;

	(void)dir;
	(void)sp;
	(void)height;
	(void)vars;
	
	int x;
	int y;
	y = vars->height / 3;
	x = 0;
	
	pixel1 = vars->north->addr + (y * 400 + x * (vars->screen->bpp / 8))
	pixel2 = vars->screen->addr + (y * vars->screen->line_length + x * (vars->screen->bpp / 8);
	printf("height: %d\n", vars->height/3);
	while (y < (vars->height / 3 * 2))
	{
	x = 0;
	while (x < vars->width)
	{
		put_pixel(vars, x, y, rgb_to_int(255,255,255));
		// put_pixel(vars, x, y + 1, rgb_to_int(0,0,0));
		++x;
	}
	++y;
	}
}