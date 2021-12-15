/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:09:04 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/07 11:24:55 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*curr_lst;

	if (!lst)
		return (0);
	new_lst = ft_lstnew((*f)(lst->content));
	if (!new_lst)
		return (0);
	lst = lst->next;
	while (lst)
	{
		curr_lst = ft_lstnew((*f)(lst->content));
		if (!curr_lst)
		{
			ft_lstclear(&new_lst, (*del));
			return (0);
		}
		ft_lstadd_back(&new_lst, curr_lst);
		lst = lst->next;
	}
	return (new_lst);
}
