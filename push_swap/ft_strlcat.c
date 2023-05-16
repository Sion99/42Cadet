/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:55:23 by sishin            #+#    #+#             */
/*   Updated: 2023/03/29 22:25:40 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	count2;
	size_t	destlen;

	count = 0;
	count2 = 0;
	destlen = ft_strlen(dst);
	if (dstsize <= destlen)
		return (dstsize + ft_strlen(src));
	while (dst[count])
		count++;
	while (src[count2] && (count < dstsize - 1))
	{
		dst[count] = src[count2];
		count++;
		count2++;
	}
	dst[count] = 0;
	return (destlen + ft_strlen(src));
}
