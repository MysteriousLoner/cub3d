#include "../cub3d.h"

// render the minimap based on the arguements given
// mlx pointer and window pointer are given in the t_cub3d struct, access by calling 
// vars->mlx and vars->win
// width and height are the dimensions of the minimap
// get player coordinates from t_player struct, access by calling vars->player->x and vars->player->y

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
	vars->screen->addr = mlx_get_data_addr(vars->screen->img, &vars->screen->bpp,
	&vars->screen->line_length, &vars->screen->endian);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j != 0 && j != size && i != 0 && i != size)
				put_pixel(vars, x + i, y + j, rgb_to_int(255, 255, 255));
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
	vars->screen->addr = mlx_get_data_addr(vars->screen->img, &vars->screen->bpp,
	&vars->screen->line_length, &vars->screen->endian);
	while (i < size)
	{
		j = 0;
		while (j < size)
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

void	init_minimap(int width, int height, t_cub3d *vars)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = get_map_size(vars->map->map, width, height);
	printf("size: %i\n", size);
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