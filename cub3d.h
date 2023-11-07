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

typedef	struct s_raycasting_vars
{
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	float 	aTan;
	int		*map;
}		t_raycasting_vars;

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
	int			size;
	t_map		*map;
	t_image		*north;
	t_player	*player;
}			t_cub3d;

// typedef struct s_render
// {
// 	unsigned int	**color;
// }

// debug
void    print_map(char **map);
void	print_player(t_player *player);
void    print_intmap(int *map);
//mapcheck
t_map	*map_check(char *argv, t_cub3d *vars);
// movement
void	move_player(t_player *player, char **map, char key);
// rendering
void	put_pixel(t_cub3d *vars, int x, int y, int color);
void 	draw_line_to_point(t_cub3d *vars, float x, float y, t_player *player);
void	init_graphics(t_cub3d *vars);
void	for_real_engine(t_cub3d *vars);
int		rgb_to_int(int r, int g, int b);
void	render_player(t_cub3d *vars, int size, t_player *player);
void	render_wall(char dir, int height, t_cub3d *vars, float sp);
void	init_screen(t_cub3d *vars);
// minimap
void	init_minimap(int width, int height, t_cub3d *vars);
// raycasting
// void	draw_rays(t_cub3d *vars, t_player *player);
// msic
int	longest_row(char **map);
int	map_height(char **map);
int	*map_to_intmap(char	**map, int height, int width);
#endif