/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:23:51 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/03 04:55:53 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(void)
{
	t_data	data;

	read_map("assets/map.txt", &data);
	printf("rows: %d\n", data.rows);
	printf("cols: %d\n", data.cols);
	printf("collectible: %d\n",data.collect);
	free_map(data.map);
	return (0);
}
