#include "cub3d.h"

// debugging function that prints map
void    print_map(char **map)
{
    int i;

    i = 0;
    printf("map: \n");
    while (map[i])
    {
        printf("%s", map[i]);
        i++;
    }
}

// debugging function that prints player info
void	print_player(t_player *player)
{
	printf("player pos: %f, %f\nplayer delta: dx: %f, dy: %f\nplayer angle: %f\n", player->x, player->y, player->dx, player->dy, player->angle);
}

void    print_intmap(int *map, int width, int height)
{
    int i;
    int j;

    i = 0;
    j = 0;
    printf("intmap: \n");
    while(i < (width * height))
    {
        printf("%i", map[i]);
        if (j == width)
        {
            printf("\n");
            j = 0;
            i++;
            continue;
        }
        j++;
        i++;
    }
}