/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 12:51:47 by manjaro           #+#    #+#             */
/*   Updated: 2021/07/01 22:42:02 by manjaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcountc(char *str, char c)
{
	char	*sav_ptr;
	int		count;

	count = 0;
	sav_ptr = str;
	while (*sav_ptr)
	{
		if (*sav_ptr == c)
			count++;
		sav_ptr++;
	}
	return (count);
}
