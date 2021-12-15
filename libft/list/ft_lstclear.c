/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendie@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:54:20 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/07 11:23:17 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_lst;

	next_lst = *lst;
	while (next_lst->next)
	{
		*lst = next_lst;
		next_lst = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
	}
	(*del)(next_lst->content);
	free(next_lst);
	*lst = 0;
}
