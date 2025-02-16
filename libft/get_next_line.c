/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:35:50 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/02/17 00:03:30 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAX_LEFT_SIZE 4096

static char	*extract_line(char *buffer, size_t *pos)
{
	size_t	len;
	char	*line;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	line = ft_substr(buffer, 0, len);
	*pos = len;
	return (line);
}

static void	update_remainder(char (*rem)[MAX_LEFT_SIZE],
char *buffer, size_t pos)
{
	ft_strlcpy(*rem, buffer + pos, MAX_LEFT_SIZE);
}

static char	*read_line_chunk(int fd, char *buffer)
{
	ssize_t	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	buffer[bytes] = '\0';
	return (buffer);
}

static char	*build_line(int fd, char (*rem)[MAX_LEFT_SIZE])
{
	char	*buffer;
	char	*line;
	char	*temp;
	char	*chunk;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = ft_strdup(*rem);
	(*rem)[0] = '\0';
	while (!ft_strchr(line, '\n'))
	{
		chunk = read_line_chunk(fd, buffer);
		if (!chunk)
			break ;
		temp = line;
		line = ft_strjoin(temp, buffer);
		free(temp);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	rem[MAX_LEFT_SIZE];
	char		*line;
	char		*result;
	size_t		pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = build_line(fd, &rem);
	if (!line || *line == '\0')
	{
		free(line);
		return (NULL);
	}
	result = extract_line(line, &pos);
	update_remainder(&rem, line, pos);
	free(line);
	return (result);
}
