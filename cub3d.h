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

//mapcheck
int	mapcheck(char **array, int array_width);


#endif