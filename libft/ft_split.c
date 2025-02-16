/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:49:40 by halmuhis          #+#    #+#             */
/*   Updated: 2024/09/10 16:50:34 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char delimiter)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != delimiter && (s[i + 1] == delimiter || !s[i + 1]))
			words++;
		i++;
	}
	return (words);
}

static int	ft_strlen_till_delimiter(char const *s, char delimiter)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != delimiter)
		i++;
	return (i);
}

static void	free_result(char **result, int wordcount)
{
	int	i;

	i = 0;
	while (i <= wordcount)
	{
		free(result[i]);
		result[i] = NULL;
		i++;
	}
	free(result);
	result = NULL;
}

static char	**set_strings(char **result, int wordcount, char const *s, char c)
{
	int	wordlen;
	int	word;

	word = 0;
	while (word < wordcount)
	{
		while (*s == c)
			s++;
		wordlen = ft_strlen_till_delimiter(s, c);
		result[word] = malloc(sizeof(char) * (wordlen + 1));
		if (!result[word])
		{
			free_result(result, word);
			return (NULL);
		}
		ft_strlcpy(result[word], s, wordlen + 1);
		s += wordlen;
		word++;
	}
	result[word] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		wordcount;
	char	**result;

	wordcount = ft_wordcount(s, c);
	result = malloc(sizeof(char *) * (wordcount + 1));
	if (!result)
		return (NULL);
	return (set_strings(result, wordcount, s, c));
}
