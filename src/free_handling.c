/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:42:21 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/26 16:41:15 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	free_images(t_data *data)
{
	if (data->wall.img)
		mlx_destroy_image(data->mlx, data->wall.img);
	if (data->coin.img)
		mlx_destroy_image(data->mlx, data->coin.img);
	if (data->player.img)
		mlx_destroy_image(data->mlx, data->player.img);
	if (data->exit.img)
		mlx_destroy_image(data->mlx, data->exit.img);
}

void	free_mlx(t_data *data)
{
	if (data->mlx)
	{
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

int	close_window(t_data *data)
{
	if (data)
	{
		free_images(data);
		free_map(data->map);
		free_mlx(data);
	}
	exit(0);
	return (0);
}
