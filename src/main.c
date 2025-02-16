/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:23:51 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/17 00:09:23 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int close_window(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_map(data->map);
	exit(0);
	return (0);
}

void render_map(t_data *data)
{
	int i = 0, j;
	mlx_clear_window(data->mlx, data->win); // Clear the screen

	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall.img, j * 80, i * 80);
			else if (data->map[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->coin.img, j * 80, i * 80);
			}
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->exit.img, j * 80, i * 80);
			j++;
		}
		i++;
	}

	// Redraw the player at the new position
	mlx_put_image_to_window(data->mlx, data->win, data->player.img, data->position.x * 80, data->position.y * 80);
}

int key_hook(int keycode, t_data *data)
{
	if (keycode == 65307) // Escape key to exit
		close_window(data);

	int new_x = data->position.x;
	int new_y = data->position.y;

	// Move image based on key pressed
	if (keycode == 65361) // Left arrow
		new_x--;
	if (keycode == 65363) // Right arrow
		new_x++;
	if (keycode == 65362) // Up arrow
		new_y--;
	if (keycode == 65364) // Down arrow
		new_y++;

	// Check if the new position is a valid move (not a wall)
	if (data->map[new_y][new_x] != '1' && (data->map[new_y][new_x] != 'E'|| data->collect == 0))
	{
		printf("Steps: %d\n", ++data->steps);
		data->map[data->position.y][data->position.x] = '0'; // Clear old player position
		data->position.x = new_x;
		data->position.y = new_y;
		if(data->map[data->position.y][data->position.x] == 'C')
		{
			data->collect--;
		}
		if(data->map[data->position.y][data->position.x] == 'E' && data->collect == 0)
		{
			close_window(data);
		}
		data->map[data->position.y][data->position.x] = 'P'; // Set new position
	}

	// Redraw everything after movement
	render_map(data);

	return (0);
}

int main(void)
{
	t_data data;
	int width;
	int height;
	int i = 0;
	int j = 0;

	read_map("assets/map.txt", &data);
	width = data.cols * 80;
	height = data.rows * 80;
	// Initialize MinilibX
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);

	data.win = mlx_new_window(data.mlx, width, height, "Image Background");
	if (!data.win)
	{
		free(data.mlx);
		return (1);
	}
	// Load image (Make sure "assets/image.xpm" exists)
	data.wall.img = mlx_xpm_file_to_image(data.mlx, "assets/world.xpm", &data.wall.width, &data.wall.height);
	data.coin.img = mlx_xpm_file_to_image(data.mlx, "assets/coin.xpm", &data.coin.width, &data.coin.height);
	data.player.img = mlx_xpm_file_to_image(data.mlx, "assets/player.xpm", &data.player.width, &data.player.height);
	data.exit.img = mlx_xpm_file_to_image(data.mlx, "assets/exit.xpm", &data.exit.width, &data.exit.height);
	if (!data.wall.img || !data.player.img)
	{
		printf("Error: Failed to load image\n");
		mlx_destroy_window(data.mlx, data.win);
		free(data.mlx);
		return (1);
	}

	// Put image to window
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == '1')
				mlx_put_image_to_window(data.mlx, data.win, data.wall.img, j * 80, i * 80);
			else if (data.map[i][j] == 'P')
			{
				data.position.x = j;
				data.position.y = i;
				mlx_put_image_to_window(data.mlx, data.win, data.player.img, j * 80, i * 80);
			}
			else if (data.map[i][j] == 'C')
				mlx_put_image_to_window(data.mlx, data.win, data.coin.img, j * 80, i * 80);
			else if (data.map[i][j] == 'E')
				mlx_put_image_to_window(data.mlx, data.win, data.exit.img, j * 80, i * 80);
			j++;
		}
		i++;
	}

	// Register key hook to move image
	mlx_key_hook(data.win, key_hook, &data);

	// Hook closing event (click "X" button)
	mlx_hook(data.win, 17, 0, close_window, &data);

	// Run MinilibX loop
	mlx_loop(data.mlx);
}