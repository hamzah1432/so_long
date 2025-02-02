/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:23:51 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/02 17:08:26 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function to load images
void load_images(t_data *data, char *bg_path, char *player_path)
{
    // Load background image
    data->background_img = mlx_xpm_file_to_image(data->mlx, bg_path, &data->bg_width, &data->bg_height);
    if (!data->background_img)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(1); // Exit if background loading fails
    }

    // Load wall image
    // data->Wall_img.img = mlx_xpm_file_to_image(data->mlx, bg_path, &data->bg_width, &data->bg_height);
    // if (!data->Wall_img.img)
    // {
    //     mlx_destroy_window(data->mlx, data->win);
    //     exit(1); // Exit if background loading fails
    // }

    // Load player image
    data->player.player_img.img = mlx_xpm_file_to_image(data->mlx, player_path, &data->player.player_img.width, &data->player.player_img.height);
    if (!data->player.player_img.img)
    {
        mlx_destroy_image(data->mlx, data->background_img);
        mlx_destroy_window(data->mlx, data->win);
        exit(1); // Exit if player image loading fails
    }

    data->player.player_img.img_path = player_path;
}

// Function to render images
void render(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);

    // Draw background image
    mlx_put_image_to_window(data->mlx, data->win, data->background_img, 0, 0);

    // Draw player image at current position
    mlx_put_image_to_window(data->mlx, data->win, data->player.player_img.img, data->player.x, data->player.y);
}

// Handle player movement with keyboard input
int key_hook(int keycode, t_data *data)
{
    int grid;
    grid = 60;

    if (keycode == 65307) // ESC key to exit
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    else if (keycode == 65361) // Left arrow
        data->player.x -= grid;
    else if (keycode == 65363) // Right arrow
        data->player.x += grid;
    else if (keycode == 65362) // Up arrow
        data->player.y -= grid;
    else if (keycode == 65364) // Down arrow
        data->player.y += grid;

    // Render updated positions
    render(data);
    return (0);
}

// Function to close the window when clicking the "X" button
int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}

int main()
{
    t_data data;
    int fd;
    char *line;
    int i;

    i = 0;

    // Open the file in read-only mode
    fd = open("map.txt", O_RDONLY);
    data.map = (char **)malloc(sizeof(char *) * (1));

    while ((line = get_next_line(fd)) != NULL)
    {
        data.map[i] = line;
        i++;
    }

    while (i > 0)
    {
        printf("%s", data.map[--i]);
    }
    // close(fd);

    // Initialize MiniLibX
    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);

    // Create a window
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Player Struct Example");

    // Initialize player position
    data.player.x = WIDTH / 2;
    data.player.y = HEIGHT / 2;

    // Load images
    load_images(&data, "world.xpm", "player.xpm");

    // Render initial scene
    render(&data);

    // Handle keyboard input
    mlx_key_hook(data.win, key_hook, &data);

    // Handle window close event
    mlx_hook(data.win, 17, 0, close_window, &data);

    // Start the event loop
    mlx_loop(data.mlx);

    return (0);
}
