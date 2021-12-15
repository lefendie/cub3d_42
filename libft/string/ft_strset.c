/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:10:22 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/24 18:29:01 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strset(char *s, int c, size_t n)
{
	char	*new_s;

	new_s = s;
	if (n)
		new_s[n--] = '\0';
	while (n)
		new_s[n--] = c;
	new_s[n] = c;
	return (new_s);
}
