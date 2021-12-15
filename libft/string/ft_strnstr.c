/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:39:05 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/07 11:32:35 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;

	if (!*little)
		return ((char *)big);
	while (len && *little && *big)
	{
		i = 0;
		big += i;
		while (*(big + i) == *(little + i)
			&& *(big + i) && *(little + i) && len - i)
			i++;
		if (*(little + i))
			big++;
		else
			return ((char *)big);
		len--;
	}
	return (0);
}
