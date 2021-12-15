/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:11:55 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/07 11:31:34 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_skip(const char *str, const char sep)
{
	while (*str == sep)
		str++;
	return (str);
}

int	ft_init_split(const char *str, const char sep, char ***result)
{
	int	list_size;

	list_size = 0;
	if (!str)
		return (0);
	while (*str)
	{
		while (*str && *str == sep)
			str++;
		if (*str && *str != sep)
		{
			list_size++;
			while (*str && *str != sep)
				str++;
		}
	}
	list_size++;
	*result = (char **)malloc(sizeof(*result) * (list_size));
	if (!(result))
	{
		free(*result);
		*result = NULL;
		return (0);
	}
	return (list_size);
}

int	ft_word_size(const char *str, const char sep)
{
	int	word_size;

	word_size = 0;
	while (str[word_size] && str[word_size] != sep)
		word_size++;
	return (word_size);
}

char	**ft_split(const char *s, const char c)
{
	char	**result;
	int		i;
	int		j;
	int		word_size;
	int		list_size;

	list_size = ft_init_split(s, c, &result);
	if (!list_size)
		return (result);
	i = 0;
	while (*s && list_size != 1 && *(ft_skip(s, c)))
	{
		s = ft_skip(s, c);
		word_size = ft_word_size(s, c);
		result[++i] = malloc(sizeof(**result) * (word_size + 1));
		if (!result[i])
			return (0);
		j = 0;
		while (*s && j < word_size)
			result[i][j++] = *s++;
		result[i][j] = '\0';
		i++;
	}
	result[i] = 0;
	return (result);
}
