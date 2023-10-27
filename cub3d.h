#ifndef CUB3D
#define CUB3D

# include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "mlx_linux/mlx.h"

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
	float	*view;
	char	start_face;
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

//mapcheck
t_map	*map_check(char *argv, t_cub3d *vars);
void    print_map(char **map);

// rendering
int		for_real_engine(t_cub3d *vars);
int		rgb_to_int(int r, int g, int b);
// minimap
void	render_minimap(int width, int height, t_cub3d *vars, t_player *player);
#endif