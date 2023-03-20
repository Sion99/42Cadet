/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:22:01 by sishin            #+#    #+#             */
/*   Updated: 2023/03/20 17:08:11 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*temp;
	const char	*s;

	temp = dst;
	s = src;
	while (n--)
		*temp++ = *s++;
	return (dst);
}
