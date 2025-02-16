/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:14:56 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/16 20:38:09 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_append(char **str, unsigned char ch)
{
	char			*temp;
	unsigned int	size;
	size_t			i;

	i = 0;
	if (!str || !*str)
		size = 0;
	else
		size = ft_strlen(*str);
	temp = malloc(size + 2);
	if (!temp)
		return ;
	while (i < size)
	{
		temp[i] = (*str)[i];
		i++;
	}
	temp[size] = ch;
	temp[size + 1] = '\0';
	free(*str);
	*str = temp;
}