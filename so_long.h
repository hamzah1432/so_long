/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:36:36 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/02/02 15:28:01 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 15
#endif

#define WIDTH 3000
#define HEIGHT 3000

typedef struct s_img
{
    char *img_path; // Path to player image
    void *img;      // Player's loaded image
    int width;      // Player image width
    int height;     // Player image height
} t_img;

typedef struct s_player
{
    int x; // Player's x position
    int y; // Player's y position
    t_img player_img;
} t_player;

typedef struct s_wall
{
    int x; // Player's x position
    int y; // Player's y position
    t_img Wall_img;
} t_wall;

// Structure for game data
typedef struct s_data
{
    void *mlx;
    void *win;
    void *background_img;
    int bg_width;
    int bg_height;
    int line_count;
    char *map[300];
    t_player player; // Player struct
} t_data;

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include "minilibx-linux/mlx.h"

char *get_next_line(int fd);
char **ft_split(char const *s, char c);
size_t ft_strlen(const char *s);
char *ft_strdup(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strchr(const char *s, int c);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char *ft_substr(char const *s, unsigned int start, size_t len);

#endif
