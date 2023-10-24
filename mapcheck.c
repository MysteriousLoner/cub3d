#include "cub3d.h"

#include "cub3d.h"

int	cf_check(char **array, int array_width)
{
	int	i;

	i = 0;
	while (array[0][i] == ' ')
		i++;
	while (array[0][i] != '\0')
	{
		if (array[0][i] == ' ' || array[0][i] == '1' 
		|| array[0][i] == '\n')
			i++;
		else
			return (1);
	}
	i = 0;
	while (array[array_width][i] == ' ')
		i++;
	while (array[array_width][i] != '\0')
	{
		if (array[array_width][i] == ' ' || array[array_width][i] == '1' 
		|| array[array_width][i] == '\n')
			i++;
		else
			return (1);
	}
	return (0);
}

int	wordcheck(char **array, int array_width)
{
	int	i;
	int	l;
	int	pos_no;

	i = 1;
	pos_no = 0;
	while (i < array_width)
	{
		l = 0;
		while (array[i][l] != '\0')
		{
			if (array[i][l] == '1' || array[i][l] == '0'
			|| array[i][l] == ' ' || array[i][l] == '\n')
				l++;
			else if (array[i][l] == 'N' || array[i][l] == 'S' ||
			array[i][l] == 'E' || array[i][l] == 'W')
			{
				l++;
				pos_no++;
			}
			else
				return (1);
		}
		i++;
	}
	if (pos_no != 1)
		return (1);
	return (0);
}

int	sidecheck(char **array, int array_width)
{
	int i;
	int	j;
	int	s;

	i = 1;
	while (i < array_width)
	{
		j = ft_strlen(array[i]) - 2;
		s = 0;
		while (array[i][s] == ' ')
			s++;
		if (array[i][s] == '1' && array[i][j] == '1')
			i++;
		else
			return (1);
	}
	return (0);
}

int	fillcheck(char **array, int array_width)
{
	int	i;
	int	j;

	i = 1;
	while (i < array_width)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			if (array[i][j] == '0' || array[i][j] == 'N'
			|| array[i][j] == 'S' || array[i][j] == 'E'
			|| array[i][j] == 'W')
			{
				if ((array[i - 1][j] == '0' || array[i - 1][j] == '1'
				|| array[i - 1][j] == 'N' || array[i - 1][j] == 'S'
				|| array[i - 1][j] == 'E' || array[i - 1][j] == 'W')
				&& (array[i + 1][j] == '0' || array[i + 1][j] == '1'
				|| array[i + 1][j] == 'N' || array[i + 1][j] == 'S'
				|| array[i + 1][j] == 'E' || array[i + 1][j] == 'W'))
					j++;
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	mapcheck(char **array, int array_width)
{
	if (cf_check(array, array_width) == 1)
		printf("Error\n");
	printf("in\n");
	if (wordcheck(array, array_width) == 1)
		printf("Error\n");
	if (sidecheck(array, array_width) == 1)
		printf("Error\n");
	if (fillcheck(array, array_width) == 1)
		printf("Error\n");
	return (0);
}
