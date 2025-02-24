/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:36:36 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/02/25 01:56:59 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define WIDTH 500
# define HEIGHT 500
# define GRID 80

typedef struct s_img
{
	char	*img_path;
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_flood
{
	int	collectibles;
	int	exit;
	int	rows;
	int	cols;
}	t_flood;

typedef struct s_map_count
{
	int	exit;
	int	player;
	int	collect;
}	t_map_count;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	int			rows;
	int			cols;
	int			collect;
	int			steps;
	char		**map;
	t_img		wall;
	t_img		coin;
	t_img		player;
	t_img		exit;
	t_position	position;
}	t_data;

/* Map functions */
void	free_map(char **map);
void	free_mlx(t_data *data);
void	free_images(t_data *data);
int		read_map(char *path, t_data *data);
void	check_map(char **map, int *collect);
void	check_valid_path(char **map, int rows, int cols);
void	data_initial(t_data *data);
void	images_initial(t_data *data);

/* Utils */
char	*get_next_line(int fd);
void	exit_read_error(char *str, char *msg);
void	exit_check_error(char **map, char *msg);
void	exit_main_error(char *msg, t_data *data);

#endif
