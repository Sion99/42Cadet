/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:40:36 by sishin            #+#    #+#             */
/*   Updated: 2023/03/16 14:00:48 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return (haystack);
	while (haystack[i] && (i < len))
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while ((haystack[i] == needle[j]) && haystack[i] && (i < len))
			{
				i++;
				j++;
			}
			if (j == ft_strlen(needle))
				return (&haystack[i - j]);
			i = i - j + 1;
		}
		else
			i++;
	}
	return (0);
}
