/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striterc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:10:51 by manjaro           #+#    #+#             */
/*   Updated: 2021/07/01 22:44:27 by manjaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_striterc(char c, int n)
{
	char	*str;

	str = malloc(sizeof(char) * n + 1);
	if (!str)
		return (0);
	str[n] = '\0';
	while (n--)
		str[n] = c;
	return (str);
}
