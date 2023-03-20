/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:40:36 by sishin            #+#    #+#             */
/*   Updated: 2023/03/20 18:40:46 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*(haystack + i) && (i < len))
	{
		if (*(haystack + i) == *needle)
		{
			j = 0;
			while ((*(haystack + i) == *(needle + j)) && (i < len))
			{
				i++;
				j++;
			}
			if (j == ft_strlen(needle))
				return ((char *)(haystack + i - j));
			i = i - j + 1;
		}
		else
			i++;
	}
	return (0);
}
