#ifndef CUB3D
#define CUB3D

# include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "mlx_linux/mlx.h"

char	*get_next_line(int fd);

typedef struct s_parse
{
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	char	*F;
	char	*C;
	char	**array;
}			t_parse;

typedef struct s_player
{
	float	x;
	float	y;
	float	*view;
}			t_player;

typedef struct s_cub3d
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	**map;
}			t_cub3d;

//mapcheck
int	mapcheck(char **array, int array_width);
int	for_real_engine(t_cub3d *vars);

#endif