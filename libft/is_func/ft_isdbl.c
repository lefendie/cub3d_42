/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdbl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:00:46 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 16:08:31 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdbl(char *str)
{
	int	dot_count;
	int	i;

	i = 1;
	dot_count = 0;
	if (!ft_isdigit(str[0]) && str[0] != '-' && str[0] != '.')
		return (0);
	if (str[0] == '.')
		dot_count++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		if (str[i] == '.')
			dot_count++;
		if (dot_count > 1)
			return (0);
		i++;
	}
	if (dot_count == 0)
		return (0);
	return (1);
}
