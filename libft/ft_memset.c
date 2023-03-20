/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:05:56 by sishin            #+#    #+#             */
/*   Updated: 2023/03/16 14:47:02 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int c, size_t len)
{
	size_t i;
	unsigned char *temp;

	i = 0;
	temp = s;
	while (i < len)
	{
		*(temp + i) = c;
		i++;
	}
	return (s);
}