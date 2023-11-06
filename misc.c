#include "cub3d.h"

int	longest_row(char **map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = 0;
	while (map[i])
	{
		while (map[i][j])
			j++;
		if (j > max)
			max = j;
		j = 0;
		i++;
	}
	return (max - 2);
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i - 1);
}

int	longest_d(char **map)
{
	int	max;
	int	i;

	i = 0;
	max = map_height(map);
	while(map[i])
	{
		if ((int)ft_strlen(map[i]) - 1 > max)
			max = ft_strlen(map[i]) - 1;
		i++;
	}
	return (max);
}
