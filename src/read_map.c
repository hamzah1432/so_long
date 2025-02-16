/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:34:39 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/17 00:09:30 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*read_file(char *path)
{
	char	*line;
	char	*tmp;
	char	*tmp1;
	int		fd;

	tmp1 = ft_strdup("");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
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

void	add_map(char *file_content, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->map = ft_split(file_content, '\n');
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

	file_content = read_file(path);
	if (!file_content || *file_content == '\0')
	{
		free(file_content);
		exit(0);
	}
	add_map(file_content, data);
	check_map(data);
	free(file_content);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
