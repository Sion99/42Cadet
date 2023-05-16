/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:37:12 by sishin            #+#    #+#             */
/*   Updated: 2023/03/27 16:12:47 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*t1;
	unsigned char	*t2;

	count = 0;
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (count < n)
	{
		if (*(t1 + count) != *(t2 + count))
			break ;
		if (count == n - 1)
			break ;
		count++;
	}
	return (*(t1 + count) - *(t2 + count));
}
