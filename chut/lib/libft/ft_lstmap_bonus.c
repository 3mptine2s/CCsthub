/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:59:14 by chutterm          #+#    #+#             */
/*   Updated: 2025/09/20 19:08:41 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*func)(void *), void (*del)(void *))
{
	t_list	*temp_lst;
	t_list	*temp_obj;

	if (!lst || !func || !del)
		return (NULL);
	temp_lst = NULL;
	while (lst)
	{
		temp_obj = ft_lstnew(func(lst->content));
		if (!temp_obj)
		{
			ft_lstclear(&temp_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&temp_lst, temp_obj);
		lst = lst->next;
	}
	return (temp_lst);
}
