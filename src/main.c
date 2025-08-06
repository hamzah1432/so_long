/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:23:51 by halmuhis          #+#    #+#             */
/*   Updated: 2025/08/05 19:57:47 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	render_tile(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->wall.img, j * GRID, i * GRID);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->coin.img, j * GRID, i * GRID);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit.img, j * GRID, i * GRID);
	else if (data->map[i][j] == 'P')
	{
		data->position.x = j;
		data->position.y = i;
		mlx_put_image_to_window(data->mlx, data->win,
			data->player.img, j * GRID, i * GRID);
	}
	if (data->map[i][j] == 'E')
	{
		data->exit_p.x = j;
		data->exit_p.y = i;
	}
}

void	render_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(data->mlx, data->win);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			render_tile(data, i, j);
			j++;
		}
		i++;
	}
}

static int	process_movement(t_data *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] == '1')
		return (0);
	if (++data->steps)
	{
		ft_putnbr_fd(data->steps, 1);
		ft_putendl_fd(" Step", 1);
	}
	data->map[data->position.y][data->position.x] = '0';
	if (data->map[new_y][new_x] == 'C')
		data->collect--;
	if (data->map[new_y][new_x] == 'E' && data->collect == 0)
		close_window(data);
	if (data->position.x == data->exit_p.x
		&& data->position.y == data->exit_p.y)
		data->map[data->exit_p.y][data->exit_p.x] = 'E';
	data->position.x = new_x;
	data->position.y = new_y;
	data->map[new_y][new_x] = 'P';
	return (1);
}

int	key_hook(int keycode, t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->position.x;
	new_y = data->position.y;
	if (!data->start)
	{
		if (keycode == 65293)
		{
			render_map(data);
			data->start = 1;
		}
		if (keycode == 65307)
			close_window(data);
		return (0);
	}
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 65361 || keycode == 97)
		new_x--;
	else if (keycode == 65363 || keycode == 100)
		new_x++;
	else if (keycode == 65362 || keycode == 119)
		new_y--;
	else if (keycode == 65364 || keycode == 115)
		new_y++;
	if (data->position.x != new_x || data->position.y != new_y)
		if (process_movement(data, new_x, new_y))
			render_map(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		exit_main_error("write the argument", NULL);
	read_map(argv[1], &data);
	check_map(data.map, &data.collect);
	data_initial(&data);
	images_initial(&data);
	// render_map(&data);
	start_menu(&data);
	mlx_hook(data.win, 02, 1L >> 0, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
