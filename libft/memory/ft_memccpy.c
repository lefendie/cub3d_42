/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:24:04 by lefendie          #+#    #+#             */
/*   Updated: 2020/11/30 08:46:47 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*new_src;
	int				i;

	i = 0;
	new_src = (unsigned char *)src;
	while (i < (int)n)
	{
		*(unsigned char *)dest = *(unsigned char *)new_src;
		dest++;
		if (*(unsigned char *)new_src == (unsigned char)c)
			return (dest);
		new_src++;
		i++;
	}
	return (0);
}
