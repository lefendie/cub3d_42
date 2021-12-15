/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:22:05 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 11:08:39 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	new_str_size;
	char	*new_str;
	int		str_len;
	int		i;

	if (!s1 || !s2)
		return (0);
	new_str_size = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(sizeof(char) * (new_str_size + 1));
	if (!new_str)
		return (0);
	i = -1;
	str_len = (int)ft_strlen(s1);
	while (++i < str_len)
		new_str[i] = s1[i];
	new_str += i;
	i = -1;
	str_len = (int)ft_strlen(s2);
	while (++i < str_len)
		new_str[i] = s2[i];
	new_str -= ft_strlen(s1);
	new_str[new_str_size] = '\0';
	return (new_str);
}
