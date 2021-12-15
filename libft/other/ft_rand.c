/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:50:31 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/07 11:19:31 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_get_random_range(int min, int max, int list_range)
{
	int	*rand_list;
	int	fd;
	int	i;

	rand_list = malloc(sizeof(int) * list_range);
	if (!rand_list)
		return (FAILURE);
	fd = open("/dev/urandom", O_RDONLY);
	i = 0;
	while (i < list_range)
	{
		rand_list[i] = ft_get_random_nb(fd, min, max);
		i++;
	}
	return (rand_list);
}

int	ft_get_random_nb(int fd, int min, int max)
{
	char	buffer_random[RD_BUFFER_SIZE];
	int		random_nomber;
	int		i;

	i = 0;
	read(fd, buffer_random, RD_BUFFER_SIZE);
	random_nomber = (buffer_random[i] * max) / 127;
	while (random_nomber > max || random_nomber < min)
	{
		random_nomber = (buffer_random[i] * max) / 127;
		i++;
		if (i > RD_BUFFER_SIZE)
		{
			read(fd, buffer_random, RD_BUFFER_SIZE);
			i = 0;
		}
	}
	return (random_nomber);
}
