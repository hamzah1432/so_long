/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:36:36 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/02/23 15:21:59 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#define WIDTH 500
#define HEIGHT 500

typedef struct s_img
{
    char *img_path; // Path to player image
    void *img;      // Player's loaded image
    int width;      // Player image width
    int height;     // Player image height
} t_img;

typedef struct s_position
{
    int x; // Player's x position
    int y; // Player's y position
} t_position;

typedef struct s_flood
{
	int	collectibles;
	int	exit;
	int	rows;
	int	cols;
}	t_flood;

// Structure for game data
typedef struct s_data
{
    void *mlx;
    void *win;
    void *img;
    int rows;
    int cols;
    int collect;
    int steps;
    char **map;
    t_img wall;
    t_img coin;
    t_img player;
    t_img exit;
    t_position position; // Player struct
} t_data;

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

// read_map.c
void    free_map(char **map);
int     read_map(char *path, t_data *data);

void    check_map(t_data *data);

char    *get_next_line(int fd);

void	exit_read_error(char *str, char *msg);
void	exit_check_error(char *msg);


#endif
