/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:50:15 by halmuhis          #+#    #+#             */
/*   Updated: 2024/09/10 16:52:09 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*start;

	start = (char *)s;
	str = start + ft_strlen(s);
	while (str != (start - 1))
	{
		if (*str == (char)c)
			return ((char *)str);
		str--;
	}
	return (NULL);
}
