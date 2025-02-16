/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:18:43 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/17 00:09:34 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(char *message)
{
	printf("%s\n", message);
	exit(0);
}

void	check_map_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i][0] != '1' || data->map[i][data->cols - 1] != '1')
			ft_error("The map must be surrounded by walls");
		i++;
	}
	j = 0;
	while (data->map[0][j])
	{
		if (data->map[0][j] != '1' || data->map[data->rows - 1][j] != '1')
			ft_error("The map must be surrounded by walls");
		j++;
	}
}

void	check_elements(char c, int *map_exit, int *map_player)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
		ft_error("The map can be composed of only these 5 characters\n");
	if (c == 'E')
		(*map_exit)++;
	if (c == 'P')
		(*map_player)++;
}

void	check_map_elements(t_data *data)
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
			if (data->cols < j)
				ft_error("The map must be rectangular\n");
			if (data->map[i][j] == 'C')
				data->collect++;
		}
	}
	if (map_player != 1 || map_exit != 1 || data->collect < 1)
		ft_error("The map must have one player, one exit one collectible\n");
}

void	check_map(t_data *data)
{
	data->collect = 0;
	check_map_walls(data);
	check_map_elements(data);
}
