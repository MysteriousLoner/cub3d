#include "../cub3d.h"

// render the player as a 4x4 square pixel by changing colour of pixels on the minimap
void	render_player(t_cub3d *vars, int mmap_width, int mmap_height, t_player *player)
{
    int i;
    int j;

    printf("rendering player\n");
    i = player->y - 5;
    while (i < 600)
    {
        while (j < 600)
        {
            put_pixel(vars, mmap_height / j, mmap_width / i, rgb_to_int(225, 30, 0));
            j++;
        }
        j = player->x - 5;
        i++;
    }
}