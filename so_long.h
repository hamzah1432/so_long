/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:36:36 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/02/03 08:08:24 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 15
#endif

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
#include "minilibx-linux/mlx.h"

// read_map.c
char *read_file(char *path);
void add_map(char *file_content, t_data *data);
void free_map(char **map);
int read_map(char *path, t_data *data);

void check_map(t_data *data);

// get_next_line.c
char *get_next_line(int fd);
char **ft_split(char const *s, char c);
size_t ft_strlen(const char *s);
char *ft_strdup(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strchr(const char *s, int c);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char *ft_substr(char const *s, unsigned int start, size_t len);

#endif
