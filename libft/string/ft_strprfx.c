/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprfx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:53:27 by manjaro           #+#    #+#             */
/*   Updated: 2021/07/01 22:23:11 by manjaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strprfx(char *prfx, char *str)
{
	char	*new_str;
	int		size;

	size = ft_strlen(prfx) + ft_strlen(str) + 1;
	new_str = malloc(sizeof(char) * size);
	if (!(new_str))
		return (0);
	while (*prfx)
	{
		*new_str = *prfx;
		new_str++;
		prfx++;
	}
	while (*str)
	{
		*new_str = *str;
		new_str++;
		str++;
	}
	*new_str = '\0';
	return (new_str);
}
