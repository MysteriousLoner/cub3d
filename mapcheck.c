#include "cub3d.h"

// assign path of graphic to struct if valid
void add_nswe(char **dir, char *line)
{
    *dir = ft_substr(line, 3, ft_strlen(line) - 3);
    // *line ++;
    // printf("before: %s\n", line);
    // *line += 4;
    // printf("line: %s\n", *dir);
}

// check if the directory of NO SO EA WE is valid
int check_graphic(int fd, t_map *map)
{
    char *line;
    int i;

    i = 0;
    while (i < 4)
    {
        line = get_next_line(fd);
        if (line[0] == '\n')
            break;
        if (line[0] == 'N' && line[1] == 'O')
            add_nswe(&map->NO, line);
        if (line[0] == 'S' && line[1] == 'O')
            add_nswe(&map->SO, line);
        if (line[0] == 'E' && line[1] == 'A')
            add_nswe(&map->EA, line);
        if (line[0] == 'W' && line[1] == 'E')
            add_nswe(&map->WE, line);
        free(line);
        i++;
    }
    if (map->NO == NULL || map->SO == NULL || map->EA == NULL || map->WE == NULL)
        return (0);
    return (1);
}

// format check and assign rgb value to struct
void    add_rgb(t_map *map, char c, char *line)
{
    char **rgb;

    line = line + 2;
    rgb = ft_split(line, ',');
    if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL)
        return ;
    if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[2]) > 255)
        return ;
    if (ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[2]) < 0)
        return ;
    if (c == 'F')
    {
        map->floor = (t_rgb *)malloc(sizeof(t_rgb));
        map->floor->r = ft_atoi(rgb[0]);
        map->floor->g = ft_atoi(rgb[1]);
        map->floor->b = ft_atoi(rgb[2]);
    }
    else if (c == 'C')
    {
        map->ceiling = (t_rgb *)malloc(sizeof(t_rgb));
        map->ceiling->r = ft_atoi(rgb[0]);
        map->ceiling->g = ft_atoi(rgb[1]);
        map->ceiling->b = ft_atoi(rgb[2]);
    }
}

// get rgb value from the map and assign it to struct
int	check_colour(int fd, t_map *map)
{
    char    *line;

    line = get_next_line(fd);
    while (line[0] == '\n')
    {
        free(line);
        line = get_next_line(fd);
    }
    if (line[0] == 'F' && line[1] == ' ')
        add_rgb(map, 'F', line);
    free(line);
    line = get_next_line(fd);
    if (line[0] == 'C' && line[1] == ' ')
        add_rgb(map, 'C', line);
    free(line);
    if (map->floor == NULL || map->ceiling == NULL)
    {
        printf("COLOUR FORMAT ERROR!\n");
        return (0);
    }
    return (1);
}

// free 2d array
void    free_2d(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

// duplicate a 2d array
char    **dup_2d(char **arr)
{
    int i;
    char **dup;

    i = 0;
    while (arr[i])
        i++;
    dup = malloc(sizeof(char *) * (i + 1));
    dup[i] = 0;
    i = 0;
    while (arr[i])
    {
        dup[i] = ft_strdup(arr[i]);
        i++;
    }
    return (dup);
}

// append the map with new line
void    append_map(char ***map, char *new_map)
{
    int     i;
    char    **tmp;

    i = 0;
    while ((*map)[i])
        i++;
    tmp = dup_2d((*map));
    free_2d((*map));
    (*map) = malloc(sizeof(char *) * (i + 2));
    (*map)[i + 1] = 0;
    i = 0;
    while (tmp[i])
    {
        (*map)[i] = ft_strdup(tmp[i]);
        i++;
    }
    (*map)[i] = ft_strdup(new_map);
    free_2d(tmp);
    return ;
}

// check if character is a cardinal direction
int is_cardinal(char c)
{
    if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
        return (1);
    return (0);
}

// assign variables to player struct
void    assign_pvars(int i, int j, char c, t_player *player)
{
    player->x = j + 0.5;
    player->y = i + 0.5;
    if (c == 'S')
        player->angle = PI / 2;
    if (c == 'N')
        player->angle = 3 * PI / 2;
    if (c == 'E')
        player->angle = 0;
    if (c == 'W')
        player->angle = PI;
    player->dy = sin(player->angle) * 0.2;
    player->dx = cos(player->angle) * 0.2;
}

// check map for invalid characters and missing or extra sprites
int map_unclean(char **map, t_cub3d **vars)
{
    int i;
    int j;
    int p_count;

    i = 0;
    p_count = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (is_cardinal(map[i][j]))
            {
                assign_pvars(i, j, map[i][j], (*vars)->player);
                map[i][j] = '0';
                p_count++;
            }
            if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '
                && !is_cardinal(map[i][j]) && map[i][j] != '\n')
            {
                printf("error: %c\n", map[i][j]);
                return (1);
            }
            j++;
        }
        i++;
    }
    if (p_count != 1)
    {
        printf("player error: %d\n", p_count);
        return (1);
    }
    return (0);
}

// check if the zero has space a space around it
int unclosed_zero(char **map, int i, int j)
{
    int mi;

    mi = 0;
    while (map[mi])
        mi++;
    if (i == mi - 1)
        return (1);
    if (i == 0)
        return (1);
    if (map[i + 1] == 0)
        return (1);
    if (j == 0)
        return (1);
    if (map[i][j + 1] == 0 || map[i][j + 1] == '\n')
        return (1);
    if (i - 1 > 0 && (map[i - 1][j] == ' ' || map[i - 1][j] == '\n' || map[i - 1][j] == 0))
        return (1);
    if (i + 1 < mi && (map[i + 1][j] == ' ' || map[i + 1][j] == '\n' || map[i + 1][j] == 0))
        return (1);
    if (j - 1 > 0 && (map[i][j - 1] == ' ' || map[i][j - 1] == '\n' || map[i][j - 1] == 0))
        return (1);
    if (j + 1 < (int)(ft_strlen(map[i]) - 1) && (map[i][j + 1] == ' ' || map[i][j + 1] == '\n' || map[i][j + 1] == 0))
        return (1);
    return (0);
}

// check if map is closed
int map_not_closed(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '0')
            {
                if (unclosed_zero(map, i, j))
                {
                    return (1);
                }
            }
            j++;
        }
        i++;
    }
    return (0);
}

// mini switch
int map_valid(t_map *map, t_cub3d *vars)
{
    char    **tmp;

    tmp = dup_2d(map->map);
    if (map_unclean(map->map, &vars))
        return (0);
    if (map_not_closed(tmp))
        return (0);
    free_2d(tmp);
    return (1);
}

// check if the map is fully enclosed and traversable
int check_map(t_map *map, int fd, t_cub3d *vars)
{
    char *line;

    map->map = malloc(sizeof(char *) * (2));
    map->map[0] = get_next_line(fd);
    map->map[1] = 0;
    while (map->map[0][0] == '\n')
    {
        free(map->map[0]);
        map->map[0] = get_next_line(fd);
    }
    line = get_next_line(fd);
    while (line)
    {
        append_map(&map->map, line);
        free(line);
        line = get_next_line(fd);
    }
    if (map_valid(map, vars) == 0)
        return (0);
    return (1);
}

// check if the map.cub is valid
int    map_check(char *argv, t_cub3d *vars)
{
    int fd;

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
