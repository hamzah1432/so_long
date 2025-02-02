/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:35:50 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/02/01 17:39:15 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define MAX_LEFT_SIZE 4096

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*set_line(char *line_buffer, char (*rem)[MAX_LEFT_SIZE])
{
	size_t	i;
	char	*result;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\n')
		i++;
	result = ft_substr(line_buffer, 0, i);
	ft_strlcpy(*rem, &line_buffer[i], MAX_LEFT_SIZE);
	free(line_buffer);
	return (result);
}

static char	*fill_line_buffer(int fd, char (*rem)[MAX_LEFT_SIZE],
		char *buffer)
{
	ssize_t	b_read;
	char	*line;
	char	*tmp;

	line = ft_strdup(*rem);
	(*rem)[0] = '\0';
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(line);
			return (NULL);
		}
		buffer[b_read] = '\0';
		tmp = line;
		line = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n') || b_read == 0)
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	rem[MAX_LEFT_SIZE];
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, &rem, buffer);
	free(buffer);
	if (!line || *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (set_line(line, &rem));
}

// #include <stdio.h>
// int main ()
// {
// 	char *line;
// 	int fd = open ("map.txt", O_RDONLY);

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 	// line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	}

// 	close(fd);
// 	return(0);
// }
