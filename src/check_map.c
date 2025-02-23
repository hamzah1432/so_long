/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:18:43 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/23 15:24:06 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void	check_map_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i][0] != '1' || data->map[i][data->cols - 1] != '1')
			exit_check_error("The map must be surrounded by walls");
		i++;
	}
	j = 0;
	while (data->map[0][j])
	{
		if (data->map[0][j] != '1' || data->map[data->rows - 1][j] != '1')
			exit_check_error("The map must be surrounded by walls");
		j++;
	}
}

static	void	check_elements(char c, int *map_exit, int *map_player)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
		exit_check_error("The map can be  1, 0, P, E, C \n");
	if (c == 'E')
		(*map_exit)++;
	if (c == 'P')
		(*map_player)++;
}

static void check_map_rectangular(t_data *data)
{
    size_t i;
    size_t first_len;

    first_len = ft_strlen(data->map[0]);
    i = 1;
    while (data->map[i])
    {
        if (ft_strlen(data->map[i]) != first_len)
            exit_check_error("The map must be rectangular\n");
        i++;
    }
}

static	void	check_map_elements(t_data *data)
{
	int	i;
	int	j;
	int	map_exit;
	int	map_player;

	i = -1;
	map_exit = 0;
	map_player = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			check_elements(data->map[i][j], &map_exit, &map_player);
			if (data->map[i][j] == 'C')
				data->collect++;
		}
	}
	if (map_player != 1 || map_exit != 1 || data->collect < 1)
		exit_check_error("The map must have one P, one E one C\n");
}

static char	**copy_map(t_data *data)
{
	char	**map_copy;
	int		i;

	map_copy = (char **)malloc(sizeof(char *) * (data->rows + 1));
	if (!map_copy)
		exit_check_error("Memory allocation failed");
	i = 0;
	while (i < data->rows)
	{
		map_copy[i] = ft_strdup(data->map[i]);
		if (!map_copy[i])
		{
			while (i > 0)
				free(map_copy[--i]);
			free(map_copy);
			exit_check_error("Memory allocation failed");
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static void	flood_fill(char **map, int row, int col, t_flood *flood)
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

static void	check_valid_path(t_data *data)
{
	t_flood	flood;
	char	**map_copy;
	int		i;
	int		j;

	flood.collectibles = 0;
	flood.exit = 0;
	flood.rows = data->rows;
	flood.cols = data->cols;
	map_copy = copy_map(data);
	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'P')
				flood_fill(map_copy, i, j, &flood);
			j++;
		}
		i++;
	}
	if (flood.collectibles != data->collect || !flood.exit)
		exit_check_error("No valid path exists");
	i = 0;
	while (map_copy[i])
		free(map_copy[i++]);
	free(map_copy);
}

void	check_map(t_data *data)
{
	data->collect = 0;
	check_map_rectangular(data);
	check_map_walls(data);
	check_map_elements(data);
	check_valid_path(data);
}
