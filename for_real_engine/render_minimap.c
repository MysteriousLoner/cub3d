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

void	minimap_put_wall(int size, t_cub3d *vars, int pos_x, int pos_y)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = pos_x * size;
	y = pos_y * size;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j != 0 && j != size && i != 0 && i != size)
				mlx_pixel_put(vars->mlx, vars->win, x + i, y + j, rgb_to_int(255, 255, 255));
			j++;
		}
		i++;
	}
}

void	render_minimap(int width, int height, t_cub3d *vars, t_player *player)
{
	printf("\nrendering minimap\n");
	printf("width: %d\n", width);
	printf("height: %d\n", height);
	printf("player x: %f\n", player->x);
	printf("player y: %f\n", player->y);
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
			j++;
		}
		i++;
	}
}