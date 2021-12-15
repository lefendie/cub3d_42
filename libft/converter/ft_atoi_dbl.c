/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_dbl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 18:01:50 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/07 00:20:12 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atoi_dbl(const char *str)
{
	double	string_to_dbl;
	double	decimal_nb;
	int		sign;

	decimal_nb = 0;
	sign = 1;
	while (*str && (*str == 32 || (*str > 8 && *str < 14)))
		str++;
	if (*str == '-')
		sign = -sign;
	string_to_dbl = ft_atoi(str);
	while (*str)
		str++;
	str--;
	while ((*str >= '0' && *str <= '9') && *str != '.')
	{
		decimal_nb = decimal_nb / 10 + (*str - 48);
		str--;
	}
	decimal_nb /= 10;
	return (string_to_dbl + decimal_nb * sign);
}
