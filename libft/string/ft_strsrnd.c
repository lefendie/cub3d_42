/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsrnd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:05:58 by manjaro           #+#    #+#             */
/*   Updated: 2021/07/01 22:18:25 by manjaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_make_new_str(char *prfx, char *str, char *sufx, char *new_str)
{
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
	while (*sufx)
	{
		*new_str = *sufx;
		new_str++;
		sufx++;
	}
	*new_str = '\0';
}

char	*ft_strsrnd(char *prfx, char *str, char *sufx)
{
	char	*new_str;
	int		size;

	size = ft_strlen(prfx) + ft_strlen(str) + ft_strlen(prfx) + 1;
	new_str = malloc(sizeof(char) * size);
	if (!new_str)
		return (0);
	ft_make_new_str(prfx, str, sufx, new_str);
	return (new_str);
}
