/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:33:34 by sishin            #+#    #+#             */
/*   Updated: 2023/03/16 12:51:00 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	char *temp;
	const char *s;

	if (dst <= src)
	{
		temp = dst;
		s = src;
		while (len--)
			*temp++ = *s++;
	}
	else
	{
		temp = dst;
		temp += len;
		s = src;
		s += len;
		while (len--)
			*--temp = *--s;
	}
	return (dst);
}