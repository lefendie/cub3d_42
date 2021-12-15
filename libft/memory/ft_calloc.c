/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:50:43 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/07 11:21:38 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*var;
	int		i;

	var = malloc(count * size);
	if (!var)
		return (0);
	i = 0;
	while (i < (int)(count * size))
		((unsigned char *)var)[i++] = 0;
	return (var);
}
