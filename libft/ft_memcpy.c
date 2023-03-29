/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:22:01 by sishin            #+#    #+#             */
/*   Updated: 2023/03/29 22:36:35 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
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
*/
void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	char		*temp;
	const char	*s;
	size_t		i;

	if (dst == 0 && src == 0)
		return (0);
	temp = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		temp[i] = s[i];
		i++;
	}
	return (dst);
}
