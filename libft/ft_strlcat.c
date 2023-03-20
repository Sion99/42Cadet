/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:55:23 by sishin            #+#    #+#             */
/*   Updated: 2023/03/16 13:06:08 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t count;
	size_t count2;
	size_t destlen;

	count = 0;
	count2 = 0;
	destlen = ft_strlen(dest);
	while (dst[count])
		count++;
	while (src[count2] && (count < dstsize - 1))
	{
		dst[count] = src[count2];
		count++;
		count2++;
	}
	if (dstsize < destlen)
		return (dstsize + ft_strlen(src));
	dst[count] = 0;
	return (destlen + ft_strlen(src));
}
