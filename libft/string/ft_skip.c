/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:45:49 by lefendie          #+#    #+#             */
/*   Updated: 2021/10/12 14:31:37 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_skip_str(char *str, char *list_skip, int *i)
{
	int	among_list;
	int	j;

	while (str[*i])
	{
		among_list = 0;
		j = 0;
		while (list_skip[j] && !among_list)
		{
			if (str[*i] == list_skip[j])
				among_list = 1;
			else
				among_list = 0;
			j++;
		}
		if (among_list)
			(*i)++;
		else
			break ;
	}
}
