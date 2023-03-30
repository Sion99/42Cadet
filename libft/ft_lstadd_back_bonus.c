/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:22:26 by sishin            #+#    #+#             */
/*   Updated: 2023/03/30 14:43:25 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		new -> next = NULL;
		*lst = new;
	}
	else
	{
		cur = *lst;
		while (cur)
		{
			if (cur -> next == NULL)
				break ;
			cur = cur -> next;
		}
		cur -> next = new;
		new -> next = NULL;
	}
}