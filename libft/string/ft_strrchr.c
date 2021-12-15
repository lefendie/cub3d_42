/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:54:18 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/07 11:33:16 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	cursor;

	cursor = ft_strlen(s);
	while (cursor >= 0 && s[cursor] != c)
		cursor--;
	if (cursor >= 0)
	{
		while (cursor-- != 0)
			s++;
		return ((char *)s);
	}
	return (0);
}
