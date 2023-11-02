#include "cub3d.h"

int	longest_row(char **map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = 0;
	while (map[i])
	{
		while (map[i][j])
			j++;
		if (j > max)
			max = j;
		j = 0;
		i++;
	}
	return (max);
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void printIntArray(int *array, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", array[i * cols + j]);
    }
    printf("\n");
  }
}

int *map_to_intmap(char **map, int rows, int cols) {
  // Allocate memory for the int * array.
  int *intArray = (int *)malloc(rows * cols * sizeof(int));

  // Iterate over the char ** map and convert each character to an int, replacing spaces and \n with 0.
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (map[i][j] == ' ' || map[i][j] == '\n') {
        intArray[i * cols + j] = 0;
      } else {
        intArray[i * cols + j] = map[i][j] - '0';
      }
    }
  }
	// printIntArray(intArray, rows, cols);
  return intArray;
}