/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 10:45:33 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/07 11:17:07 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	pos_nb;

	pos_nb = n;
	if (n < 0)
	{
		pos_nb = -n;
		ft_putchar_fd('-', fd);
	}
	if (pos_nb >= 10)
		ft_putnbr_fd(pos_nb / 10, fd);
	pos_nb %= 10;
	ft_putchar_fd(pos_nb + '0', fd);
}
