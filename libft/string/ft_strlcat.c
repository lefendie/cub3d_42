/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:19:44 by lefendie          #+#    #+#             */
/*   Updated: 2020/11/30 08:58:37 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			dest_len;
	size_t			src_len;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	if (size < dest_len)
		return (src_len + size);
	i = dest_len;
	while (*src && i < (unsigned int)size - 1 && size > 0)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (dest_len + src_len);
}
