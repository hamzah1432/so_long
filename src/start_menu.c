/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:14:17 by halmuhis          #+#    #+#             */
/*   Updated: 2025/08/05 19:59:14 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	start_menu(t_data *data)
{
	mlx_string_put(data->mlx, data->win, WIDTH - 50, HEIGHT/2, 0xFFFFFF,
		"Welcome to My Game!");
	mlx_string_put(data->mlx, data->win, WIDTH - 50, HEIGHT/2 + 50, 0xFFFFFF,
		"Press ENTER to Start");
	mlx_string_put(data->mlx, data->win, WIDTH - 50, HEIGHT/2 + 100, 0xFFFFFF,
		"Press ESC to Quit");
}
