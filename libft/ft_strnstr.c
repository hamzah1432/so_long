/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:50:12 by halmuhis          #+#    #+#             */
/*   Updated: 2024/09/10 16:50:34 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_indexor;
	size_t	big_indexor;
	size_t	big_buffer_indexor;

	if (!*little)
		return ((char *)big);
	big_indexor = 0;
	big_buffer_indexor = 0;
	little_indexor = 0;
	while (big[big_indexor] && big_indexor < len)
	{
		little_indexor = 0;
		while (little[little_indexor] && big_indexor < len)
		{
			if (little[little_indexor] != big[big_indexor])
				break ;
			little_indexor++;
			big_indexor++;
			if (!little[little_indexor])
				return ((char *)&big[big_buffer_indexor]);
		}
		big_indexor = ++big_buffer_indexor;
	}
	return (NULL);
}
