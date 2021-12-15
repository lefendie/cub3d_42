/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:34:40 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/07 11:21:54 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	i;
	void	*new_s;

	new_s = (void *)s;
	i = 0;
	while (i < (char)n)
	{
		if (*((char *)new_s) == c)
			return (new_s);
		new_s++;
		i++;
	}
	return (0);
}
