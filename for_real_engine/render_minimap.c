#include "../cub3d.h"

// render the minimap based on the arguements given
// mlx pointer and window pointer are given in the t_cub3d struct, access by calling 
// vars->mlx and vars->win
// width and height are the dimensions of the minimap
// get player coordinates from t_player struct, access by calling vars->player->x and vars->player->y
void	render_minimap(int width, int height, t_cub3d *vars, t_player *player)
{
	printf("\nrendering minimap\n");
	printf("width: %d\n", width);
	printf("height: %d\n", height);
	printf("player x: %f\n", player->x);
	printf("player y: %f\n", player->y);
	(void)width;
	(void)height;
	(void)vars;
	(void)player;
}