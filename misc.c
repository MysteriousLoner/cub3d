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
	return (max);
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	*map_to_intmap(char	**map, int height, int width)
{
	int	*intmap;
	int	i;
	int	j;
	int	k;

	intmap = malloc(sizeof(int) * height * width);
	i = 0;
	j = 0;
	k = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == '1')
				intmap[k] = 1;
			else
				intmap[k] = 0;
			j++;
			k++;
		}
		i++;
	}
	intmap[k] = 2;
	printf("k: %d\n", k);
	print_intmap(intmap);
	return (intmap);
}