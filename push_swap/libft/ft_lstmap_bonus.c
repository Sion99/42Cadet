/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:37:06 by sishin            #+#    #+#             */
/*   Updated: 2023/03/30 21:42:44 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*head;
	void	*temp;

	if (!lst)
		return (NULL);
	temp = f(lst -> content);
	head = ft_lstnew(temp);
	if (!head)
		del(temp);
	lst = lst -> next;
	while (lst && head)
	{
		temp = f(lst -> content);
		newnode = ft_lstnew(temp);
		if (!newnode)
		{
			del(temp);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, newnode);
		lst = lst -> next;
	}
	return (head);
}
