/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendie@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:43:59 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/07 00:29:37 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nblen(int nb)
{
	int				powerten;
	unsigned int	pos_nb;

	powerten = 0;
	pos_nb = nb;
	if (nb <= 0)
	{
		pos_nb = -nb;
		powerten++;
	}
	while (pos_nb > 0)
	{
		pos_nb /= 10;
		powerten++;
	}
	return (powerten);
}

char	*ft_itoa(int n)
{
	char			*str_n;
	int				nb_len;
	unsigned int	pos_n;

	nb_len = ft_nblen(n);
	str_n = malloc(sizeof(*str_n) * (nb_len + 1));
	if (!str_n)
		return (0);
	pos_n = n;
	if (n < 0)
	{
		pos_n = -n;
		*str_n = '-';
	}
	str_n[nb_len] = '\0';
	if (pos_n == 0)
		*str_n = '0';
	while (nb_len-- && pos_n > 0)
	{
		str_n[nb_len] = pos_n % 10 + '0';
		pos_n = pos_n / 10;
	}	
	return (str_n);
}
