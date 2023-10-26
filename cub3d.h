#ifndef CUB3D
#define CUB3D

# include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "mlx_linux/mlx.h"

#define G_PI 3.14159265358979323846

char	*get_next_line(int fd);

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}			t_rgb;

typedef struct s_map
{
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	char	*F;
	char	*C;
	char	**map;
	t_rgb	*floor;
	t_rgb	*ceiling;
}			t_map;

typedef struct s_player
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	angle;
	float	*view;
}			t_player;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_map		*map;
	t_player	*player;
}			t_cub3d;

// debug
void    print_map(char **map);
void	print_player(t_player *player);
//mapcheck
t_map	*map_check(char *argv, t_cub3d *vars);
// movement
void	move_player(t_player *player, char key);
// rendering
int		for_real_engine(t_cub3d *vars);
// minimap
void	render_minimap(int width, int height, t_cub3d *vars, t_player *player);
#endif