#ifndef CUB3D
#define CUB3D

# include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
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
#define KEY_SPACE 49
#define KEY_ESC 53
#define BUTTON_X 17
#endif

// Universal Macro
#define PI 3.141592
#define P2 1.570796
#define P3 4.712388
#define DG 0.017452
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
	float 	nTan;
	float 	hx;
	float 	hy;
	float 	distH;
	float 	distV;
	float 	vx;
	float 	vy;
	float 	ca;
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
	float	rc_angle;
	float	lov;
}			t_player;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
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
	t_player	*player;
	t_image		*mc;
	char		*bs;
	int			bsf;
	int			key_state[4];
	char		*mc_path;
	t_image		*n;
	t_image		*south;
	t_image		*east;
	t_image		*west;
}			t_cub3d;

// debug
void    print_map(char **map);
void	print_player(t_player *player);
void    print_intmap(int *map, int width, int height);
//mapcheck
int		map_check(char *argv, t_cub3d *vars);
void	texture_init(t_cub3d *vars);
// movement
void	move_player(t_player *player, char **map, char key);
// rendering
void	put_pixel(t_cub3d *vars, int x, int y, int color);
void	init_graphics(t_cub3d *vars);
void	for_real_engine(t_cub3d *vars);
int		rgb_to_int(int r, int g, int b);
void	render_player(t_cub3d *vars, int size, t_player *player);
void	draw_line_to_point(t_cub3d *vars, float x, float y, t_player *player);
void	draw_walls(t_cub3d *vars, int r, float dist);
// minimap
void	init_minimap(int width, int height, t_cub3d *vars);
// raycasting
void	draw_rays(t_cub3d *vars, t_player *player);
// msic
int	longest_row(char **map);
int	map_height(char **map);
int	longest_d(char **map);
void	put_texture(t_cub3d *vars);
#endif