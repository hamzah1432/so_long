/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 03:19:58 by halmuhis          #+#    #+#             */
/*   Updated: 2025/08/05 19:51:40 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	data_initial(t_data *data)
{
	int	width;
	int	height;

	data->steps = 0;
	data->wall.img = NULL;
	data->coin.img = NULL;
	data->player.img = NULL;
	data->exit.img = NULL;
	data->steps = 0;
	data->exit_p.x = 0;
	data->exit_p.y = 0;
	data->start = 0;
	data->current_bg = 1;
	data->mlx = mlx_init();
	mlx_get_screen_size(data->mlx, &width, &height);
	if (!data->mlx)
		exit_main_error("MLX initialization failed", data);
	data->win = mlx_new_window(data->mlx, width, height, "So Long");
	if (!data->win)
		exit_main_error("Window creation failed", data);
}

void	images_initial(t_data *data)
{
	data->wall.img = mlx_xpm_file_to_image(data->mlx, "assets/world.xpm",
			&data->wall.width, &data->wall.height);
	data->coin.img = mlx_xpm_file_to_image(data->mlx, "assets/coin.xpm",
			&data->coin.width, &data->coin.height);
	data->player.img = mlx_xpm_file_to_image(data->mlx, "assets/player.xpm",
			&data->player.width, &data->player.height);
	data->exit.img = mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm",
			&data->exit.width, &data->exit.height);
	if (!data->wall.img || !data->player.img || !data->coin.img
		|| !data->exit.img)
		exit_main_error("Window creation failed", data);
}
