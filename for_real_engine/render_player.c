#include "../cub3d.h"

// render the player as a 4x4 square pixel by changing colour of pixels on the minimap
void	render_player(t_cub3d *vars, int mmap_width, int mmap_height, t_player *player)
{
    (void)vars;
    printf("rendering player, these are the variables you need.\n");
    printf("mmap_width: %i\nmmap_height: %i\n", mmap_width, mmap_height);
    printf("Use these to calculate the pixel position of the player on the minimap.\n");
    printf("player->x: %f\nplayer->y: %f\n", player->x, player->y);
    printf("Use these to calculate the mathmathical position of the player on the minimap.\n");
    printf("player->c_pos: %f\n", player->c_pos);
    printf("This is the size of the cube / 2, add it to your calculation to get where to put the pizel.\n");
    printf("center pixel for the player, x = width / player->posx + player->c_pos\n");
    printf("center pixel for the player, y = height / player->posy + player->c_pos\n");
    printf("I think glhf\n");
}