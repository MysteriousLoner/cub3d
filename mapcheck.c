#include "cub3d.h"

// check if the directory of NO SO EA WE is valid
// int	check_graphic(int fd)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	line = get_next_line(fd);
// 	while ()
// 	{
// 		if (line[0] == 'N' && line[1] == 'O')
// 			i++;
// 		if (line[0] == 'S' && line[1] == 'O')
// 			i++;
// 		if (line[0] == 'E' && line[1] == 'A')
// 			i++;
// 		if (line[0] == 'W' && line[1] == 'E')
// 			i++;
// 		free(line);
// 	}
// 	if (i != 4)
// 		return (0);
// 	return (1);
// }

// char	**map_check(char *argv)
// {
// 	int	fd;
// 	char	**map;

// 	fd = open(argv, O_RDONLY);
// 	if (!check_graphic(fd))
// 		return (NULL);
// 	if (!check_colour(fd))
// 		return (NULL);
// 	if (!check_map(&map, fd))
// 		return (NULL);
// 	return (map);
// }