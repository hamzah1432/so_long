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

int     key_hook_start(int keycode, t_data *data)
{
    char    *bg_path;
    void    *bg_img;
    if (keycode == KEY_UP)  // UP arrow
        data->current_bg--;
    else if (keycode == KEY_DOWN)  // DOWN arrow
        data->current_bg++;
    else if (keycode == KEY_ESC)  // ESC key
        close_window(data);
	else
		return (0);  // Ignore other keys

    // Keep bg index between 0-3 (4 backgrounds)
    if (data->current_bg < 1)
        data->current_bg = 3;
    if (data->current_bg > 3)
        data->current_bg = 1;
    // Choose background file
    if (data->current_bg == 1)
        bg_path = "assets/background1.xpm";
    else if (data->current_bg == 2)
        bg_path = "assets/background2.xpm";
    else if (data->current_bg == 3)
        bg_path = "assets/background3.xpm";

    // Load and display new background
    bg_img = mlx_xpm_file_to_image(data->mlx, bg_path, 
                &data->wall.width, &data->wall.height);
    mlx_put_image_to_window(data->mlx, data->win, bg_img, 0, 0);
    
    return (0);
}


void    start_menu(t_data *data)
{
    void    *background_img;
    
    background_img = mlx_xpm_file_to_image(data->mlx, "assets/background1.xpm",
            &data->wall.width, &data->wall.height);
    mlx_put_image_to_window(data->mlx, data->win, background_img, 0, 0);
	mlx_key_hook(data->win, key_hook_start, data);
}