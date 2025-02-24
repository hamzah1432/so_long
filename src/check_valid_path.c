/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 01:47:12 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/25 02:09:35 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**copy_map(char **map, int rows)
{
	char	**map_copy;
	int		i;

	map_copy = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			free_map(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	count_collectibles(char **map, int rows, int cols)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
			if (map[i][j] == 'C')
				count++;
	}
	return (count);
}

void	flood_fill(char **map, int row, int col, t_flood *flood)
{
	if (row < 0 || col < 0 || row >= flood->rows || col >= flood->cols)
		return ;
	if (map[row][col] == '1' || map[row][col] == 'F')
		return ;
	if (map[row][col] == 'C')
		flood->collectibles++;
	if (map[row][col] == 'E')
		flood->exit = 1;
	map[row][col] = 'F';
	flood_fill(map, row + 1, col, flood);
	flood_fill(map, row - 1, col, flood);
	flood_fill(map, row, col + 1, flood);
	flood_fill(map, row, col - 1, flood);
}

void	init_flood_check(t_flood *flood, int rows, int cols)
{
	flood->collectibles = 0;
	flood->exit = 0;
	flood->rows = rows;
	flood->cols = cols;
}

void	check_valid_path(char **map, int rows, int cols)
{
	t_flood	flood;
	char	**map_copy;
	int		i;
	int		j;
	int		total_collectibles;

	init_flood_check(&flood, rows, cols);
	total_collectibles = count_collectibles(map, rows, cols);
	map_copy = copy_map(map, rows);
	if (!map_copy)
		exit_check_error(map, "Error with check path");
	i = -1;
	while (map_copy[++i])
	{
		j = -1;
		while (map_copy[i][++j])
			if (map_copy[i][j] == 'P')
				flood_fill(map_copy, i, j, &flood);
	}
	if (flood.collectibles != total_collectibles || !flood.exit)
	{
		free_map(map_copy);
		exit_check_error(map, "No valid path exists");
	}
	free_map(map_copy);
}
