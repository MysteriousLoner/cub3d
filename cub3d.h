#ifndef CUB3D
#define CUB3D

# include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "mlx_linux/mlx.h"

// Macro for Linux
#ifdef __linux__
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_W 119
#define KEY_ESC 65307
#define BUTTON_X 33
#endif

// Macro for Mac
#ifdef __APPLE__
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_W 13
#define KEY_ESC 53
#define BUTTON_X 17
#endif

// Universal Macro
#define PI 3.14159265358979323846
#define WIDTH 1200
#define HEIGHT 800

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
	float	c_pos;
}			t_player;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	t_image		*screen;
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
void	move_player(t_player *player, char **map, char key);
// rendering
void	put_pixel(t_cub3d *vars, int x, int y, int color);
void	init_graphics(t_cub3d *vars);
void	for_real_engine(t_cub3d *vars);
int		rgb_to_int(int r, int g, int b);
void	render_player(t_cub3d *vars, int mmap_width, int mmap_height, t_player *player);
// minimap
void	init_minimap(int width, int height, t_cub3d *vars);
#endif