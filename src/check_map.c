/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:18:43 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/25 02:04:43 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_map_walls(char **map, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			exit_check_error(map, "The map must be surrounded by walls");
		i++;
	}
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1' || map[rows - 1][j] != '1')
			exit_check_error(map, "The map must be surrounded by walls");
		j++;
	}
}

static int	check_elements(char c, int *map_exit, int *map_player, int *collect)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
		return (0);
	if (c == 'E')
		(*map_exit)++;
	if (c == 'P')
		(*map_player)++;
	if (c == 'C')
		(*collect)++;
	return (1);
}

static void	check_map_rectangular(char **map)
{
	size_t	i;
	size_t	first_len;

	first_len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != first_len)
			exit_check_error(map, "The map must be rectangular\n");
		i++;
	}
}

static void	check_map_elements(char **map, int *collect)
{
	int	i;
	int	j;
	int	map_exit;
	int	map_player;

	i = -1;
	map_exit = 0;
	map_player = 0;
	*collect = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (!check_elements(map[i][j], &map_exit, &map_player, collect))
				exit_check_error(map, "The map can be  1, 0, P, E, C \n");
	}
	if (map_player != 1 || map_exit != 1 || *collect < 1)
		exit_check_error(map, "The map must have one P, one E one C\n");
}

void	check_map(char **map, int *collect)
{
	int	rows;
	int	cols;

	rows = 0;
	while (map[rows])
		rows++;
	cols = ft_strlen(map[0]);
	check_map_rectangular(map);
	check_map_walls(map, rows, cols);
	check_map_elements(map, &*collect);
	check_valid_path(map, rows, cols);
}
