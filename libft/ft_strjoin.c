/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:41:59 by sishin            #+#    #+#             */
/*   Updated: 2023/03/29 14:44:47 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				count;
	unsigned int	count_2;

	count = 0;
	count_2 = 0;
	while (dest[count])
		count++;
	while (src[count_2] && count_2 < nb)
		dest[count++] = src[count_2++];
	dest[count] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!joined)
		return (NULL);
	joined[0] = 0;
	ft_strncat(joined, (char *)s1, len1);
	ft_strncat(&joined[len1], (char *)s2, len2);
	return (joined);
}
