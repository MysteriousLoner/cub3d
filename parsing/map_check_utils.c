/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:42:25 by yalee             #+#    #+#             */
/*   Updated: 2023/11/09 18:36:37 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
// free 2d array
void	free_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// duplicate a 2d array
char	**dup_2d(char **arr)
{
	int		i;
	char	**dup;

	i = 0;
	while (arr[i])
		i++;
	dup = malloc(sizeof(char *) * (i + 1));
	dup[i] = 0;
	i = 0;
	while (arr[i])
	{
		dup[i] = ft_strdup(arr[i]);
		i++;
	}
	return (dup);
}
