/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:34:39 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/03 01:39:48 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_file(int fd)
{
	char	*line;
	char	*tmp;
	char	*tmp1;

	tmp1 = ft_strdup("");
	while ((line = get_next_line(fd)) != NULL)
	{
		tmp = tmp1;
		tmp1 = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	return (tmp1);
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