/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:25:44 by sishin            #+#    #+#             */
/*   Updated: 2023/03/20 17:11:09 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = s;
	while (*(temp + i) && (i < n))
	{
		if (*(temp + i) == (unsigned char)c)
			return (temp + i);
		i++;
	}
	return (0);
}
