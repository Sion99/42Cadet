/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:47:32 by sishin            #+#    #+#             */
/*   Updated: 2023/03/30 14:59:24 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*prev;

	cur = *lst;
	prev = *lst;
	if (!cur)
		return ;
	while (cur)
	{
		del(cur -> content);
		cur = cur -> next;
		free(prev);
		prev = cur;
	}
	free(cur);
}		
