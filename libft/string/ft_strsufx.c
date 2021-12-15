/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsufx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:53:48 by manjaro           #+#    #+#             */
/*   Updated: 2021/07/01 22:12:49 by manjaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsufx(char *sufx, char *str)
{
	char	*new_str;
	int		size;

	size = ft_strlen(sufx) + ft_strlen(str) + 1;
	new_str = malloc(sizeof(char) * size);
	if (!new_str)
		return (0);
	while (*str)
	{
		*new_str = *str;
		new_str++;
		str++;
	}
	while (*sufx)
	{
		*new_str = *sufx;
		new_str++;
		sufx++;
	}
	*new_str = '\0';
	return (new_str);
}
