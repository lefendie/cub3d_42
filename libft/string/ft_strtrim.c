/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:15:07 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/07 11:29:45 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_contains(char const *set, char const c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

size_t	ft_get_trim_size(char const *s1, char const *set)
{
	size_t	trim_size;
	size_t	end_index;

	end_index = ft_strlen(s1) - 1;
	trim_size = 0;
	while (s1[trim_size] && ft_str_contains(set, s1[trim_size]))
		trim_size++;
	while (s1[trim_size] && ft_str_contains(set, s1[end_index--]))
		trim_size++;
	return (trim_size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		i;
	size_t	new_str_size;

	if (!s1 || !set)
		return (0);
	new_str_size = ft_strlen(s1) - ft_get_trim_size(s1, set);
	new_str = malloc(sizeof(*new_str) * (new_str_size + 1));
	if (!new_str)
		return (0);
	while (ft_str_contains(set, *s1))
		s1++;
	i = 0;
	while (i < (int)new_str_size)
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
