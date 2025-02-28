/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:34:39 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/28 18:06:55 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	char	*read_file(char *path)
{
	char	*line;
	char	*tmp;
	char	*tmp1;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	tmp1 = ft_strdup("");
	if (!tmp1)
		exit_read_error(NULL, "Memory allocation failed");
	line = get_next_line(fd);
	if (!line)
		exit_read_error(tmp1, "Memory allocation failed");
	while (line != NULL)
	{
		tmp = tmp1;
		tmp1 = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (tmp1);
}

static int	check_newlines(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static	void	add_map(char *file_content, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->map = ft_split(file_content, '\n');
	if (data->map == NULL)
		exit_read_error(file_content, "Memory allocation failed add_map");
	while (data->map[i])
		i++;
	data->rows = i;
	while (data->map[0][j])
		j++;
	data->cols = j;
}

int	read_map(char *path, t_data *data)
{
	char	*file_content;
	char	*extension;

	extension = path + ft_strlen(path) - 4;
	if (ft_strncmp(extension, ".ber", 4) != 0)
		exit_read_error(NULL, "Invalid map file: must end with .ber");
	file_content = read_file(path);
	if (!file_content || *file_content == '\0')
		exit_read_error(file_content, "map is empty");
	if (check_newlines(file_content))
		exit_read_error(file_content, "Invalid map: contains empty lines");
	add_map(file_content, data);
	free(file_content);
	return (0);
}
