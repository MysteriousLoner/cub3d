/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:23:23 by yalee             #+#    #+#             */
/*   Updated: 2023/11/09 21:24:03 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "mlx_linux/mlx.h"

// Macro for Linux
# ifdef __linux__
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_W 119
#  define KEY_ESC 65307
#  define BUTTON_X 33
# endif

// Macro for Mac
# ifdef __APPLE__
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_W 13
#  define KEY_SPACE 49
#  define KEY_ESC 53
#  define BUTTON_X 17
# endif

// Universal Macro
# define PI 3.141592
# define P2 1.570796
# define P3 4.712388
# define DG 0.017452
# define WIDTH 1200
# define HEIGHT 800

char	*get_next_line(int fd);

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
	char	d;
	t_image	*dimg;
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
	t_image		*north;
	t_image		*south;
	t_image		*east;
	t_image		*west;
}			t_cub3d;

// parsing
void    free_2d(char **arr);
char    **dup_2d(char **arr);
int 	is_cardinal(char c);
void    add_nswe(char **dir, char *line);
void    add_rgb(t_map *map, char c, char *line);
void    assign_pvars(int i, int j, char c, t_player *player);
int 	unclosed_zero(char **map, int i, int j);
int 	map_not_closed(char **map);
int		map_valid(t_map *map, t_cub3d *vars);
int 	check_map(t_map *map, int fd, t_cub3d *vars);
int    	map_check(char *argv, t_cub3d *vars);
int check_graphic(int fd, t_map *map);
int	check_colour(int fd, t_map *map);
void    append_map(char ***map, char *new_map);
int cheese(int pcount);
int map_unclean(char **map, t_cub3d **vars);
int	unclosed_zero2(char **map, int i, int j, int mi);

// graphics
int		rgb_to_int(int r, int g, int b);
void	put_pixel(t_cub3d *vars, int x, int y, int color);
float	dist(float ax, float ay, float bx, float by);
float	norm_angle(float angle);
void 	draw_line_to_point(t_cub3d *vars, float x, float y, t_player *player);
void	init_screen(t_cub3d *vars);
void	init_mc(t_cub3d *vars);
void	init_graphics(t_cub3d *vars);
void	for_real_engine(t_cub3d *vars);
void	init_horizontal(t_raycasting_vars *ray_vars, t_cub3d *vars, t_player *player);
void	check_horizontal(t_raycasting_vars *ray_vars, t_cub3d *vars, t_player *player);
void	init_vertical(t_raycasting_vars *ray_vars, t_cub3d *vars, t_player *player);
void	check_vertical(t_raycasting_vars *ray_vars, t_cub3d *vars, t_player *player);
void	init_rays(t_cub3d *vars, t_player *player, t_raycasting_vars *ray_vars);
void	calculate_and_render_wall(t_cub3d *vars, t_player *player, t_raycasting_vars *ray_vars);
void	render_walls(t_cub3d *vars, t_player *player);
void	render_sky(t_cub3d *vars);
void	render_earth(t_cub3d *vars);
int		get_map_size(char **map, int width, int height);
void	minimap_put_wall(int size, t_cub3d *vars, int pos_x, int pos_y);
void	minimap_put_floor(int size, t_cub3d *vars, int pos_x, int pos_y);
void	render_minimap(int width, int height, t_cub3d *vars);
void	draw_line(t_cub3d *vars, int size, t_player *player, float angle);
void	render_player(t_cub3d *vars, int size, t_player *player);
int		compute_colour(t_cub3d *vars, int y, float dist, t_raycasting_vars *ray_vars);
void	drawWalls(t_cub3d *vars, int r, float dist, t_raycasting_vars *ray_vars);
void	texture_init(t_cub3d *vars);

// others
void    print_map(char **map);
void	print_player(t_player *player);
void    print_intmap(int *map, int width, int height);
int 	close_window(t_cub3d *game_vars);
char 	*roll(void);
void    player_action(t_cub3d *vars, int keycode);
int     key_handler(int keycode, void *game_vars);
int    key_release_handler(int keycode, void *game_vars);
void    init_game_vars(t_cub3d *game_vars, char *argv );
void    free_game_vars(t_cub3d *game_vars);
int	can_move(t_player *player, char **map, char sign);
void	move_player(t_player *player, char **map, char key);
int	longest_row(char **map);
int	map_height(char **map);
int	longest_d(char **map);
#endif