/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:32:28 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/24 02:10:25 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

void	exit_read_error(char *str, char *msg)
{
	if (str != NULL)
		free(str);
	ft_putendl_fd("Error with read.c", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}
void	exit_check_error(char **map, char *msg)
{
	free_map(map);
	ft_putendl_fd("Error with check.c", 2);
	ft_putendl_fd(msg, 2);
	exit(0);
}
